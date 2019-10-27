
#ifndef __EFFEKSEER_VEC3FBLOCK4_H__
#define __EFFEKSEER_VEC3FBLOCK4_H__

#include "Effekseer.Vec4f.h"

namespace Effekseer
{

struct Vec3fBlock4
{
	Vec4f X;
	Vec4f Y;
	Vec4f Z;

	Vec3fBlock4 operator+(const Vec3fBlock4& o) const
	{
		return Vec3fBlock4{
			this->x + o.x,
			this->y + o.y,
			this->z + o.z,
		};
	}

	Vec3fBlock4 operator-(const Vec3fBlock4& o) const
	{
		return Vec3fBlock4{
			this->x - o.x,
			this->y - o.y,
			this->z - o.z,
		};
	}

	Vec3fBlock4 operator*(const Vec3fBlock4& o) const
	{
		return Vec3fBlock4{
			this->x * o.x,
			this->y * o.y,
			this->z * o.z,
		};
	}

	Vec3fBlock4 operator/(const Vec3fBlock4& o) const
	{
		return Vec3fBlock4{
			this->x / o.x,
			this->y / o.y,
			this->z / o.z,
		};
	}

	static Vec4f Dot(const Vec3fBlock4& lhs, const Vec3fBlock4& rhs) { return sqrt(lhs.X * rhs.X + lhs.Y * rhs.Y + lhs.Z * rhs.Z); }
};

inline Vec3fBlock4 sqrt(const Vec3fBlock4& o)
{
	return Vec3fBlock4{
		sqrt(o.X),
		sqrt(o.Y),
		sqrt(o.Z),
	};
}

} // namespace Effekseer

#endif // __EFFEKSEER_VEC3FBLOCK4_H__