#ifndef _MATRIX2_H_
#define _MATRIX2_H_
#include "Vector2.h"

class matrix2
{
public:
	matrix2();
	~matrix2();
	
	union {
		struct {
			vector2 x_axis;
			vector2 y_axis;
		};
		vector2 axis[2];
		float data[2][2];
	};

	vector2& operator[](int index);
	const vector2& operator[](int index) const;
};

#endif
