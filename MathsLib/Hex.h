#pragma once
#include <vector>
#include "FractionalHex.h"
#include "Utilities.h"
#include <cmath>
#include <cassert>

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

const Orientation layout_pointy
= Orientation(sqrt(3.0), sqrt(3.0) / 2.0, 0.0, 3.0 / 2.0,
	sqrt(3.0) / 3.0, -1.0 / 3.0, 0.0, 2.0 / 3.0,
	0.5);
const Orientation layout_flat
= Orientation(3.0 / 2.0, 0.0, sqrt(3.0) / 2.0, sqrt(3.0),
	2.0 / 3.0, 0.0, -1.0 / 3.0, sqrt(3.0) / 3.0,
	0.0);

//essentially a Vec2
struct Point {
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
	Hex(int q_in, int r_in, int s_in);
	Hex();
	Hex(int q_, int r_);
	::Hex& operator=(const Hex& hex);
	//copy
	Hex(const Hex& other);
	~Hex();

	//UNION
	union {
		//struct as qrs accessable with . operator
		struct {
			int  q, r, s;
		};
		//array accessable with [] operator
		int data[3];
	};
	//operators
	bool operator== (Hex other);
	bool operator!=(Hex other);

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
	const std::vector<Hex> hex_directions = {
		Hex(1, 0, -1), Hex(1, -1, 0), Hex(0, -1, 1),
		Hex(-1, 0, 1), Hex(-1, 1, 0), Hex(0, 1, -1)
	};

	Hex hex_direction(int direction /* 0 to 5 */) const;
	Hex hex_neighbor(Hex hex, int direction) const;

	//converters
	static Point hex_to_pixel(Layout layout, Hex h);

	static FractionalHex pixel_to_hex(Layout layout, Point p);

	//drawing
	Point hex_corner_offset(Layout layout, int corner) const;

	std::vector<Point> polygon_corners(Layout layout, Hex h) {
		std::vector<Point> corners = {};
		Point center = hex_to_pixel(layout, h);
		for (int i = 0; i < 6; i++) {
			Point offset = hex_corner_offset(layout, i);
			corners.push_back(Point(center.x + offset.x,
				center.y + offset.y));
		}
		return corners;
	}

};
