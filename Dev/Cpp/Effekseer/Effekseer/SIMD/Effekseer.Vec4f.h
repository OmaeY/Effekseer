
#ifndef __EFFEKSEER_VEC4F_H__
#define __EFFEKSEER_VEC4F_H__

#if defined(__ARM_NEON__)
#include "Effekseer.SIMD4f_NEON.h"
#elif (defined(_M_IX86_FP) && _M_IX86_FP >= 2) || defined(__SSE__)
#include "Effekseer.SIMD4f_SSE.h"
#else
#include "Effekseer.SIMD4f.h"
#endif

namespace Effekseer
{

struct Vec4f
{
	SIMD4f s;

	float GetX() const { return s.GetX(); }
	float GetY() const { return s.GetY(); }
	float GetZ() const { return s.GetZ(); }
	float GetW() const { return s.GetW(); }

	void SetX(float o) { s.SetX(o); }
	void SetY(float o) { s.SetY(o); }
	void SetZ(float o) { s.SetZ(o); }
	void SetW(float o) { s.SetW(o); }

	Vec4f operator+(const Vec4f& o) const { return Vec4f{this->s + o.s}; }

	Vec4f operator-(const Vec4f& o) const { return Vec4f{this->s - o.s}; }

	Vec4f operator*(const Vec4f& o) const { return Vec4f{this->s * o.s}; }

	Vec4f operator/(const Vec4f& o) const { return Vec4f{this->s / o.s}; }
};

inline Vec4f sqrt(const Vec4f& o) { return Vec4f{o.s}; }

} // namespace Effekseer

#endif // __EFFEKSEER_VEC4F_H__