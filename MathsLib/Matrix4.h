#ifndef _Matrix4_H_
#define _Matrix4_H_
#include "Vector4.h"
#include "Vector3.h"

class Matrix4
{
public:
	Matrix4();
	~Matrix4();
	Matrix4(const Matrix4& Matrix);
	Matrix4(const Vector4& new_x_ax, const Vector4& new_y_ax, const Vector4& new_z_ax, const Vector4& new_w_ax);
	Matrix4(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l,
	        float m, float n, float o, float p);
	static const Matrix4 identity;

	union {
		struct {
			Vector4 x_axis;
			Vector4 y_axis;
			Vector4 z_axis;
			Vector4 translation;
		
		};
		Vector4 axis[4];
		float data_alt[16];
		float data[4][4];
	};

	Vector4& operator[](int index);
	const Vector4& operator[](int index) const;
	Matrix4 operator*(const Matrix4& other) const;
	Vector4 operator*(const Vector4& v) const;
	Matrix4& operator=(const Matrix4& other);


	Matrix4 transposed() const;
	void setScaled(float x, float y, float z);
	void set_rotate_x(float radians);
	void rotate_x(float radians);
	void set_rotate_y(float radians);
	void rotate_y(float radians);
	void set_rotate_z(float radians);
	void rotate_z(float radians);
	void set_euler(float pitch, float yaw, float roll);
	void translate(float x, float y, float z);

	operator float*() { return data_alt; }
};

#endif
