#ifndef _Vector4_H_
#define _Vector4_H_




class Vector4 {
public:
	//DEFUALT CONSTRUCTORS
	Vector4();
	~Vector4();
	//ALTERNATIVE  CONSTRUCTORS
	//copy
	Vector4(const Vector4& Vector);
	//defined
	Vector4(float xval, float yval, float zval, float wval);

	//UNION
	union {
		//struct as xyz accessable with . operator
		struct {
			float x, y, z;
			union {
				float w;
				float t;
			};
		};
		//array accessable with [] operator
		float data[4]; 
	};

	//OPERATORS
	float operator[](int index) const; //getter
	float& operator[](int index);      //setter

	Vector4 operator+(const Vector4& other) const;
	Vector4 operator+(const float other) const;
	Vector4& operator+=(Vector4& other);
	Vector4 operator-(const Vector4& other) const;
	Vector4 operator-(const float other) const;
	Vector4& operator-=(Vector4& other);



	Vector4 operator*(float scalar) const;
	Vector4& operator*=(float scalar);
	Vector4 operator/( float scalar) const;
	Vector4& operator/=(float scalar);

	Vector4& operator=(const Vector4& other);

	//STANDARD OPERATIONS
	void zero();
	Vector4 invert() const;
	float magnitude() const;
	float magnitude_sqr() const; //squared
	void normalise(); //Normalise me
	Vector4 normalised() const; //Make a new me thats normalised
	float distance(const Vector4& other) const;
	float distance_sqr(const Vector4& other) const;
	float dot(const Vector4& other) const;
	float angle_between(const Vector4& other) const;
	Vector4 cross(const Vector4& other) const;

	operator float*() { return data; }
};
#endif
