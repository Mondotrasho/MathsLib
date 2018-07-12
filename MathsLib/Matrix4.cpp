#include "Matrix4.h"

matrix4::matrix4(): data{ { 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } }
{
}

matrix4::~matrix4()
= default;

matrix4::matrix4(const matrix4& matrix) : x_axis(matrix.x_axis), y_axis(matrix.y_axis), z_axis(matrix.z_axis), w_axis(matrix.w_axis)
{
}


matrix4::matrix4(const vector4& new_x_ax, const vector4& new_y_ax, const vector4& new_z_ax, const vector4& new_w_ax) : x_axis(new_x_ax), y_axis(new_y_ax), z_axis(new_z_ax), w_axis(new_w_ax)
{
}

matrix4::matrix4(const float a, const float b, const float c, const float d, const float e, const float f, const float g, const float h, const float i, const float j, const float k, const float l, const float m, const float n, const float o, const float p) : data{ { a,b,c,d },{ e,f,g,h },{ i,j,k,l },{ m,n,o,p } }
{
}


// create a static const identity matrix
const matrix4 matrix4::identity = matrix4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);


// reference access so it can be modified
vector4& matrix4::operator [] (const int index) {
	return axis[index];
}
// const access for read-only
const vector4& matrix4::operator [] (const int index) const {
	return axis[index];
}

matrix4 matrix4::operator * (const matrix4& other) const {
	matrix4 result;
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

vector4 matrix4::operator * (const vector4& v) const {
	vector4 result;
	for (auto r = 0; r < 4; ++r) {
		result[r] =
			data[0][r] * v[0] +
			data[1][r] * v[1] + 
			data[2][r] * v[2] + 
			data[3][r] * v[3]; 
	}
	return result;
}

matrix4 matrix4::transposed() const {
	matrix4 result;
	// flip row and column
	for (int r = 0; r < 4; ++r)
		for (int c = 0; c < 4; ++c)
			result.data[r][c] = data[c][r];
	return result;
}