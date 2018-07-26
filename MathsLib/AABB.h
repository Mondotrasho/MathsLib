// simple axis-aligned bounding box that stores min/max
#include "Vector2.h"
#include <vector>
#include "Utilities.h"

class AABB {
public:
	AABB() {}
	AABB(const Vector2& min, const Vector2& max)
		: min(min), max(max) {}

	Vector2 center() const;
	Vector2 extents() const;
	std::vector<Vector2> corners() const;
	void fit(const Vector2* points, unsigned count);
	void fit(const std::vector<Vector2>& points);
	bool overlaps(const Vector2& p) const;
	bool overlaps(const AABB& other) const;
	Vector2 closestPoint(const Vector2& p) const;
	Vector2 min, max;
	
};
