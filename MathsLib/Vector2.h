#ifndef _VECTOR_2_
#define _VECTOR_2_

class vector2 {
public:
	vector2() = default;
	~vector2() = default;
	//Copy
	vector2(const vector2 &vector): x(vector.x), y(vector.y){}

	union {
		//struct as xyz accessable with . operator
		struct {
			float x, y;
		};
		//array accessable with [] operator
		float data[2]{}; // NOTE IDK WHAT THE {} DO HERE !!!!!!
	};

	float operator[](int index) const; //getter
	float& operator[](int index);      //setter
	vector2 operator+(const vector2& other) const;
	vector2& operator+=(const vector2& other);
	vector2 operator-(const vector2& other) const;
	vector2& operator-=(const vector2& other);

	vector2 operator*(float scalar) const;
	vector2& operator*=(float scalar);
	vector2 operator/(float scalar) const;
	vector2& operator/=(float scalar);

	vector2& operator=(const vector2& other);
};
#endif
#pragma once
