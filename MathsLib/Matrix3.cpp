#include "Matrix3.h"
#include <cmath>


matrix3::matrix3():data{ { 0,0,0 },{ 0,0,0 },{ 0,0,0 } }
{
}

matrix3::~matrix3()
= default;

matrix3::matrix3(const matrix3& matrix) : x_axis(matrix.x_axis), y_axis(matrix.y_axis), z_axis(matrix.z_axis)
{
}

matrix3::matrix3(const vector3& new_x_ax, const vector3& new_y_ax, const vector3& new_z_ax) : x_axis(new_x_ax), y_axis(new_y_ax), z_axis(new_z_ax)
{
}

matrix3::matrix3(const float a, const float b, const float c, const float d, const float e, const float f, const float g, const float h, const float i) : data{ {a,b,c},{d,e,f},{g,h,i} }
{
}


// create a static const identity matrix
const matrix3 matrix3::identity = matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);

// reference access so it can be modified
vector3& matrix3::operator [] (const int index) {
	return axis[index];
}
// const access for read-only
const vector3& matrix3::operator [] (const int index) const {
	return axis[index];
}

// binary * operator
matrix3 matrix3::operator * (const matrix3& other) const {
	matrix3 result;
	for (auto r = 0; r < 3; ++r) {
		for (auto c = 0; c < 3; ++c) {
			result.data[c][r] = 
				data[0][r] * other.data[c][0] +
				data[1][r] * other.data[c][1] +
				data[2][r] * other.data[c][2];
		}
	}
	return result;
}

vector3 matrix3::operator * (const vector3& v) const {
	vector3 result;
	for (auto r = 0; r < 3; ++r) {
		result[r] = 
			data[0][r] * v[0] +
			data[1][r] * v[1] +
			data[2][r] * v[2];
	}
	return result;
}

matrix3& matrix3::operator=(const matrix3& other)
{
	x_axis = other.x_axis; 
	y_axis = other.y_axis; 
	z_axis = other.z_axis;
		
	return *this;
	
}

matrix3 matrix3::transposed() const {
	matrix3 result;
	// flip row and column
	for (auto r = 0; r < 3; ++r)
		for (auto c = 0; c < 3; ++c)
			result.data[r][c] = data[c][r];
	return result;
}

void matrix3::set_element(const int r, const int c, const int e) {
	data[r][c] = e;
};

int matrix3::get_element(const int r, const int c) {
	return data[r][c];
}

void matrix3::set_column(const int c, vector3& vec) {
	for (auto i = 0; i<3; i++) {
		data[i][c] = vec[i];
	}
}

vector3 matrix3::get_column(const int c) {
	vector3 output;
	for (auto i = 0; i<3; i++) {
		output[i] = data[i][c];
	}
	return output;
}

void matrix3::set_row(const int r, vector3& vec) {
	for (auto i = 0; i<3; i++) {
		data[r][i] = vec[i];
	}
}

vector3 matrix3::get_row(const int r) {
	vector3 output;
	for (auto i = 0; i<3; i++) {
		output[i] = data[r][i];
	}
	return output;
}

matrix3& matrix3::operator+=(const matrix3& m)
{
	for (auto i = 0; i < 3; ++i) {
		for (auto j = 0; j < 3; ++j) {
			data[i][j] += m.data[i][j];
		}
	}
	return *this;
}


matrix3& matrix3::operator-=(const matrix3& m)
{
	for (auto i = 0; i < 3; ++i) {
		for (auto j = 0; j < 3; ++j) {
			data[i][j] -= m.data[i][j];
		}
	}
	return *this;
}

void matrix3::set_scaled(float x, float y, float z) {
	// set scale of each axis
	x_axis = { x, 0, 0 };
	y_axis = { 0, y, 0 };
	z_axis = { 0, 0, z };
}
void matrix3::set_scaled(const vector3& v) {
	// set scale of each axis
	x_axis = { v.x, 0, 0 };
	y_axis = { 0, v.y, 0 };
	z_axis = { 0, 0, v.z };
}
void matrix3::scale(const float x, const float y, const float z) {
	matrix3 m;
	m.set_scaled(x, y, z);
	*this = *this * m;
}
void matrix3::scale(const vector3& v) {
	matrix3 m;
	m.set_scaled(v.x, v.y, v.z);
	*this = *this * m;
}


void matrix3::set_rotate_x(const float radians) {
	// leave X axis and elements unchanged
	x_axis = { 1, 0, 0 };
	y_axis = { 0, cosf(radians), sinf(radians) };
	z_axis = { 0, -sinf(radians), cosf(radians) };
}
void matrix3::rotate_x(const float radians) {
	matrix3 m;
	m.set_rotate_x(radians);
	*this = *this * m;
}
void matrix3::set_rotate_y(const float radians) {
	// leave X axis and elements unchanged
	x_axis = { cosf(radians), 0,-sinf(radians) };
	y_axis = { 0, 1, 0 };
	z_axis = { sinf(radians),0 , cosf(radians) };
}
void matrix3::rotate_y(const float radians) {
	matrix3 m;
	m.set_rotate_y(radians);
	*this = *this * m;
}
void matrix3::set_rotate_z(const float radians) {
	// leave X axis and elements unchanged
	x_axis = { cosf(radians), -sinf(radians), 0 };
	y_axis = { sinf(radians), cosf(radians),0  };
	z_axis = { 0, 0,1  };
}
void matrix3::rotate_z(const float radians) {
	matrix3 m;
	m.set_rotate_z(radians);
	*this = *this * m;
}


void matrix3::set_euler(const float pitch, const float yaw, const float roll) {
	matrix3 x, y, z;
	x.set_rotate_x(pitch);
	y.set_rotate_y(yaw);
	z.set_rotate_z(roll);
	// combine rotations in a specific order
	*this = z * y * x;
}