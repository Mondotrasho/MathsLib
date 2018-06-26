#include "Matrix2.h"

matrix2::matrix2()
= default;


matrix2::~matrix2()
= default;

// reference access so it can be modified
vector2& matrix2::operator [] (const int index) {
	return axis[index];
}
// const access for read-only
const vector2& matrix2::operator [] (const int index) const {
	return axis[index];
}