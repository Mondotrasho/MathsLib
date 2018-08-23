#include "Matrix3.h"
#include <cmath>


Matrix3::Matrix3():data{ { 0,0,0 },{ 0,0,0 },{ 0,0,0 } }
{
}

Matrix3::~Matrix3()
= default;

Matrix3::Matrix3(const Matrix3& Matrix) : x_axis(Matrix.x_axis), y_axis(Matrix.y_axis), z_axis(Matrix.z_axis)
{
}

Matrix3::Matrix3(const Vector3& new_x_ax, const Vector3& new_y_ax, const Vector3& new_z_ax) : x_axis(new_x_ax), y_axis(new_y_ax), z_axis(new_z_ax)
{
}

Matrix3::Matrix3(const float a, const float b, const float c, const float d, const float e, const float f, const float g, const float h, const float i) : data { a, b, c,  d,e,f ,  g,h,i  }
{
}


// create a static const identity Matrix
const Matrix3 Matrix3::identity = Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);

// reference access so it can be modified
Vector3& Matrix3::operator [] (const int index) {
	return axis[index];
}
// const access for read-only
const Vector3& Matrix3::operator [] (const int index) const {
	return axis[index];
}

// binary * operator
Matrix3 Matrix3::operator * (const Matrix3& other) const {
	Matrix3 result;
	for (auto r = 0; r < 3; ++r) {
		for (auto c = 0; c < 3; ++c) {
			result.data[c][r] = data[0][r] * other.data[c][0] + data[1][r] * other.data[c][1] + data[2][r] * other.data[c][2];
		}
	}
	return result;
}

Vector3 Matrix3::operator * (const Vector3& v) const {
	Vector3 result;
	for (auto r = 0; r < 3; ++r) {
		result[r] = 
			data[0][r] * v[0] +
			data[1][r] * v[1] +
			data[2][r] * v[2];
	}
	return result;
}

Matrix3& Matrix3::operator=(const Matrix3& other)
{
	x_axis = other.x_axis; 
	y_axis = other.y_axis; 
	z_axis = other.z_axis;
		
	return *this;
	
}

Matrix3 Matrix3::transposed() const {
	Matrix3 result;
	// flip row and column
	for (auto r = 0; r < 3; ++r)
		for (auto c = 0; c < 3; ++c)
			result.data[r][c] = data[c][r];
	return result;
}

void Matrix3::set_element(const int r, const int c, const int e) {
	data[r][c] = e;
};

int Matrix3::get_element(const int r, const int c) {
	return data[r][c];
}

void Matrix3::set_column(const int c, Vector3& vec) {
	for (auto i = 0; i<3; i++) {
		data[i][c] = vec[i];
	}
}

Vector3 Matrix3::get_column(const int c) {
	Vector3 output;
	for (auto i = 0; i<3; i++) {
		output[i] = data[i][c];
	}
	return output;
}

void Matrix3::set_row(const int r, Vector3& vec) {
	for (auto i = 0; i<3; i++) {
		data[r][i] = vec[i];
	}
}

Vector3 Matrix3::get_row(const int r) {
	Vector3 output;
	for (auto i = 0; i<3; i++) {
		output[i] = data[r][i];
	}
	return output;
}

Matrix3& Matrix3::operator+=(const Matrix3& m)
{
	for (auto i = 0; i < 3; ++i) {
		for (auto j = 0; j < 3; ++j) {
			data[i][j] += m.data[i][j];
		}
	}
	return *this;
}


Matrix3& Matrix3::operator-=(const Matrix3& m)
{
	for (auto i = 0; i < 3; ++i) {
		for (auto j = 0; j < 3; ++j) {
			data[i][j] -= m.data[i][j];
		}
	}
	return *this;
}




void Matrix3::set_scaled(float x, float y) {
	// set scale of each axis
	x_axis = { x, 0, 0 };
	y_axis = { 0, y, 0 };
	z_axis = { 0, 0, 1 };
}
void Matrix3::set_scaled(const Vector3& v) {
	// set scale of each axis
	x_axis = { v.x, 0, 0 };
	y_axis = { 0, v.y, 0 };
	z_axis = { 0, 0, 1 };
}
void Matrix3::scale(const float x, const float y) {
	Matrix3 m;
	m.set_scaled(x, y);
	*this = *this * m;
}
void Matrix3::scale(const Vector3& v) { //creates scale matrix from vector input and scales
	Matrix3 m;
	m.set_scaled(v.x, v.y); //sets up new scale matrix using our vector
	*this = *this * m;
}

void Matrix3::scale(const Matrix3& m) { //takes scale matrix
	Matrix3 newtemp;
	// makes a new matrix with only the scale axis just to make sure you don't multiply anything else
	newtemp.x_axis = { m.x_axis.x,0,0 };
	newtemp.y_axis = { 0,m.y_axis.y,0 };
	newtemp.z_axis = { 0,0,1};

	*this = *this * newtemp; // Original x scale
}


void Matrix3::setRotateX(const float radians) {
	// leave X axis and elements unchanged
	x_axis = { 1, 0, 0 };
	y_axis = { 0, cosf(radians), sinf(radians) };
	z_axis = { 0, -sinf(radians), cosf(radians) };
}
void Matrix3::rotate_x(const float radians) {
	Matrix3 m;
	m.setRotateX(radians);
	*this = *this * m;
}
void Matrix3::setRotateY(const float radians) {
	// leave X axis and elements unchanged
	x_axis = { cosf(radians), 0,-sinf(radians) };
	y_axis = { 0, 1, 0 };
	z_axis = { sinf(radians),0 , cosf(radians) };
}
void Matrix3::rotate_y(const float radians) {
	Matrix3 m;
	m.setRotateY(radians);
	*this = *this * m;
}
void Matrix3::setRotateZ(const float radians) {
	// leave X axis and elements unchanged
	x_axis = { cosf(radians), -sinf(radians), 0 };
	y_axis = { sinf(radians), cosf(radians),0  };
	z_axis = { 0, 0,1 };
}
void Matrix3::rotate_z(const float radians) {
	Matrix3 m;
	m.setRotateZ(radians);
	*this = *this * m;
}


void Matrix3::set_euler(const float pitch, const float yaw, const float roll) {
	Matrix3 x, y, z;
	x.setRotateX(pitch);
	y.setRotateY(yaw);
	z.setRotateZ(roll);
	// combine rotations in a specific order
	*this = z * y * x;
}

void Matrix3::translate(float x, float y)
{
	z_axis.x += x;
	z_axis.y += y;

}