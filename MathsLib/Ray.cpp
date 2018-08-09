#include "Ray.h"



Vector2 Ray::closestPoint(const Vector2& point) const {
	// ray origin to arbitrary point
	auto p = point - origin;
	// project the point onto the ray and clamp by length
	float t = Uclamp(p.dot(direction), 0, length);
	// return position in direction of ray
	return origin + direction * t;
}
bool Ray::intersects(const Sphere & sphere, Vector2 * I = nullptr, Vector2* R = nullptr) const
{
	// ray origin to sphere center
	auto L = sphere.center - origin;
	// project sphere center onto ray
	float t = L.dot(direction);
	// get sqr distance from sphere center to ray
	float dd = L.dot(L) - t * t;
	// subtract penetration amount from projected distance
	t -= sqrt(sphere.radius * sphere.radius - dd);
	// it intersects if within ray length
	if (t >= 0 && t <= length) {
		// store intersection point if requested
		if (I != nullptr)
			*I = origin + direction * t;
		if (R != nullptr) {
			// get surface normal at intersection point
			auto N = ((origin + direction * t) - sphere.center);
			N /= sphere.radius;
			// get penetration vector
			auto P = direction * (length - t);
			// get penetration amount
			float p = P.dot(N);
			// get reflected vector
			*R = N * -2 * p + P;
		}
		return true;
	}
	// default no intersection
	return false;
}
bool Ray::intersects(const Plane & plane, Vector2 * I = nullptr, Vector2* R = nullptr) const
{
	// project ray direction onto plane normal
	// this should give us a value between -1 and 1
	float t = direction.dot(plane.N);
	// must face the plane
	if (t > 0)
		return false;
	// get distance of ray origin to the plane
	float d = origin.dot(plane.N) + plane.d;
	// check if ray is parallel with the plane
	// no intersection if parallel and not touching
	if (t == 0 && d != 0)
		return false;
	// calculate distance along ray to plane
	t = d == 0 ? 0 : -(d / t);
	// intersects if within range
	if (t >= 0 && t <= length) {
		// store intersection point if requested
		if (I != nullptr)
			*I = origin + direction * t;
		if (R != nullptr) {
			// get penetration vector
			auto P = direction * (length - t);
			// get penetration amount
			float p = P.dot(plane.N);
			// get reflected vector
			*R = plane.N * -2 * p + P;
		}
		return true;

	}
	// default no intersection
	return false;
}
bool Ray::intersects(const AABB & aabb, Vector2 * I = nullptr,	Vector2* R = nullptr) const
{
	// get distances to each axis of the box
	float xmin, xmax, ymin, ymax;
	// get min and max in the x-axis
	if (direction.x < 0) {
		xmin = (aabb.max.x - origin.x) / direction.x;
		xmax = (aabb.min.x - origin.x) / direction.x;
	}
	else {
		xmin = (aabb.min.x - origin.x) / direction.x;
		xmax = (aabb.max.x - origin.x) / direction.x;
	}
	// get min and max in the y-axis
	if (direction.y < 0) {
		ymin = (aabb.max.y - origin.y) / direction.y;
		ymax = (aabb.min.y - origin.y) / direction.y;
	}
	else {
		ymin = (aabb.min.y - origin.y) / direction.y;
		ymax = (aabb.max.y - origin.y) / direction.y;
	}
	// ensure within box
	if (xmin > ymax || ymin > xmax)
		return false;
	// the first contact is the largest of the two min
	float t = Umax(xmin, ymin);
	// intersects if within range
	if (t >= 0 && t <= length) {
		// store intersection point if requested
		if (I != nullptr)
			*I = origin + direction * t;
		if (R != nullptr) {
			// need to determine box side hit
			Vector2 N = {};
			if (t == xmin) {
				// horizontal normal
				if (direction.x < 0)
					// right side
					N = { 1,0 };
				else
					// left side
					N = { -1,0 };
			}
			else {
				// vertical normal
				if (direction.y < 0)
					// top
					N = { 0,1 };
				else
					// bottom
					N = { 0,-1 };
			}
			// get penetration vector
			auto P = direction * (length - t);
			// get penetration amount
			float p = P.dot(N);
			// get reflected vector
			*R = N * -2 * p + P;
		}
		return true;
	}
	// not within Ray's range
	return false;
}
