#ifndef _VECTOR_2_
#define _VECTOR_2_

class vector2 {
public:
	//DEFUALT CONSTRUCTORS
	vector2() = default;
	~vector2() = default;
	//ALTERNATIVE  CONSTRUCTORS
	//Copy
	vector2(const vector2 &vector) : x(vector.x), y(vector.y) {}
	//defined
	vector2(float xval, float yval) :x(xval), y(yval) {}

	//UNION
	union {
		//struct as xyz accessable with . operator
		struct {
			float x, y;
		};
		//array accessable with [] operator
		float data[2]{}; 
	};
	
	//OPERATORS
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

	//STANDARD OPERATIONS
	void zero();
	vector2 invert() const;
	float magnitude() const;
	float magnitude_sqr() const; //squared
	void normalise(); //Normalise me
	vector2 normalised(vector2) const; //Make a new me thats normalised
	float distance(const vector2& other) const;
	float dot(const vector2& other) const;
	vector2 get_perpendicular_rh() const;
	vector2 get_perpendicular_lh() const;
};
#endif
#pragma once
