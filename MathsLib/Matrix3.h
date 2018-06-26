#ifndef _MATRIX3_H_
#define _MATRIX3_H_
#include "Vector3.h"

class matrix3
{
public:
	matrix3();
	~matrix3();
	union {
		struct {
			vector3 x_axis;
			vector3 y_axis;
			vector3 z_axis;
		};
		vector3 axis[3];
		float data[3][3];
	};

	vector3& operator[](int index);
	const vector3& operator[](int index) const;
	matrix3 operator*(const matrix3& other) const;
	vector3 operator*(const vector3& v) const;
};

#endif