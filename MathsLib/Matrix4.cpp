#include "Matrix4.h"

matrix4::matrix4()
= default;


matrix4::~matrix4()
= default;

// reference access so it can be modified
vector4& matrix4::operator [] (const int index) {
	return axis[index];
}
// const access for read-only
const vector4& matrix4::operator [] (const int index) const {
	return axis[index];
}