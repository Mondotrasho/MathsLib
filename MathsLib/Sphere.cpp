#include "Sphere.h"

void Sphere::fit(const Vector2* points, unsigned int count) {
	// invalidate extents
	Vector2 min = { FLT_MAX, FLT_MAX };
	Vector2 max = { FLT_MIN, FLT_MIN };
	// find min and max of the points
	for (unsigned int i = 0; i < count; ++i, ++points) {
		min = Umin(min, *points);
		max = Umax(max, *points);
	}
	// put a circle around the min/max box
	center = (min + max) * 0.5f;
	radius = center.distance(max);
}
void Sphere::fit(const std::vector<Vector2>& points) {
	// invalidate extents
	Vector2 min = { FLT_MAX, FLT_MAX };
	Vector2 max = { FLT_MIN, FLT_MIN };
	// find min and max of the points
	for (auto& p : points) {
		min = Umin(min, p);
		max = Umax(max, p);
	}
	// put a circle around the min/max box
	center = (min + max) * 0.5f;
	radius = center.distance(max);
}
bool Sphere::overlaps(const Vector2& p) const {
	Vector2 toPoint = p - center;
	return toPoint.magnitude_sqr() <= (radius * radius);
}
bool Sphere::overlaps(const Sphere& other) const {
	Vector2 diff = other.center - center;
	// compare distance between spheres to combined radii
	float r = radius + other.radius;
	return diff.magnitude_sqr() <= (r * r);
}




bool Sphere::overlaps(const ::AABB& aabb) const{
	auto diff = aabb.closestPoint(center) - center;
	return diff.dot(diff) <= (radius * radius);
}
Vector2 Sphere::closestPoint(const Vector2& p) const {
	// distance from center
	Vector2 toPoint = p - center;
	// if outside of radius bring it back to the radius
	if (toPoint.magnitude_sqr() > radius * radius) {
		toPoint = toPoint.normalised() * radius;
	}
	return center + toPoint;
}
