#ifndef _Matrix2_H_
#define _Matrix2_H_
#include "Vector2.h"

class Matrix2
{
public:
	Matrix2();
	~Matrix2();
	//copy
	Matrix2(const Matrix2& matrix);
	//defined
	Matrix2(const Vector2& new_x_ax, const Vector2& new_y_ax, const Vector2& new_z_ax);
	Matrix2(float a, float b, float c, float d);
	static const Matrix2 identity;

	union {
		struct {
			Vector2 x_axis;
			Vector2 y_axis;
		};
		Vector2 axis[2];
		float data[2][2];
	};

	Vector2& operator[](int index);
	const Vector2& operator[](int index) const;
	Matrix2 operator*(const Matrix2& other) const;
	Vector2 operator*(const Vector2& v) const;
	Matrix2& operator=(const Matrix2& other);
	Matrix2 transposed() const;
	void set_element(int r, int c, int e);
	int get_element(int r, int c);
	void set_column(int c, Vector2& vec);
	Vector2 get_column(int c);
	void set_row(int r, Vector2& vec);
	Vector2 get_row(int r);
	Matrix2& operator+=(const Matrix2& m);
	Matrix2& operator-=(const Matrix2& m);
	void set_scaled(float x, float y);
	void set_scaled(const Vector2& v);
	void scale(float x, float y);
	void scale(const Vector2& v);
	void set_rotate(float radians);
	void rotate(float radians);
};

#endif
