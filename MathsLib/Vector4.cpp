#include "Vector4.h"
#include <cmath>

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

void vector4::zero()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

vector4 vector4::invert() const
{
	return vector4(-x, -y, -z, -w);
}

float vector4::magnitude() const { return sqrt(x*x + y*y + z*z + w*w); }
float vector4::magnitude_sqr() const { return (x*x + y*y + z*z + w*w); }
void vector4::normalise() {
	x /= magnitude();
	y /= magnitude();
	z /= magnitude();
	w /= magnitude();
}
vector4 vector4::normalised(vector4) const
{
	return{ x / magnitude(), y / magnitude(), z / magnitude(), w / magnitude() };
}

float vector4::distance(const vector4& other) const {
	const auto diff_x = x - other.x;
	const auto diff_y = y - other.y;
	const auto diff_z = z - other.z;
	const auto diff_w = w - other.w;
	return sqrt(diff_x * diff_x + diff_y * diff_y + diff_z * diff_z + diff_w * diff_w);
}