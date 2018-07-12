#include "Vector4.h"
#include <cmath>

Vector4::Vector4() : data{ 0, 0, 0, 0 } 
{
}

Vector4::~Vector4()
= default;

Vector4::Vector4(const Vector4& Vector): x(Vector.x), y(Vector.y), z(Vector.z), w(Vector.w)
{
}

Vector4::Vector4(float xval, float yval, float zval, float wval): x(xval), y(yval), z(zval), w(wval)
{
}

float Vector4::operator [] (int index) const { return data[index]; }
float& Vector4::operator [] (int index) { return data[index]; }
//ADDITION
Vector4 Vector4::operator + (const Vector4& other) const {
	return{ x + other.x, y + other.y, z + other.z,w + other.w };
}
Vector4 Vector4::operator  + (const float other) const{
	return{ x + other, y + other, z + other,w + other };
}
Vector4& Vector4::operator +=( Vector4& other) {
	x += other.x; y += other.y; z += other.z, w += other.w;
	return *this;
}
//SUBTRACTION
Vector4 Vector4::operator - (const Vector4& other) const
{
	return{ x - other.x, y - other.y, z - other.z,w - other.w };

}
Vector4 Vector4::operator - (const float other) const
{
	return{ x - other, y - other, z - other,w - other };

}
Vector4& Vector4::operator -= (Vector4& other)  {
	x -= other.x; y -= other.y; z -= other.z, w -= other.w;
	return *this;
}



//MULTIPLICATION
Vector4 Vector4::operator * (float scalar) const {
	return{ x * scalar, y * scalar, z * scalar,w * scalar };
}
Vector4& Vector4::operator *= (float scalar)  {
	 x *= scalar, y *= scalar, z *= scalar,w *= scalar ;
	return *this;
}
//DIVISION
Vector4 Vector4::operator /(float scalar) const{
return{ x / scalar, y / scalar, z / scalar, w / scalar };
}

Vector4& Vector4::operator /= (float scalar) {
	x /= scalar; y /= scalar; z /= scalar, w /= scalar;
	return *this;
}
//ASSIGNMENT
Vector4& Vector4::operator = (const Vector4& other) {
	x = other.x; y = other.y; z = other.z,w = other.w;
	return *this;
}

void Vector4::zero()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

Vector4 Vector4::invert() const
{
	return Vector4(-x, -y, -z, -w);
}

float Vector4::magnitude() const { return sqrt(x*x + y*y + z*z + w*w); }
float Vector4::magnitude_sqr() const { return (x*x + y*y + z*z + w*w); }

void Vector4::normalise() {
	x /= magnitude();
	y /= magnitude();
	z /= magnitude();
	w /= magnitude();
}
Vector4 Vector4::normalised() const
{
	return{ x / magnitude(), y / magnitude(), z / magnitude(), w / magnitude() };
}

float Vector4::distance(const Vector4& other) const {
	const auto diff_x = x - other.x;
	const auto diff_y = y - other.y;
	const auto diff_z = z - other.z;
	const auto diff_w = w - other.w;
	return sqrt(diff_x * diff_x + diff_y * diff_y + diff_z * diff_z + diff_w * diff_w);
}
float Vector4::distance_sqr(const Vector4& other) const {
	const auto diff_x = x - other.x;
	const auto diff_y = y - other.y;
	const auto diff_z = z - other.z;
	const auto diff_w = w - other.w;
	return diff_x * diff_x + diff_y * diff_y + diff_z * diff_z + diff_w * diff_w;
}

float Vector4::dot(const Vector4& other) const {
	return x * other.x + y * other.y + z * other.z + w * other.w;
}

float Vector4::angle_between(const Vector4& other) const {
	// normalise the Vectors
	const auto a = normalised();
	const auto b = other.normalised();
	// calculate the dot product
	float d = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	// return the angle between them
	return acos(d);
}