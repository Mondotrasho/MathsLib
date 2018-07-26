#ifndef _UTILITIES_H
#define _UTILITIES_H
#include "Vector2.h"

// utilities
inline float Umin(float a, float b) { return a < b ? a : b; }
inline float Umax(float a, float b) { return a > b ? a : b; }

inline Vector2 Umin(const Vector2& a, const Vector2& b) {
	return{ Umin(a.x,b.x), Umin(a.y, b.y) };
}

inline Vector2 Umax(const Vector2& a, const Vector2& b) {
	return{ Umax(a.x,b.x), Umax(a.y, b.y) };
}

inline float Uclamp(float t, float a, float b) {
	return Umax(a, Umin(b, t));
}

inline Vector2 Uclamp(const Vector2& t, const Vector2& a, const Vector2& b) {
	return Umax(a,Umin(b, t));
}
#endif
