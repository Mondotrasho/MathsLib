#include "Vector2.h"
#include <cmath>

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

void vector2::zero()
{
	x = 0;
	y = 0;
}

vector2 vector2::invert() const
{
	return vector2(-x, -y);
}
float vector2::magnitude() const { return sqrt(x*x + y*y); }
float vector2::magnitude_sqr() const { return (x*x + y*y); }
void vector2::normalise() {
	x /= magnitude();
	y /= magnitude();
}
vector2 vector2::normalised(vector2) const
{
	return{ x / magnitude(), y / magnitude()};
}

float vector2::distance(const vector2& other) const {
	const auto diff_x = x - other.x;
	const auto diff_y = y - other.y;
	return sqrt(diff_x * diff_x + diff_y * diff_y);
}
float vector2::dot(const vector2& other) const {
	return x * other.x + y * other.y;
}
vector2 vector2::getPerpendicularRH() const {
	return{ -y, x };
}