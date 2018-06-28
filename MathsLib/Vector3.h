#ifndef _VECTOR3_H_
#define _VECTOR3_H_

class vector3 {
public:
	//DEFUALT CONSTRUCTORS
	vector3();
	~vector3();
	//ALTERNATIVE  CONSTRUCTORS
	//Copy
	vector3(const vector3& vector);
	//defined
	//vector3(const float a, const float b, const float c);
	vector3(float xval, float yval, float zval);

	//UNION
	union {
		//struct as xyz accessable with . operator
		struct {
			float x, y, z;
			union {
				float z, w;
			};
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

	vector3 operator+(const vector3& other) const;
	vector3 operator+(float other) const;
	vector3& operator+=(const vector3& other);
	vector3 operator-(const vector3& other) const;
	vector3 operator-(float other) const;
	vector3& operator-=(const vector3& other);

	vector3 operator*(float scalar) const;
	vector3& operator*=(float scalar);
	vector3 operator/(float scalar) const;
	vector3& operator/=(float scalar);

	vector3& operator=(const vector3& other);

	//STANDARD OPERATIONS
	void zero();
	vector3 invert() const;
	float magnitude() const;
	float magnitude_sqr() const; //squared
	void normalise(); //Normalise me
	vector3 normalised() const; //Make a new me thats normalised
	float distance(const vector3& other) const;
	float distance_sqr(const vector3& other) const;
	float dot(const vector3& other) const;
	vector3 cross(const vector3& other) const;
	float angle_between(const vector3& other) const;
};
#endif
