#include "Matrix2.h"
#include <cmath>

Matrix2::Matrix2():data{ { 0,0 },{ 0,0 } }
{
}

Matrix2::~Matrix2()
= default;

Matrix2::Matrix2(const Matrix2& Matrix) : x_axis(Matrix.x_axis), y_axis(Matrix.y_axis)
{
}

Matrix2::Matrix2(const Vector2& new_x_ax, const Vector2& new_y_ax, const Vector2& new_z_ax) : x_axis(new_x_ax), y_axis(new_y_ax)
{
}

Matrix2::Matrix2(const float a, const float b, const float c, const float d) : data{{ a,b},{ c,d }}
{
}


// create a static const identity Matrix
const Matrix2 Matrix2::identity = Matrix2(1, 0, 0, 1);


// reference access so it can be modified
Vector2& Matrix2::operator [] (const int index) {
	return axis[index];
}
// const access for read-only
const Vector2& Matrix2::operator [] (const int index) const {
	return axis[index];
}

// binary * operator
Matrix2 Matrix2::operator * (const Matrix2& other) const {
	Matrix2 result;
	for (auto r = 0; r < 2; ++r) {
		for (auto c = 0; c < 2; ++c) {
			result.data[c][r] =
				data[0][r] * other.data[c][0] +
				data[1][r] * other.data[c][1];
		}
	}
	return result;
}

Vector2 Matrix2::operator * (const Vector2& v) const {
	Vector2 result;
	for (auto r = 0; r < 2; ++r) {
		result[r] =
			data[0][r] * v[0] +
			data[1][r] * v[1];
	}
	return result;
}
Matrix2& Matrix2::operator=(const Matrix2& other)
{
	x_axis = other.x_axis;
	y_axis = other.y_axis;
	

	return *this;

}
Matrix2 Matrix2::transposed() const {
	Matrix2 result;
	// flip row and column
	for (auto r = 0; r < 2; ++r)
		for (auto c = 0; c < 2; ++c)
			result.data[r][c] = data[c][r];
	return result;
}

void Matrix2::set_element(const int r, const int c, const int e) {
	data[r][c] = e;
};

int Matrix2::get_element(const int r, const int c) {
	return data[r][c];
}

void Matrix2::set_column(const int c, Vector2& vec) {
	for (auto i = 0; i<2; i++) {
		data[i][c] = vec[i];
	}
}

Vector2 Matrix2::get_column(const int c) {
	Vector2 output;
	for (auto i = 0; i<2; i++) {
		output[i] = data[i][c];
	}
	return output;
}

void Matrix2::set_row(const int r, Vector2& vec) {
	for (auto i = 0; i<2; i++) {
		data[r][i] = vec[i];
	}
}

Vector2 Matrix2::get_row(const int r) {
	Vector2 output;
	for (auto i = 0; i<2; i++) {
		output[i] = data[r][i];
	}
	return output;
}

Matrix2& Matrix2::operator+=(const Matrix2& m)
{
	for (auto i = 0; i < 2; ++i) {
		for (auto j = 0; j < 2; ++j) {
			data[i][j] += m.data[i][j];
		}
	}
	return *this;
}


Matrix2& Matrix2::operator-=(const Matrix2& m)
{
	for (auto i = 0; i < 2; ++i) {
		for (auto j = 0; j < 2; ++j) {
			data[i][j] -= m.data[i][j];
		}
	}
	return *this;
}

void Matrix2::set_scaled(float x, float y) {
	// set scale of each axis
	x_axis = { x, 0};
	y_axis = { 0, y};
	}
void Matrix2::set_scaled(const Vector2& v) {
	// set scale of each axis
	x_axis = { v.x, 0};
	y_axis = { 0, v.y};
}
void Matrix2::scale(const float x, const float y) {
	Matrix2 m;
	m.set_scaled(x, y);
	*this = *this * m;
}
void Matrix2::scale(const Vector2& v) {
	Matrix2 m;
	m.set_scaled(v.x, v.y);
	*this = *this * m;
}

void Matrix2::setRotate(const float radians) {

	// leave X axis and elements unchanged
	x_axis = { cosf(radians), -sinf(radians),};
	y_axis = { sinf(radians), cosf(radians)};
}
void Matrix2::rotate(const float radians) {
	Matrix2 m;
	m.setRotate(radians);
	*this = *this * m;
}
