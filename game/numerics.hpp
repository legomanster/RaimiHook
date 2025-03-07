#pragma once

#include <math.h>

/// <summary>
/// 3D vector struct
/// </summary>
struct vector3d
{
	float x, y, z;

	/// <summary>
	/// Gets the distance between two points
	/// </summary>
	/// <param name="a">Point A</param>
	/// <param name="b">Point B</param>
	/// <returns>The distance between the two points</returns>
	static inline float distance(const vector3d& a, const vector3d& b)
	{
		const float x = a.x - b.x;
		const float y = a.y - b.y;
		const float z = a.z - b.z;
		return sqrtf((x * x) + (y * y) + (z * z));
	}
};

inline static vector3d operator + (const vector3d& a, const vector3d& b)
{
	const float x = a.x + b.x;
	const float y = a.y + b.y;
	const float z = a.z + b.z;
	return vector3d({ x, y, z });
}

inline static vector3d operator * (const vector3d& v, const float& f)
{
	const float x = v.x * f;
	const float y = v.y * f;
	const float z = v.z * f;
	return vector3d({ x, y, z });
}