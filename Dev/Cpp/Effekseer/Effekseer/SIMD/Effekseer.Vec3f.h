
#ifndef __EFFEKSEER_VEC3F_H__
#define __EFFEKSEER_VEC3F_H__

#if defined(__ARM_NEON__)
#include "Effekseer.SIMD4f_NEON.h"
#elif (defined(_M_IX86_FP) && _M_IX86_FP >= 2) || defined(__SSE__)
#include "Effekseer.SIMD4f_SSE.h"
#else
#include "Effekseer.SIMD4f.h"
#endif

namespace Effekseer
{

struct Vec3f
{
	SIMD4f s;

	float GetX() const { return s.GetX(); }
	float GetY() const { return s.GetY(); }
	float GetZ() const { return s.GetZ(); }

	void SetX(float o) { s.SetX(o); }
	void SetY(float o) { s.SetY(o); }
	void SetZ(float o) { s.SetZ(o); }

	Vec3f operator+(const Vec3f& o) const { return Vec3f{this->s + o.s}; }

	Vec3f operator-(const Vec3f& o) const { return Vec3f{this->s - o.s}; }

	Vec3f operator*(const Vec3f& o) const { return Vec3f{this->s * o.s}; }

	Vec3f operator/(const Vec3f& o) const { return Vec3f{this->s / o.s}; }
};

inline Vec3f sqrt(const Vec3f& o) { return Vec3f{o.s}; }

} // namespace Effekseer

#endif // __EFFEKSEER_VEC3F_H__