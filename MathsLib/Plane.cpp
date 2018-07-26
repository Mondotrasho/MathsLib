#include "Plane.h"

float Plane::distanceTo(const Vector2& p) const {
	return p.dot(N) + d;
}
Vector2 Plane::closestPoint(const Vector2& p) const {
	return p - N * distanceTo(p);
}
ePlaneResult Plane::testSide(const Vector2& p) const {
	float t = p.dot(N) + d;
	if (t < 0)
		return ePlaneResult::BACK;
	else if (t > 0)
		return ePlaneResult::FRONT;
	return ePlaneResult::INTERSECTS;
}
ePlaneResult Plane::testSide(const Sphere& sphere) const {
	float t = distanceTo(sphere.center);
	if (t > sphere.radius)
		return ePlaneResult::FRONT;
	else if (t < -sphere.radius)
		return ePlaneResult::BACK;
	return ePlaneResult::INTERSECTS;
}ePlaneResult Plane::testSide(const AABB& aabb) const {
	// tag if we find a corner on each side
	bool side[2] = { false, false };
	// compare each corner
	for (auto c : aabb.corners()) {
		auto result = testSide(c);
		if (result == ePlaneResult::FRONT)
			side[0] = true;
		else if (result == ePlaneResult::BACK)
			side[1] = true;
	}
	// if front but not back
	if (side[0] && !side[1])
		return ePlaneResult::FRONT;
	// if back but not front
	else if (!side[0] && side[1])
		return ePlaneResult::BACK;
	// else overlapping
	return ePlaneResult::INTERSECTS;
}