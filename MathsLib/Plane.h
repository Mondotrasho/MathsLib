#pragma once
#include "Vector2.h"
#include "Vector3.h"
#include "Sphere.h"

enum ePlaneResult : int {
	FRONT = 1,
	BACK = -1,
	INTERSECTS = 0
};
// 2D mathematical plane using Ax + By + d = 0
class Plane {
public:
	Plane() {}
	Plane(float x, float y, float d) : N(x, y), d(d) {}
	Plane(const Vector2& n, float d) : N(n), d(d) {}
	Plane(const Vector2& p1, const Vector2& p2) {
		// calculate normalised vector from p0 to p1
		auto v = p2 - p1;
		v.normalise();
		// set normal perpendicular to the vector
		N.x = -v.y;
		N.y = v.x;
		// calculate d
		d = -p1.dot(N);
	}
	Plane(const Vector3& p1,
		const Vector3& p2, const Vector3& p3) {
		// calculate edge vectors
		auto v1 = (p2 - p1).normalised();
		auto v2 = (p3 - p1).normalised();
		// calculate normal
		N = v1.cross(v2);
		// calculate d
		d = -p1.dot(N);
	}

	float distanceTo(const Vector2& p) const;
	Vector2 closestPoint(const Vector2& p) const;
	ePlaneResult testSide(const Vector2& p) const;
	ePlaneResult testSide(const Sphere& sphere) const;
	ePlaneResult testSide(const AABB& aabb) const;

	Vector2 N;
	float d;
	// more to go here...
};