#include "Vector3.h"

float Vector3::operator [] (int index) const { return data[index]; }
float& Vector3::operator [] (int index) { return data[index]; }
Vector3 Vector3::operator + (const Vector3& other) const {
	return{ x + other.x, y + other.y, z + other.z };
}
Vector3& Vector3::operator -= (const Vector3& other) {
	x -= other.x; y -= other.y; z -= other.z;
	return *this;
}
Vector3 Vector3::operator * (float scalar) const {
	return{ x * scalar, y * scalar, z * scalar };
}
Vector3& Vector3::operator /= (float scalar) {
	x /= scalar; y /= scalar; z /= scalar;
	return *this;
}
Vector3& Vector3::operator = (const Vector3& other) {
	x = other.x; y = other.y; z = other.z;
	return *this;
}