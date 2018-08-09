#ifndef _UTILITIES_H
#define _UTILITIES_H
#include "Vector2.h"
#include <complex>

# define M_PI           3.14159265358979323846  /* pi */
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
namespace Tweening {
	inline Vector2 linearInSineVec2(float t,Vector2 b,Vector2 c,float delta)
	{
		
		return b + c - c * cosf(t / delta * (M_PI / 2));
	}

	inline Vector2 easeOutElasticVec2(float t, const Vector2& b, const Vector2& c, float d) {
		auto s = 1.70158;
		auto p = 0;
		auto a = c;
		if (t == 0) return b;
		if ((t /= d / 2) == 2) return b + c;
		if (!p) p = d * (.3*1.5);
		if (a.x < std::abs(c.x) && a.y < std::abs(c.y))
		{
			a = c;
			s = p / 4;

		}
		else {
			s = p / (2 * M_PI) * std::asin((c.x / a.x) + (c.y / a.y));

		}
		if (t < 1) return Vector2(-.5*(a.x*std::pow(2, 10 * (t -= 1)) * std::sin((t*d - s)*(2 * M_PI) / p)) + b.x, -.5*(a.y*std::pow(2, 10 * (t -= 1)) * std::sin((t*d - s)*(2 * M_PI) / p)) + b.y);
		return Vector2(a.x * std::pow(2, -10 * t) * std::sin((t*d - s)*(2 * M_PI) / p) + c.x + b.x, a.y * std::pow(2, -10 * t) * std::sin((t*d - s)*(2 * M_PI) / p) + c.y + b.y);
	}
	template <typename T>
	T linearEase(float t, const T& b, const T& c, float d) {
		return b + c * (t / d);
	}
	template <typename T>
	T lerp(const T& a, const T& b, float t) {
		return a * (1 - t) + b * t;
	}
	template <typename T>
	T easeInSine(float t, const T& b, const T& c, float d) {
		return b + c - c * cosf(t / d * (M_PI / 2));
	}
	template <typename T>
	T easeOutElastic(float t, const T& b, const T& c, float d) {
		auto s = 1.70158; 
		auto p = 0; 
		auto a = c;
		if (t == 0) return b; 
		if ((t /= d / 2) == 2) return b + c;
		if (!p) p = d * (.3*1.5);
		if (a < std::abs(c))
		{
			a = c; 
			s = p / 4;

		}
		else {
			s = p / (2 * M_PI) * std::asin(c / a);
			
		}
		if (t < 1) return -.5*(a*std::pow(2, 10 * (t -= 1)) * std::sin((t*d - s)*(2 * M_PI) / p)) + b;
		return a * std::pow(2, -10 * t) * std::sin((t*d - s)*(2 * M_PI) / p) + c + b;
	}
	template <typename T>
	T easeOutBounce(float t, const T& b, const T& c, float d) {
		if ((t /= d) < (1 / 2.75)) {
			return c * (7.5625*t*t) + b;
		}
		if (t < (2 / 2.75)) {
			return c * (7.5625*(t -= (1.5 / 2.75))*t + .75) + b;
		}
		if (t < (2.5 / 2.75)) {
			return c * (7.5625*(t -= (2.25 / 2.75))*t + .9375) + b;
		}
		return c * (7.5625*(t -= (2.625 / 2.75))*t + .984375) + b;
	}
	template <typename T>
	T easeInBounce(float t, const T& b, const T& c, float d) {
		return c - easeOutBounce(d - t, 0, c, d) + b;
	}

//
//
}
#endif
