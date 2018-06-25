#include "Vector4.h"

float vector4::operator [] (int index) const { return data[index]; }
float& vector4::operator [] (int index) { return data[index]; }
//ADDITION
vector4 vector4::operator + (const vector4& other) const {
	return{ x + other.x, y + other.y, z + other.z,w + other.w };
}

vector4& vector4::operator +=( vector4& other) {
	x += other.x; y += other.y; z += other.z, w += other.w;
	return *this;
}
//SUBTRACTION
vector4 vector4::operator - (const vector4& other) const
{
	return{ x - other.x, y - other.y, z - other.z,w - other.w };

}
vector4& vector4::operator -= (vector4& other)  {
	x -= other.x; y -= other.y; z -= other.z, w -= other.w;
	return *this;
}
//MULTIPLICATION
vector4 vector4::operator * (float scalar) const {
	return{ x * scalar, y * scalar, z * scalar,w * scalar };
}
vector4& vector4::operator *= (float scalar)  {
	 x *= scalar, y *= scalar, z *= scalar,w *= scalar ;
	return *this;
}
//DIVISION
vector4 vector4::operator /(float scalar) const{
return{ x / scalar, y / scalar, z / scalar, w / scalar };
}

vector4& vector4::operator /= (float scalar) {
	x /= scalar; y /= scalar; z /= scalar, w /= scalar;
	return *this;
}
//ASSIGNMENT
vector4& vector4::operator = (const vector4& other) {
	x = other.x; y = other.y; z = other.z,w = other.w;
	return *this;
}

