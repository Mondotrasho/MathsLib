#ifndef _VECTOR_4_
#define _VECTOR_4_

class vector4 {
public:
	//DEFUALT CONSTRUCTORS
	vector4() = default;
	~vector4() = default;
	//ALTERNATIVE  CONSTRUCTORS
	//copy
	vector4(const vector4 &vector) : x(vector.x), y(vector.y), z(vector.z), w(vector.w) {}
	//defined
	vector4(float xval, float yval, float zval, float wval) :x(xval), y(yval), z(zval), w(wval){}

	//UNION
	union {
		//struct as xyz accessable with . operator
		struct {
			float x, y, z, w;
		};
		//array accessable with [] operator
		float data[4]{}; 
	};

	//OPERATORS
	float operator[](int index) const; //getter
	float& operator[](int index);      //setter

	vector4 operator+(const vector4& other) const;
	vector4& operator+=(vector4& other);
	vector4 operator-(const vector4& other) const;
	vector4& operator-=(vector4& other);

	vector4 operator*(float scalar) const;
	vector4& operator*=(float scalar);
	vector4 operator/( float scalar) const;
	vector4& operator/=(float scalar);

	vector4& operator=(const vector4& other);

	//STANDARD OPERATIONS
	void zero();
	vector4 invert() const;
	float magnitude() const;
	float magnitude_sqr() const; //squared
	void normalise(); //Normalise me
	vector4 normalised() const; //Make a new me thats normalised
	float distance(const vector4& other) const;
	float dot(const vector4& other) const;
	float angle_between(const vector4& other) const;
};
#endif
