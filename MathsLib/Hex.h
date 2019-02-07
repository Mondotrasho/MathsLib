#pragma once
#include <vector>
#include "FractionalHex.h"
#include "Utilities.h"
#include <cmath>
#include <cassert>
#include <algorithm>

//a matrix
struct Orientation {
	const double f0, f1, f2, f3;
	const double b0, b1, b2, b3;
	const double start_angle; // in multiples of 60°
	Orientation(double f0_, double f1_, double f2_, double f3_,
		double b0_, double b1_, double b2_, double b3_,
		double start_angle_)
		: f0(f0_), f1(f1_), f2(f2_), f3(f3_),
		b0(b0_), b1(b1_), b2(b2_), b3(b3_),
		start_angle(start_angle_) {}


}; 


//essentially a Vec2
struct Point {
public:
	const double x, y;
	Point(double x_, double y_) : x(x_), y(y_) {}
};

struct Layout {
	const Orientation orientation;
	const Point size;
	const Point origin;
	Layout(Orientation orientation_, Point size_, Point origin_)
		: orientation(orientation_), size(size_), origin(origin_) {}
};



class Hex
{
public:
	//int constructors
	Hex(void) = default;
	~Hex(void) = default;
	Hex(int q_in, int r_in, int s_in) : q(q_in), r(r_in), s(s_in){};
	Hex(int q_, int r_) : q(q_), r(r_), s(-q_ - r_)	{assert(q + r + s == 0);	} //watch me

	Hex& operator=(const Hex& hex) {
		return{ *this };
	};
	//copy
	Hex(const Hex& other) {
		q = other.q;
		r = other.r;
		s = other.s;
		*this = other;
	};

	//UNION
	union {
		//struct as qrs accessable with . operator
		struct {
			int  q, r, s;
		};
		//array accessable with [] operator
		int data[3]{};
	};
	//operators
	bool operator==(const Hex& b) const;
	bool operator!=(Hex b);


	Hex operator+(const Hex& other) const;
	Hex operator+(int other) const;
	Hex& operator+=(const Hex& other);
	Hex operator-(const Hex& other) const;
	Hex operator-(int other) const;
	Hex& operator-=(const Hex& other);

	Hex operator*(int scalar) const;
	Hex& operator*=(int scalar);
	Hex operator/(int scalar) const;
	Hex& operator/=(int scalar);

	static Hex hex_add(Hex a, Hex b);
	static Hex hex_subtract(Hex a, Hex b);
	static Hex hex_multiply(Hex a, int k);

	//methods
	int hex_length(Hex hex) const;
	int hex_distance(Hex a, Hex b) const;

	//Neighbours
	

	Hex hex_direction(int direction /* 0 to 5 */) const;
	Hex hex_neighbor(Hex hex, int direction) const;

	//converters
	static Point hex_to_pixel(Layout layout, Hex h);

	static FractionalHex pixel_to_hex(Layout layout, Point p);

	//drawing
	Point hex_corner_offset(Layout layout, int corner) const;

	std::vector<Point> polygon_corners(Layout layout, Hex h) const;
	Hex hex_round(FractionalHex h);
	float lerp(double a, double b, double t);
	FractionalHex hex_lerp(Hex a, Hex b, double t);
	FractionalHex hex_lerp(FractionalHex a, FractionalHex b, double t);
	std::vector<Hex> hex_linedraw(Hex a, Hex b);
	std::vector<Hex> hex_linedrawnudge(Hex a, Hex b);
};
const Orientation layout_pointy
= Orientation(sqrt(3.0), sqrt(3.0) / 2.0, 0.0, 3.0 / 2.0,
	sqrt(3.0) / 3.0, -1.0 / 3.0, 0.0, 2.0 / 3.0,
	0.5);

const Orientation layout_flat
= Orientation(3.0 / 2.0, 0.0, sqrt(3.0) / 2.0, sqrt(3.0),
	2.0 / 3.0, 0.0, -1.0 / 3.0, sqrt(3.0) / 3.0,
	0.0);

namespace std {
	template <> struct hash<Hex> {
		size_t operator()(const Hex& h) const {
			hash<int> int_hash;
			size_t hq = int_hash(h.q);
			size_t hr = int_hash(h.r);
			return hq ^ (hr + 0x9e3779b9 + (hq << 6) + (hq >> 2));
		}
	};
}