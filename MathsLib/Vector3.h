#ifndef _Vector3_H_
#define _Vector3_H_

class Vector3 {
public:
	//DEFUALT CONSTRUCTORS
	Vector3();
	~Vector3();
	//ALTERNATIVE  CONSTRUCTORS
	//Copy
	Vector3(const Vector3& Vector);
	//defined
	//Vector3(const float a, const float b, const float c);
	Vector3(float xval, float yval, float zval);

	//UNION
	union {
		//struct as xyz accessable with . operator
		struct {
			float x;
			float y;
			union {
				float z;
				float t;
			};
		};
		struct {
			float position, velocity, acceleration;
		};
		struct {
			float R, G, B;
		};
		//array accessable with [] operator
		float data[3] ; 
	};
	
	//OPERATORS
	float operator[](int index) const; //getter
	float& operator[](int index);      //setter

	Vector3 operator+(const Vector3& other) const;
	Vector3 operator+(float other) const;
	Vector3& operator+=(const Vector3& other);
	Vector3 operator-(const Vector3& other) const;
	Vector3 operator-(float other) const;
	Vector3& operator-=(const Vector3& other);

	Vector3 operator*(float scalar) const;
	Vector3& operator*=(float scalar);
	Vector3 operator/(float scalar) const;
	Vector3& operator/=(float scalar);

	Vector3& operator=(const Vector3& other);

	//STANDARD OPERATIONS
	void zero();
	Vector3 invert() const;
	float magnitude() const;
	float magnitude_sqr() const; //squared
	void normalise(); //Normalise me
	Vector3 normalised() const; //Make a new me thats normalised
	float distance(const Vector3& other) const;
	float distance_sqr(const Vector3& other) const;
	float dot(const Vector3& other) const;
	Vector3 cross(const Vector3& other) const;
	float angle_between(const Vector3& other) const;
};
#endif
