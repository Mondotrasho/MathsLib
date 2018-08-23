#ifndef _VECTOR2_H_
#define _VECTOR2_H_

class Vector2 {
public:
	//DEFUALT CONSTRUCTORS
	Vector2();
	~Vector2();
	//ALTERNATIVE  CONSTRUCTORS
	//Copy
	Vector2(const Vector2& Vector);
	//defined
	Vector2(float xval, float yval);
	Vector2& operator+=(const float& other);
	Vector2& operator-=(const float& other);

	//UNION
	union {
		//struct as xyz accessable with . operator
		struct {
			float x, y;
		};
		struct {
			float Min, Max;
		};
		//array accessable with [] operator
		float data[2] ; 
	};
	
	//OPERATORS
	float operator[](int index) const; //getter
	float& operator[](int index);      //setter

	Vector2 operator+(const Vector2& other) const;
	Vector2 operator+(float other) const;
	Vector2& operator+=(const Vector2& other);
	Vector2 operator-(const Vector2& other) const;
	Vector2 operator-(float other) const;
	Vector2& operator-=(const Vector2& other);

	Vector2 operator*(float scalar) const;
	Vector2& operator*=(float scalar);
	Vector2 operator/(float scalar) const;
	Vector2& operator/=(float scalar);

	Vector2& operator=(const Vector2& other);

	//STANDARD OPERATIONS
	void zero();
	Vector2 invert() const;
	float magnitude() const;
	float magnitude_sqr() const; //squared
	void normalise(); //Normalise me
	Vector2 normalised() const; //Make a new me thats normalised
	float distance(const Vector2& other) const;
	float distance_sqr(const Vector2& other) const;
	float dot(const Vector2& other) const;
	Vector2 get_perpendicular_rh() const;
	Vector2 get_perpendicular_lh() const;
	float angle_between(const Vector2& other) const;
};

Vector2& operator*(const float& lhs, const Vector2& rhs);
#endif