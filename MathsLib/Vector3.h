#ifndef _VECTOR_3_
#define _VECTOR_3_

class Vector3 {
public:
	union {
		//struct as xyz accessable with . operator
		struct {
			float x, y, z;
		};
		//array accessable with [] operator
		float data[3];
	};

	float operator[](int index) const; //getter
	float& operator[](int index);      //setter
	Vector3 operator+(const Vector3& other) const;
	Vector3& operator-=(const Vector3& other);
	Vector3 operator*(float scalar) const;
	Vector3& operator/=(float scalar);
	Vector3& operator=(const Vector3& other);
};
#endif
