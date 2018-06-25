#ifndef _VECTOR_3_
#define _VECTOR_3_

class vector3 {
public:
	vector3() = default;
	~vector3()=default;
	//Copy
	vector3(const vector3 &vector) : x(vector.x), y(vector.y), z(vector.z) {}

	union {
		//struct as xyz accessable with . operator
		struct {
			float x, y, z;
		};
		struct {
			float R{}, G{}, B{}; //IDK WHY {}!!!!!!
		};
		//array accessable with [] operator
		float data[3]{}; //idk WHY {}!!!!!!
	};

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
};
#endif
