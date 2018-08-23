#include "Matrix4.h"
#include <math.h>

Matrix4::Matrix4(): data{ { 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } }
{
}

Matrix4::~Matrix4()
= default;

Matrix4::Matrix4(const Matrix4& Matrix) : x_axis(Matrix.x_axis), y_axis(Matrix.y_axis), z_axis(Matrix.z_axis), translation(Matrix.translation)
{
}


Matrix4::Matrix4(const Vector4& new_x_ax, const Vector4& new_y_ax, const Vector4& new_z_ax, const Vector4& new_w_ax) : x_axis(new_x_ax), y_axis(new_y_ax), z_axis(new_z_ax), translation(new_w_ax)
{
}

Matrix4::Matrix4(const float a, const float b, const float c, const float d, const float e, const float f, const float g, const float h, const float i, const float j, const float k, const float l, const float m, const float n, const float o, const float p) : data{ { a,b,c,d },{ e,f,g,h },{ i,j,k,l },{ m,n,o,p } }
{
}


// create a static const identity Matrix
const Matrix4 Matrix4::identity = Matrix4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);


// reference access so it can be modified
Vector4& Matrix4::operator [] (const int index) {
	return axis[index];
}
// const access for read-only
const Vector4& Matrix4::operator [] (const int index) const {
	return axis[index];
}

Matrix4 Matrix4::operator * (const Matrix4& other) const {
	Matrix4 result;
	for (auto r = 0; r < 4; ++r) {
		for (auto c = 0; c < 4; ++c) {
			result.data[c][r] =
				data[0][r] * other.data[c][0] +
				data[1][r] * other.data[c][1] +
				data[2][r] * other.data[c][2] +
				data[3][r] * other.data[c][3];
		}
	}
	return result;
}

Vector4 Matrix4::operator * (const Vector4& v) const {
	Vector4 result;
	for (auto r = 0; r < 4; ++r) {
		result[r] =
			data[0][r] * v[0] +
			data[1][r] * v[1] + 
			data[2][r] * v[2] + 
			data[3][r] * v[3]; 
	}
	return result;
}

Matrix4& Matrix4::operator=(const Matrix4& other)
{
	x_axis = other.x_axis;
	y_axis = other.y_axis;
	z_axis = other.z_axis;
	translation = other.translation;
	return *this;

}

Matrix4 Matrix4::transposed() const {
	Matrix4 result;
	// flip row and column
	for (int r = 0; r < 4; ++r)
		for (int c = 0; c < 4; ++c)
			result.data[r][c] = data[c][r];
	return result;
}

void Matrix4::setScaled(float x, float y, float z) {
	// set scale of each axis
	x_axis = { x, 0, 0, 0 };
	y_axis = { 0, y, 0, 0 };
	z_axis = { 0, 0, z, 0 };
	translation = { 0, 0, 0, 1 };
}

void Matrix4::setRotateX(float radians) { //WHY IS THIS HERE
	// leave X axis and elements unchanged
	x_axis = { 1, 0, 0, 0 };
	y_axis = { 0, cosf(radians), sinf(radians), 0 };
	z_axis = { 0, -sinf(radians), cosf(radians), 0 };
	translation = { 0, 0, 0, 1 };
}

void Matrix4::rotate_x(const float radians) {
	Matrix4 m;
	m.setRotateX(radians);
	*this = *this * m;
}
void Matrix4::setRotateY(const float radians) {
	// leave X axis and elements unchanged
	x_axis = { cosf(radians), 0,-sinf(radians),0 };
	y_axis = { 0, 1, 0,0 };
	z_axis = { sinf(radians),0 , cosf(radians),0 };
	translation = { 0, 0, 0, 1 };
}
void Matrix4::rotate_y(const float radians) {
	Matrix4 m;
	m.setRotateY(radians);
	*this = *this * m;
}
void Matrix4::setRotateZ(const float radians) {
	// leave X axis and elements unchanged
	x_axis = { cosf(radians), -sinf(radians), 0,0 };
	y_axis = { sinf(radians), cosf(radians),0,0 };
	z_axis = { 0, 0,1,0 };
	translation = { 0, 0, 0, 1 };
}
void Matrix4::rotate_z(const float radians) {
	Matrix4 m;
	m.setRotateZ(radians);
	*this = *this * m;
}


void Matrix4::set_euler(const float pitch, const float yaw, const float roll) {
	Matrix4 x, y, z;
	x.setRotateX(pitch);
	y.setRotateY(yaw);
	z.setRotateZ(roll);

	// combine rotations in a specific order
	*this = z * y * x;
}

void Matrix4::translate(float x, float y, float z) {
	// apply vector offset
	translation += Vector4(x, y, z, 0);
}
