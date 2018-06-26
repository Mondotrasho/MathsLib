#include "Matrix4.h"
#include "Vector3.h"
matrix4::matrix4(): data{ { 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } }
{
}

matrix4::~matrix4()
= default;

matrix4::matrix4(const matrix4& matrix) : x_axis(matrix.x_axis), y_axis(matrix.y_axis), z_axis(matrix.z_axis), w_axis(matrix.w_axis)
{
}

matrix4::matrix4(const vector3& new_x_ax, const vector3& new_y_ax, const vector3& new_z_ax, const vector3& new_w_ax) : x_axis(new_x_ax), y_axis(new_y_ax), z_axis(new_z_ax), w_axis(new_w_ax)
{
}

matrix4::matrix4(const float a, const float b, const float c, const float d, const float e, const float f, const float g, const float h, const float i, const float j, const float k, const float l, const float m, const float n, const float o, const float p) : data{ { a,b,c,d },{ e,f,g,h },{ i,j,k,l },{ m,n,o,p } }
{
}

// reference access so it can be modified
vector3& matrix4::operator [] (const int index) {
	return axis[index];
}
// const access for read-only
const vector3& matrix4::operator [] (const int index) const {
	return axis[index];
}