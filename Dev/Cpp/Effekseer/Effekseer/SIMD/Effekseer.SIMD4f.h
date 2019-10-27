
#ifndef __EFFEKSEER_SIMD4F_H__
#define __EFFEKSEER_SIMD4F_H__

namespace Effekseer
{

/**
	@brief	simd class for generic
*/
struct alignas(16) SIMD4f
{
	union {
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

	SIMD4f operator+(const SIMD4f& o) const
	{
		SIMD4f ret;
		for (size_t i = 0; i < 4; i++)
		{
			ret.f[i] = f[i] + o.f[i];
		}
	}
}

} // namespace Effekseer

#endif // __EFFEKSEER_SIMD4F_H__