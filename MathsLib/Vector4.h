#ifndef _VECTOR_4_
#define _VECTOR_4_

class vector4 {
public:
	vector4() = default;
	~vector4() = default;
	union {
		//struct as xyz accessable with . operator
		struct {
			float x, y, z, w;
		};
		//array accessable with [] operator
		float data[4];
	};

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
};
#endif
