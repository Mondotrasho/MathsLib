#include "Matrix2.h"

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

// reference access so it can be modified
vector2& matrix2::operator [] (const int index) {
	return axis[index];
}
// const access for read-only
const vector2& matrix2::operator [] (const int index) const {
	return axis[index];
}