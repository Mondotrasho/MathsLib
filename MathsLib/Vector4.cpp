#include "Vector4.h"
#include <cmath>

vector4::vector4() : data{ 0, 0, 0, 0 } 
{
}

vector4::~vector4()
= default;

vector4::vector4(const vector4& vector): x(vector.x), y(vector.y), z(vector.z), w(vector.w)
{
}

vector4::vector4(float xval, float yval, float zval, float wval): x(xval), y(yval), z(zval), w(wval)
{
}

float vector4::operator [] (int index) const { return data[index]; }
float& vector4::operator [] (int index) { return data[index]; }
//ADDITION
vector4 vector4::operator + (const vector4& other) const {
	return{ x + other.x, y + other.y, z + other.z,w + other.w };
}
vector4 vector4::operator  + (const float other) const{
	return{ x + other, y + other, z + other,w + other };
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
vector4 vector4::operator - (const float other) const
{
	return{ x - other, y - other, z - other,w - other };

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
vector4 vector4::normalised() const
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
float vector4::distance_sqr(const vector4& other) const {
	const auto diff_x = x - other.x;
	const auto diff_y = y - other.y;
	const auto diff_z = z - other.z;
	const auto diff_w = w - other.w;
	return diff_x * diff_x + diff_y * diff_y + diff_z * diff_z + diff_w * diff_w;
}

float vector4::dot(const vector4& other) const {
	return x * other.x + y * other.y + z * other.z + w * other.w;
}

float vector4::angle_between(const vector4& other) const {
	// normalise the vectors
	const auto a = normalised();
	const auto b = other.normalised();
	// calculate the dot product
	float d = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	// return the angle between them
	return acos(d);
}