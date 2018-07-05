#ifndef _MATRIX2_H_
#define _MATRIX2_H_
#include "Vector2.h"

class matrix2
{
public:
	matrix2();
	~matrix2();
	//copy
	matrix2(const matrix2& matrix);
	//defined
	matrix2(const vector2& new_x_ax, const vector2& new_y_ax, const vector2& new_z_ax);
	matrix2(float a, float b, float c, float d);
	static const matrix2 identity;

	union {
		struct {
			vector2 x_axis;
			vector2 y_axis;
		};
		vector2 axis[2];
		float data[2][2];
	};

	vector2& operator[](int index);
	const vector2& operator[](int index) const;
	matrix2 operator*(const matrix2& other) const;
	vector2 operator*(const vector2& v) const;
	matrix2& operator=(const matrix2& other);
	matrix2 transposed() const;
	void set_element(int r, int c, int e);
	int get_element(int r, int c);
	void set_column(int c, vector2& vec);
	vector2 get_column(int c);
	void set_row(int r, vector2& vec);
	vector2 get_row(int r);
	matrix2& operator+=(const matrix2& m);
	matrix2& operator-=(const matrix2& m);
	void set_scaled(float x, float y);
	void set_scaled(const vector2& v);
	void scale(float x, float y);
	void scale(const vector2& v);
	void set_rotate(float radians);
	void rotate(float radians);
};

#endif
