#ifndef _Matrix3_H_
#define _Matrix3_H_
#include "Vector3.h"

class Matrix3
{
public:
	Matrix3();
	~Matrix3();
	//Copy
	Matrix3(const Matrix3& Matrix);
	//defined
	Matrix3(const Vector3& new_x_ax, const Vector3& new_y_ax, const Vector3& new_z_ax);
	Matrix3(const float a, const float b, const float c, const float d, const float e, const float f, const float g, const float h,const float i);
	union {
		struct {
			Vector3 x_axis;
			Vector3 y_axis;
			//Vector3 z_axis;	
			union {
				Vector3 z_axis;
				Vector3 t_axis;
			};

		};
		Vector3 axis[3];
		float data_alt[9];
		float data[3][3];
	};

	static const Matrix3 identity;

	Vector3& operator[](int index);
	const Vector3& operator[](int index) const;
	Matrix3 operator*(const Matrix3& other) const;
	Vector3 operator*(const Vector3& v) const;
	Matrix3& operator=(const Matrix3&);


	Matrix3 transposed() const;
	void set_element(int r, int c, int e);
	int get_element(int r, int c);
	void set_column(int c, Vector3& vec);
	Vector3 get_column(int c);
	void set_row(int r, Vector3& vec);
	Vector3 get_row(int r);
	Matrix3& operator+=(const Matrix3& m);
	Matrix3& operator-=(const Matrix3& m);
	void set_scaled(float x, float y, float z);
	void set_scaled(const Vector3& v);
	void scale(float x, float y, float z);
	void scale(const Vector3& v);
	void scale(const Matrix3& v);
	void rotate_y(float radians);
	void set_rotate_z(float radians);
	void rotate_z(float radians);
	void set_rotate_x(float radians);
	void rotate_x(float radians);
	void set_rotate_y(float radians);
	void set_euler(float pitch, float yaw, float roll);
};

#endif