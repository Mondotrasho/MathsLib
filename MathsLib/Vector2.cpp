#include "Vector2.h"

float vector2::operator [] (int index) const { return data[index]; }
float& vector2::operator [] (int index) { return data[index]; }
//ADDITION
vector2 vector2::operator + (const vector2& other) const {
	return{ x + other.x, y + other.y};
}
vector2& vector2::operator += (const vector2& other) {
	x += other.x; y += other.y;
	return *this;
}
//SUBTRACTION
vector2 vector2::operator - (const vector2& other) const {
	return{ x - other.x, y - other.y };
}
vector2& vector2::operator -= (const vector2& other) {
	x -= other.x; y -= other.y;
	return *this;
}
//MULTIPLICATION
vector2 vector2::operator * (float scalar) const {
	return{ x * scalar, y * scalar };
}
vector2& vector2::operator *= (float scalar) {
	x *= scalar; y *= scalar;
	return *this;
}
//DICISION
vector2 vector2::operator / (float scalar) const {
	return{ x / scalar, y / scalar };
}
vector2& vector2::operator /= (float scalar) {
	x /= scalar; y /= scalar;
	return *this;
}
//ASSIGNMENT
vector2& vector2::operator = (const vector2& other) {
	x = other.x; y = other.y;
	return *this;
}