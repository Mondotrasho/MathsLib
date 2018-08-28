#include "Vector2.h"
#include <cmath>

Vector2::Vector2(): data{0,0}
{
}

Vector2::~Vector2()
= default;

Vector2::Vector2(const Vector2& Vector): x(Vector.x), y(Vector.y)
{
}

Vector2::Vector2(float xval, float yval): x(xval), y(yval)
{
}

Vector2& Vector2::operator+=(const float& other)//suss
{
	x += other; y += other;
	return *this;
}

Vector2& Vector2::operator-=(const float& other)//suss
{
	x -= other; y -= other;
	return *this;
}

float Vector2::operator [] (int index) const { return data[index]; }
float& Vector2::operator [] (int index) { return data[index]; }
//ADDITION
Vector2 Vector2::operator + (const Vector2& other) const {
	return{ x + other.x, y + other.y };
}
Vector2 Vector2::operator + (const float other) const {
	return{ x + other, y + other };
}
Vector2& Vector2::operator += (const Vector2& other) {
	x += other.x; y += other.y;
	return *this;
}
//SUBTRACTION
Vector2 Vector2::operator - (const Vector2& other) const {
	return{ x - other.x, y - other.y };
}
Vector2 Vector2::operator - (const float other) const {
	return{ x - other, y - other };
}
Vector2& Vector2::operator -= (const Vector2& other) {
	x -= other.x; y -= other.y;
	return *this;
}
//MULTIPLICATION
Vector2 Vector2::operator * (float scalar) const {
	return{ x * scalar, y * scalar };
}
Vector2& Vector2::operator *= (float scalar) {
	x *= scalar; y *= scalar;
	return *this;
}
//DICISION
Vector2 Vector2::operator / (float scalar) const {
	return{ x / scalar, y / scalar };
}
Vector2& Vector2::operator /= (float scalar) {
	x /= scalar; y /= scalar;
	return *this;
}
//ASSIGNMENT
Vector2& Vector2::operator = (const Vector2& other) {
	x = other.x; y = other.y;
	return *this;
}

void Vector2::zero()
{
	x = 0;
	y = 0;
}

Vector2 Vector2::invert() const
{
	return Vector2(-x, -y);
}
float Vector2::magnitude() const { return sqrt(x*x + y*y); }
float Vector2::magnitude_sqr() const { return (x*x + y*y); }

void Vector2::normalise() {
	float magtemp = magnitude();

	x /= magtemp;
	y /= magtemp;
}
Vector2 Vector2::normalised() const
{
	float magtemp = magnitude();
	return{ x / magtemp, y / magtemp };
}

float Vector2::distance(const Vector2& other) const {
	const auto diff_x = x - other.x;
	const auto diff_y = y - other.y;
	return sqrt(diff_x * diff_x + diff_y * diff_y);
}
float Vector2::distance_sqr(const Vector2& other) const {
	const auto diff_x = x - other.x;
	const auto diff_y = y - other.y;
	return diff_x * diff_x + diff_y * diff_y;
}
float Vector2::dot(const Vector2& other) const {
	return x * other.x + y * other.y;
}
Vector2 Vector2::get_perpendicular_rh() const {
	return{ -y, x };
}
Vector2 Vector2::get_perpendicular_lh() const {
	return{ y, -x };
}
float Vector2::angle_between(const Vector2& other) const {
	// normalise the Vectors
	const auto a = normalised();
	const auto b = other.normalised();
	// calculate the dot product
	float d = a.x * b.x + a.y * b.y;
	// return the angle between them
	return acos(d);
}

Vector2 operator*(const float lhs, const Vector2& rhs)
{
	float temp1 = lhs * rhs.x;
	float temp2 = lhs * rhs.y;

	return Vector2{ temp1, temp2 };
}
