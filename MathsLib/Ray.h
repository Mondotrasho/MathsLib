#ifndef _RAY_H_
#define _RAY_H_
#include "Vector2.h"
#include <cmath>
#include "Sphere.h"
#include "Plane.h"

// ray where direction should be normalised
class Ray {
public:
	Ray() {}
	// default infinite length
	Ray(const Vector2& start,const Vector2& dir,float l = INFINITY)	: origin(start), direction(dir), length(l) {}

	Vector2 closestPoint(const Vector2& point) const;
	bool intersects(const Sphere& sphere, Vector2* I, Vector2* R) const;
	bool intersects(const Plane& plane, Vector2* I, Vector2* R) const;
	bool intersects(const AABB& aabb, Vector2* I, Vector2* R) const;
	Vector2 origin;
	Vector2 direction;
	float length;
	
};
#endif
