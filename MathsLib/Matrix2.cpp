#include "Matrix2.h"
#include <cmath>

matrix2::matrix2():data{ { 0,0 },{ 0,0 } }
{
}

matrix2::~matrix2()
= default;

matrix2::matrix2(const matrix2& matrix) : x_axis(matrix.x_axis), y_axis(matrix.y_axis)
{
}

matrix2::matrix2(const vector2& new_x_ax, const vector2& new_y_ax, const vector2& new_z_ax) : x_axis(new_x_ax), y_axis(new_y_ax)
{
}

matrix2::matrix2(const float a, const float b, const float c, const float d) : data{{ a,b},{ c,d }}
{
}


// create a static const identity matrix
const matrix2 matrix2::identity = matrix2(1, 0, 0, 1);


// reference access so it can be modified
vector2& matrix2::operator [] (const int index) {
	return axis[index];
}
// const access for read-only
const vector2& matrix2::operator [] (const int index) const {
	return axis[index];
}

// binary * operator
matrix2 matrix2::operator * (const matrix2& other) const {
	matrix2 result;
	for (auto r = 0; r < 2; ++r) {
		for (auto c = 0; c < 2; ++c) {
			result.data[c][r] =
				data[0][r] * other.data[c][0] +
				data[1][r] * other.data[c][1];
		}
	}
	return result;
}

vector2 matrix2::operator * (const vector2& v) const {
	vector2 result;
	for (auto r = 0; r < 2; ++r) {
		result[r] =
			data[0][r] * v[0] +
			data[1][r] * v[1];
	}
	return result;
}
matrix2& matrix2::operator=(const matrix2& other)
{
	x_axis = other.x_axis;
	y_axis = other.y_axis;
	

	return *this;

}
matrix2 matrix2::transposed() const {
	matrix2 result;
	// flip row and column
	for (auto r = 0; r < 2; ++r)
		for (auto c = 0; c < 2; ++c)
			result.data[r][c] = data[c][r];
	return result;
}

void matrix2::set_element(const int r, const int c, const int e) {
	data[r][c] = e;
};

int matrix2::get_element(const int r, const int c) {
	return data[r][c];
}

void matrix2::set_column(const int c, vector2& vec) {
	for (auto i = 0; i<2; i++) {
		data[i][c] = vec[i];
	}
}

vector2 matrix2::get_column(const int c) {
	vector2 output;
	for (auto i = 0; i<2; i++) {
		output[i] = data[i][c];
	}
	return output;
}

void matrix2::set_row(const int r, vector2& vec) {
	for (auto i = 0; i<2; i++) {
		data[r][i] = vec[i];
	}
}

vector2 matrix2::get_row(const int r) {
	vector2 output;
	for (auto i = 0; i<2; i++) {
		output[i] = data[r][i];
	}
	return output;
}

matrix2& matrix2::operator+=(const matrix2& m)
{
	for (auto i = 0; i < 2; ++i) {
		for (auto j = 0; j < 2; ++j) {
			data[i][j] += m.data[i][j];
		}
	}
	return *this;
}


matrix2& matrix2::operator-=(const matrix2& m)
{
	for (auto i = 0; i < 2; ++i) {
		for (auto j = 0; j < 2; ++j) {
			data[i][j] -= m.data[i][j];
		}
	}
	return *this;
}

void matrix2::set_scaled(float x, float y) {
	// set scale of each axis
	x_axis = { x, 0};
	y_axis = { 0, y};
	}void matrix2::set_scaled(const vector2& v) {
	// set scale of each axis
	x_axis = { v.x, 0};
	y_axis = { 0, v.y};
}void matrix2::scale(const float x, const float y) {
	matrix2 m;
	m.set_scaled(x, y);
	*this = *this * m;
}void matrix2::scale(const vector2& v) {
	matrix2 m;
	m.set_scaled(v.x, v.y);
	*this = *this * m;
}


void matrix2::set_rotate(const float radians) {
	// leave X axis and elements unchanged
	x_axis = { cosf(radians), -sinf(radians),};
	y_axis = { sinf(radians), cosf(radians)};
}
void matrix2::rotate(const float radians) {
	matrix2 m;
	m.set_rotate(radians);
	*this = *this * m;
}
