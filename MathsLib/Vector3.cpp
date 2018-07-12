#include "Vector3.h"
#include <cmath>

Vector3::Vector3() :data{ 0,0,0 }
{
}

Vector3::~Vector3()
= default;

Vector3::Vector3(const Vector3& Vector): x(Vector.x), y(Vector.y), z(Vector.z)
{
}


//Vector3::Vector3(const float a, const float b, const float c) : data{ a,b,c }
//{
//}

Vector3::Vector3(const float xval, const float yval, const float zval) : x(xval), y(yval), z(zval)
{
}

float Vector3::operator [] (int index) const { return data[index]; }
float& Vector3::operator [] (int index) { return data[index]; }
//ADDITION

Vector3 Vector3::operator + (const Vector3& other) const {
	return{ x + other.x, y + other.y, z + other.z };
}
Vector3 Vector3::operator + (const float other) const {
	return{ x + other, y + other, z + other };
}
Vector3& Vector3::operator += (const Vector3& other) {
	x += other.x; y += other.y; z += other.z;
	return *this;
}
//SUBTRACTION
Vector3 Vector3::operator - (const Vector3& other) const {
	return{ x - other.x, y - other.y, z - other.z };
}
Vector3 Vector3::operator - (const float other) const {
	return{ x - other, y - other, z - other };
}
Vector3& Vector3::operator -= (const Vector3& other) {
	x -= other.x; y -= other.y; z -= other.z;
	return *this;
}
//MULTIPLICATION
Vector3 Vector3::operator * (float scalar) const {
	return{ x * scalar, y * scalar, z * scalar };
}
Vector3& Vector3::operator *= (float scalar) {
	x *= scalar; y *= scalar; z *= scalar;
	return *this;
}
//DIVISION
Vector3 Vector3::operator / (float scalar) const {
	return{ x / scalar, y / scalar, z / scalar };
}
Vector3& Vector3::operator /= (float scalar) {
	x /= scalar; y /= scalar; z /= scalar;
	return *this;
}
//ASSIGNMENT
Vector3& Vector3::operator = (const Vector3& other) {
	x = other.x; y = other.y; z = other.z;
	return *this;
}

void Vector3::zero()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3 Vector3::invert() const
{
	return Vector3(-x, -y, -z);
}
float Vector3::magnitude() const { return sqrt(x*x + y*y + z*z); }
float Vector3::magnitude_sqr() const { return (x*x + y*y + z*z); }

void Vector3::normalise() {
	x /= magnitude();
	y /= magnitude();
	z /= magnitude();
}
Vector3 Vector3::normalised() const
{
	return{ x / magnitude(), y / magnitude(), z / magnitude() };
}

float Vector3::distance(const Vector3& other) const {
	const auto diff_x = x - other.x;
	const auto diff_y = y - other.y;
	const auto diff_z = z - other.z;
	return sqrt(diff_x * diff_x + diff_y * diff_y + diff_z * diff_z);
}
float Vector3::distance_sqr(const Vector3& other) const {
	const auto diff_x = x - other.x;
	const auto diff_y = y - other.y;
	const auto diff_z = z - other.z;
	return diff_x * diff_x + diff_y * diff_y + diff_z * diff_z;
}

float Vector3::dot(const Vector3& other) const {
	return x * other.x + y * other.y + z * other.z;
}

Vector3 Vector3::cross(const Vector3& other) const {
	return{ 
		y * other.z - z * other.y,
		z * other.x - x * other.z,
		x * other.y - y * other.x };
}

float Vector3::angle_between(const Vector3& other) const {
	// normalise the Vectors
	const auto a = normalised();
	const auto b = other.normalised();
	// calculate the dot product
	float d = a.x * b.x + a.y * b.y + a.z * b.z;
	// return the angle between them
	return acos(d);
}

//ADD GET PERPINDICULAR