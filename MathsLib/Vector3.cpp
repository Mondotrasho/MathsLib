#include "Vector3.h"

float vector3::operator [] (int index) const { return data[index]; }
float& vector3::operator [] (int index) { return data[index]; }
//ADDITION

vector3 vector3::operator + (const vector3& other) const {
	return{ x + other.x, y + other.y, z + other.z };
}
vector3& vector3::operator += (const vector3& other) {
	x += other.x; y += other.y; z += other.z;
	return *this;
}
//SUBTRACTION
vector3 vector3::operator - (const vector3& other) const {
	return{ x - other.x, y - other.y, z - other.z };
}
vector3& vector3::operator -= (const vector3& other) {
	x -= other.x; y -= other.y; z -= other.z;
	return *this;
}
//MULTIPLICATION
vector3 vector3::operator * (float scalar) const {
	return{ x * scalar, y * scalar, z * scalar };
}
vector3& vector3::operator *= (float scalar) {
	x *= scalar; y *= scalar; z *= scalar;
	return *this;
}
//DIVISION
vector3 vector3::operator / (float scalar) const {
	return{ x / scalar, y / scalar, z / scalar };
}
vector3& vector3::operator /= (float scalar) {
	x /= scalar; y /= scalar; z /= scalar;
	return *this;
}
//ASSIGNMENT
vector3& vector3::operator = (const vector3& other) {
	x = other.x; y = other.y; z = other.z;
	return *this;
}

void vector3::zero()
{
	x = 0;
	y = 0;
	z = 0;
}

vector3 vector3::invert() const
{
	return vector3(-x, -y, -z);
}
