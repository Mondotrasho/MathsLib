#ifndef _MATRIX3_H_
#define _MATRIX3_H_
#include "Vector3.h"

class matrix3
{
public:
	matrix3();
	~matrix3();
	//Copy
	matrix3(const matrix3& matrix);
	//defined
	matrix3(const vector3& new_x_ax, const vector3& new_y_ax, const vector3& new_z_ax);
	matrix3(const float a, const float b, const float c, const float d, const float e, const float f, const float g, const float h,const float i);
	union {
		struct {
			vector3 x_axis;
			vector3 y_axis;
			//vector3 z_axis;	
			union {
				vector3 z_axis;
				vector3 t_axis;
			};

		};
		vector3 axis[3];
		float data_alt[9];
		float data[3][3];
	};

	static const matrix3 identity;

	vector3& operator[](int index);
	const vector3& operator[](int index) const;
	matrix3 operator*(const matrix3& other) const;
	vector3 operator*(const vector3& v) const;
	matrix3& operator=(const matrix3&);


	matrix3 transposed() const;
	void set_element(int r, int c, int e);
	int get_element(int r, int c);
	void set_column(int c, vector3& vec);
	vector3 get_column(int c);
	void set_row(int r, vector3& vec);
	vector3 get_row(int r);
	matrix3& operator+=(const matrix3& m);
	matrix3& operator-=(const matrix3& m);
	void set_scaled(float x, float y, float z);
	void set_scaled(const vector3& v);
	void scale(float x, float y, float z);
	void scale(const vector3& v);
	void rotate_y(float radians);
	void set_rotate_z(float radians);
	void rotate_z(float radians);
	void set_rotate_x(float radians);
	void rotate_x(float radians);
	void set_rotate_y(float radians);
	void set_euler(float pitch, float yaw, float roll);
};

#endif