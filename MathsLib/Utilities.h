#pragma once
#include "Vector2.h"

// utilities
float min(float a, float b) { return a < b ? a : b; }
float max(float a, float b) { return a > b ? a : b; }
Vector2 min(const Vector2& a, const Vector2& b) {
	return{ min(a.x,b.x), min(a.y, b.y) };
}
Vector2 max(const Vector2& a, const Vector2& b) {
	return{ max(a.x,b.x), max(a.y, b.y) };
}

float clamp(float t, float a, float b) {
	return max(a, min(b, t));
}
Vector2 clamp(const Vector2& t, const Vector2& a, const Vector2& b) {
	return max(a, min(b, t));
}