#include "Vector3.h"

float vector3::operator [] (int index) const { return data[index]; }
float& vector3::operator [] (int index) { return data[index]; }
vector3 vector3::operator + (const vector3& other) const {
	return{ x + other.x, y + other.y, z + other.z };
}
vector3& vector3::operator -= (const vector3& other) {
	x -= other.x; y -= other.y; z -= other.z;
	return *this;
}
vector3 vector3::operator * (float scalar) const {
	return{ x * scalar, y * scalar, z * scalar };
}
vector3& vector3::operator /= (float scalar) {
	x /= scalar; y /= scalar; z /= scalar;
	return *this;
}
vector3& vector3::operator = (const vector3& other) {
	x = other.x; y = other.y; z = other.z;
	return *this;
}