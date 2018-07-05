#ifndef _MATRIX4_H_
#define _MATRIX4_H_
#include "Vector4.h"

class matrix4
{
public:
	matrix4();
	~matrix4();
	matrix4(const matrix4& matrix);
	matrix4(const vector4& new_x_ax, const vector4& new_y_ax, const vector4& new_z_ax, const vector4& new_w_ax);
	matrix4(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l,
	        float m, float n, float o, float p);

	union {
		struct {
			vector4 x_axis;
			vector4 y_axis;
			vector4 z_axis;
			union {
				vector4 w_axis;
				vector4 t_axis;
			};
		};
		vector4 axis[4];
		float data_alt[16];
		float data[4][4];
	};

	vector4& operator[](int index);
	const vector4& operator[](int index) const;
	matrix4 operator*(const matrix4& other) const;
	vector4 operator*(const vector4& v) const;
};

#endif
