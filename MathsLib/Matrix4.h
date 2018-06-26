#ifndef _MATRIX4_H_
#define _MATRIX4_H_
#include "Vector3.h"

class matrix4
{
public:
	matrix4();
	~matrix4();
	matrix4(const matrix4& matrix);
	matrix4(const vector3& new_x_ax, const vector3& new_y_ax, const vector3& new_z_ax, const vector3& new_w_ax);
	matrix4(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l,
	        float m, float n, float o, float p);

	union {
		struct {
			vector3 x_axis;
			vector3 y_axis;
			vector3 z_axis;
			vector3 w_axis;
		};
		vector3 axis[4];
		float data[4][4];
	};

	vector3& operator[](int index);
	const vector3& operator[](int index) const;
};

#endif
