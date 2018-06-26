#ifndef _MATRIX4_H_
#define _MATRIX4_H_
#include "Vector4.h"

class matrix4
{
public:
	matrix4();
	~matrix4();
	union {
		struct {
			vector4 x_axis;
			vector4 y_axis;
			vector4 z_axis;
			vector4 w_axis;
		};
		vector4 axis[4];
		float data[4][4];
	};
	vector4& operator[](int index);
	const vector4& operator[](int index) const;
};

#endif
