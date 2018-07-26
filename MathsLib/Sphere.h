#pragma once
#include "Vector2.h"
#include <vector>
#include "AABB.h"


// simple sphere
class Sphere {
public:
	Sphere() {}
	Sphere(const Vector2& p, float r) : center(p), radius(r) {}
	void fit(const Vector2* points, unsigned count);
	void fit(const std::vector<Vector2>& points);
	bool overlaps(const Vector2& p) const;
	bool overlaps(const Sphere& other) const;
	bool overlaps(const AABB& aabb) const;

	Vector2 closestPoint(const Vector2& p) const;
	Vector2 center;
	float radius;
	// more to come...
};
