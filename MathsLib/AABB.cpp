#include "AABB.h"


Vector2 AABB::center() const {
	return (min + max) * 0.5f;
}
Vector2 AABB::extents() const {
	return{ abs(max.x - min.x) * 0.5f,
		abs(max.y - min.y) * 0.5f };
}std::vector<Vector2> AABB::corners() const {
	std::vector<Vector2> corners(4);
	corners[0] = min;
	corners[1] = { min.x, max.y };
	corners[2] = max;
	corners[3] = { max.x, min.y };
	return corners;
}
void AABB::fit(const Vector2* points, unsigned int count) {
	// invalidate the extents
	min = { FLT_MAX, FLT_MAX };
	max = { FLT_MIN, FLT_MIN };
	// find min and max of the points
	for (unsigned int i = 0;
		i < count;
		++i, ++points) {
		min = ::min(min, *points);
		max = ::max(max, *points);
	}
}
void AABB::fit(const std::vector<Vector2>& points) {
	// invalidate the extents
	min = { FLT_MAX, FLT_MAX };
	max = { FLT_MIN, FLT_MIN };
	// find min and max of the points
	for (auto& p : points) {
		min = ::min(min, p);
		max = ::max(max, p);
	}
}
bool AABB::overlaps(const Vector2& p) const {
	// test for not overlapped as it exits faster
	return !(p.x < min.x || p.y < min.y ||
		p.x > max.x || p.y > max.y);
}
bool AABB::overlaps(const AABB& other) const {
	// test for not overlapped as it exits faster
	return !(max.x < other.min.x || max.y < other.min.y ||
		min.x > other.max.x || min.y > other.max.y);
}
Vector2 AABB::closestPoint(const Vector2& p) const {
	return clamp(p, min, max);
}

