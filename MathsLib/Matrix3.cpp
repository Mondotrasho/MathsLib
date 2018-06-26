#include "Matrix3.h"

matrix3::matrix3() = default;


matrix3::~matrix3() = default;

matrix3::matrix3(const matrix3& matrix) : x_axis(matrix.x_axis), y_axis(matrix.y_axis), z_axis(matrix.z_axis)
{
}

matrix3::matrix3(const vector3& new_x_ax, const vector3& new_y_ax, const vector3& new_z_ax) : x_axis(new_x_ax), y_axis(new_y_ax), z_axis(new_z_ax)
{
}

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
	for (int r = 0; r < 3; ++r) {
		for (int c = 0; c < 3; ++c) {
			result.data[c][r] = data[0][r] * other.data[c][0] +
				data[1][r] * other.data[c][1] +
				data[2][r] * other.data[c][2];
		}
	}
	return result;
}
// binary * operator
vector3 matrix3::operator * (const vector3& v) const {
	vector3 result;
	for (int r = 0; r < 3; ++r) {
		result[r] = data[0][r] * v[0] +
			data[1][r] * v[1] +
			data[2][r] * v[2];
	}
	return result;
}