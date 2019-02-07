#include "Hex.h"

//test
const std::vector<Hex> hex_directions = {
	Hex(1, 0, -1), Hex(1, -1, 0), Hex(0, -1, 1),
	Hex(-1, 0, 1), Hex(-1, 1, 0), Hex(0, 1, -1)
};

//OPERATORS
bool Hex::operator == (const Hex& b) const
{
	return q == b.q && r == b.r && s == b.s;
}

bool Hex::operator != (Hex b) {
	return !(*this == b);
}

Hex Hex::operator+(const Hex& other) const
{
	return{ q + other.q, r + other.r, s + other.s };
}

Hex Hex::operator+(int other) const
{
	return{ q + other,r + other, s + other };
}

Hex& Hex::operator+=(const Hex& other)
{
	q += other.q; r += other.r; s += other.s;
	return *this;
}

Hex Hex::operator-(const Hex& other) const
{
	return{ q - other.q, r - other.r, s - other.s };
}

Hex Hex::operator-(int other) const
{
	return{ q - other,r - other, s - other };
}

Hex& Hex::operator-=(const Hex& other)
{
	q -= other.q; r -= other.r; s -= other.s;
	return *this;
}

Hex Hex::operator*(int scalar) const
{
	return{ q * scalar, r * scalar , s * scalar };
}

Hex& Hex::operator*=(int scalar)
{
	q *= scalar; r *= scalar; s *= scalar;
	return *this;
}

Hex Hex::operator/(int scalar) const
{
	return{ q * scalar, r * scalar , s * scalar };
}

Hex& Hex::operator/=(int scalar)
{
	q *= scalar; r *= scalar; s *= scalar;
	return *this;
}

Hex Hex::hex_add(Hex a, Hex b)
{
	return Hex(a.q + b.q, a.r + b.r, a.s + b.s);
}

Hex Hex::hex_subtract(Hex a, Hex b)
{
	return Hex(a.q - b.q, a.r - b.r, a.s - b.s);
}

Hex Hex::hex_multiply(Hex a, int k)
{
	return Hex(a.q * k, a.r * k, a.s * k);
}

int Hex::hex_length(Hex hex) const
{
	return int((abs(hex.q) + abs(hex.r) + abs(hex.s)) / 2);
}

int Hex::hex_distance(Hex a, Hex b) const
{
	return hex_length(hex_subtract(a, b));
}

Hex Hex::hex_direction(int direction) const
{
	assert(0 <= direction && direction < 6);
	return hex_directions[direction];
}

Hex Hex::hex_neighbor(Hex hex, int direction) const
{
	return hex_add(hex, hex_direction(direction));
}

Point Hex::hex_to_pixel(Layout layout, Hex h)
{
	const Orientation& M = layout.orientation;

	double x = (M.f0 * h.q + M.f1 * h.r) * layout.size.x;
	double y = (M.f2 * h.q + M.f3 * h.r) * layout.size.y;

	return Point(x + layout.origin.x, y + layout.origin.y);
}

FractionalHex Hex::pixel_to_hex(Layout layout, Point p)
{
	{
		const Orientation& M = layout.orientation;
		Point pt = Point((p.x - layout.origin.x) / layout.size.x,
		                 (p.y - layout.origin.y) / layout.size.y);
		double q = M.b0 * pt.x + M.b1 * pt.y;
		double r = M.b2 * pt.x + M.b3 * pt.y;
		return FractionalHex(q, r, -q - r);
	}
}

Point Hex::hex_corner_offset(Layout layout, int corner) const
{
	Point size = layout.size;
	double angle = 2.0 * M_PI *
		(layout.orientation.start_angle + corner) / 6;
	return Point(size.x * cos(angle), size.y * sin(angle));
}

std::vector<Point> Hex::polygon_corners(Layout layout, Hex h) const
{
	std::vector<Point> corners = {};
	Point center = hex_to_pixel(layout, h);

	for (int i = 0; i < 6; i++)
	{
		Point offset = hex_corner_offset(layout, i);
		corners.push_back(Point(center.x + offset.x,
		                        center.y + offset.y));
	}

	return corners;
}

Hex Hex::hex_round(FractionalHex h) {
	int q = int(round(h.q));
	int r = int(round(h.r));
	int s = int(round(h.s));
	double q_diff = abs(q - h.q);
	double r_diff = abs(r - h.r);
	double s_diff = abs(s - h.s);
	if (q_diff > r_diff && q_diff > s_diff) {
		q = -r - s;
	}
	else if (r_diff > s_diff) {
		r = -q - s;
	}
	else {
		s = -q - r;
	}
	return Hex(q, r, s);
}

float Hex::lerp(double a, double b, double t) {
	return a * (1 - t) + b * t;
	/* better for floating point precision than
	a + (b - a) * t, which is what I usually write */
}

FractionalHex Hex::hex_lerp(Hex a, Hex b, double t) {
	return FractionalHex(lerp(a.q, b.q, t),
		lerp(a.r, b.r, t),
		lerp(a.s, b.s, t));
}
FractionalHex Hex::hex_lerp(FractionalHex a, FractionalHex b, double t) {
	return FractionalHex(lerp(a.q, b.q, t),
		lerp(a.r, b.r, t),
		lerp(a.s, b.s, t));
}

std::vector<Hex> Hex::hex_linedraw(Hex a, Hex b) {
	int N = hex_distance(a, b);
	std::vector<Hex> results = {};
	double step = 1.0 / std::max(N, 1);
	for (int i = 0; i <= N; i++) {
		results.push_back(hex_round(hex_lerp(a, b, step * i)));
	}
	return results;
}

std::vector<Hex> Hex::hex_linedrawnudge(Hex a, Hex b) {
	int N = hex_distance(a, b);
	FractionalHex a_nudge(a.q + 1e-6, a.r + 1e-6, a.s - 2e-6);
	FractionalHex b_nudge(b.q + 1e-6, b.r + 1e-6, b.s - 2e-6);
	std::vector<Hex> results = {};
	double step = 1.0 / std::max(N, 1);
	for (int i = 0; i <= N; i++) {
		results.push_back(
			hex_round(hex_lerp(a_nudge, b_nudge, step * i)));
	}
	return results;
}

