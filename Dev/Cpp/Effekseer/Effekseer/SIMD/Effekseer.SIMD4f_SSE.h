
#ifndef __EFFEKSEER_SIMD4F_SSE_H__
#define __EFFEKSEER_SIMD4F_SSE_H__

#include <emmintrin.h>

namespace Effekseer
{

/**
	@brief	simd class for sse
*/

struct alignas(16) SIMD4f
{
	union {
		__m128 s;
		float f[4];
	};

	float GetX() const { return f[0]; }
	float GetY() const { return f[1]; }
	float GetZ() const { return f[2]; }
	float GetW() const { return f[3]; }

	void SetX(float o) { f[0] = o; }
	void SetY(float o) { f[1] = o; }
	void SetZ(float o) { f[2] = o; }
	void SetW(float o) { f[3] = o; }

	SIMD4f operator+(const SIMD4f& o) const { return SIMD4f{_mm_add_ps(s, o.s)}; }
};

} // namespace Effekseer

#endif // __EFFEKSEER_SIMD4F_SSE_H__