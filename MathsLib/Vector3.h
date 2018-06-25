#ifndef _VECTOR_3_
#define _VECTOR_3_

class vector3 {
public:
	//DEFUALT CONSTRUCTORS
	vector3() = default;
	~vector3() = default;
	//ALTERNATIVE  CONSTRUCTORS
	//Copy
	vector3(const vector3 &vector) : x(vector.x), y(vector.y), z(vector.z) {}
	//defined
	vector3(float xval, float yval, float zval) :x(xval), y(yval), z(zval) {}	
	
	//UNION
	union {
		//struct as xyz accessable with . operator
		struct {
			float x, y, z;
		};
		struct {
			float R{}, G{}, B{};
		};
		//array accessable with [] operator
		float data[3]{}; 
	};
	
	//OPERATORS
	float operator[](int index) const; //getter
	float& operator[](int index);      //setter

	vector3 operator+(const vector3& other) const;
	vector3& operator+=(const vector3& other);
	vector3 operator-(const vector3& other) const;
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
	vector3 normalised(vector3) const; //Make a new me thats normalised
	float distance(const vector3& other) const;
	float dot(const vector3& other) const;
};
#endif
