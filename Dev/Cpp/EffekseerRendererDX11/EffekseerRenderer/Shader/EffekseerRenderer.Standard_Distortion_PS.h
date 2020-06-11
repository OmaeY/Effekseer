#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//
//   fxc /Zpc /Tps_4_0 /EPS /D __EFFEKSEER_BUILD_VERSION16__=1 /Fh
//    Shader/EffekseerRenderer.Standard_Distortion_PS.h
//    Shader/standard_renderer_distortion_PS.fx
//
//
// Buffer Definitions: 
//
// cbuffer PS_ConstanBuffer
// {
//
//   float4 g_scale;                    // Offset:    0 Size:    16
//   float4 mUVInversedBack;            // Offset:   16 Size:    16
//   float4 flipbookParameter;          // Offset:   32 Size:    16
//   float4 uvDistortionParameter;      // Offset:   48 Size:    16
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// g_sampler                         sampler      NA          NA    0        1
// g_backSampler                     sampler      NA          NA    1        1
// g_alphaSampler                    sampler      NA          NA    2        1
// g_uvDistortionSampler             sampler      NA          NA    3        1
// g_texture                         texture  float4          2d    0        1
// g_backTexture                     texture  float4          2d    1        1
// g_alphaTexture                    texture  float4          2d    2        1
// g_uvDistortionTexture             texture  float4          2d    3        1
// PS_ConstanBuffer                  cbuffer      NA          NA    0        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_POSITION              0   xyzw        0      POS  float       
// COLOR                    0   xyzw        1     NONE  float   xy w
// TEXCOORD                 0   xy          2     NONE  float   xy  
// TEXCOORD                 4     zw        2     NONE  float     zw
// TEXCOORD                 1   xyzw        3     NONE  float   xy w
// TEXCOORD                 2   xyzw        4     NONE  float   xy w
// TEXCOORD                 3   xyzw        5     NONE  float   xy w
// TEXCOORD                 5   xy          6     NONE  float   xy  
// TEXCOORD                 6     z         6     NONE  float     z 
// TEXCOORD                 7   xy          7     NONE  float   xy  
// TEXCOORD                 8     z         7     NONE  float     z 
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_Target                0   xyzw        0   TARGET  float   xyzw
//
ps_4_0
dcl_constantbuffer cb0[4], immediateIndexed
dcl_sampler s0, mode_default
dcl_sampler s1, mode_default
dcl_sampler s2, mode_default
dcl_sampler s3, mode_default
dcl_resource_texture2d (float,float,float,float) t0
dcl_resource_texture2d (float,float,float,float) t1
dcl_resource_texture2d (float,float,float,float) t2
dcl_resource_texture2d (float,float,float,float) t3
dcl_input_ps linear v1.xyw
dcl_input_ps linear v2.xy
dcl_input_ps linear v2.zw
dcl_input_ps linear v3.xyw
dcl_input_ps linear v4.xyw
dcl_input_ps linear v5.xyw
dcl_input_ps linear v6.xy
dcl_input_ps linear v6.z
dcl_input_ps linear v7.xy
dcl_input_ps linear v7.z
dcl_output o0.xyzw
dcl_temps 3
sample r0.xyzw, v6.xyxx, t3.xyzw, s3
mad r0.xy, r0.xyxx, l(2.000000, 2.000000, 0.000000, 0.000000), l(-1.000000, -1.000000, 0.000000, 0.000000)
mul r0.xy, r0.xyxx, cb0[3].xxxx
resinfo r1.xyzw, l(0), t0.xyzw
div r0.zw, l(1.000000, 1.000000, 1.000000, 1.000000), r1.xxxy
mad r1.xy, r0.xyxx, r0.zwzz, v2.xyxx
sample r1.xyzw, r1.xyxx, t0.xyzw, s0
mul r1.z, r1.w, v1.w
lt r1.w, l(0.000000), cb0[2].x
if_nz r1.w
  mad r0.zw, r0.xxxy, r0.zzzw, v7.xxxy
  sample r2.xyzw, r0.zwzz, t0.xyzw, s0
  eq r0.z, cb0[2].y, l(1.000000)
  mad r2.xyz, r2.xywx, v1.xywx, -r1.xyzx
  mad r2.xyz, v6.zzzz, r2.xyzx, r1.xyzx
  movc r1.xyz, r0.zzzz, r2.xyzx, r1.xyzx
endif 
resinfo r2.xyzw, l(0), t2.xyzw
div r0.zw, l(1.000000, 1.000000, 1.000000, 1.000000), r2.xxxy
mad r0.xy, r0.xyxx, r0.zwzz, v2.zwzz
sample r0.xyzw, r0.xyxx, t2.xyzw, s2
mul r0.x, r0.w, r1.z
ge r0.y, v7.z, r0.x
discard r0.y
eq r0.y, r0.x, l(0.000000)
discard r0.y
div r0.yz, v3.xxyx, v3.wwww
div r1.zw, v4.xxxy, v4.wwww
div r2.xy, v5.xyxx, v5.wwww
mad r1.xy, r1.xyxx, l(2.000000, 2.000000, 0.000000, 0.000000), l(-1.000000, -1.000000, 0.000000, 0.000000)
mul r1.xy, r1.xyxx, v1.xyxx
mul r1.xy, r1.xyxx, cb0[0].xxxx
add r2.xy, -r0.yzyy, r2.xyxx
mad r2.xy, r2.xyxx, r1.xxxx, r0.yzyy
add r0.yz, -r0.yyzy, r1.zzwz
mad r0.yz, r0.yyzy, r1.yyyy, r2.xxyx
add r0.yz, r0.yyzy, l(0.000000, 1.000000, 1.000000, 0.000000)
mul r1.x, r0.y, l(0.500000)
mad r0.y, -r0.z, l(0.500000), l(1.000000)
mad r1.z, cb0[1].y, r0.y, cb0[1].x
sample r1.xyzw, r1.xzxx, t1.xyzw, s1
mov o0.xyz, r1.xyzx
mov o0.w, r0.x
ret 
// Approximately 44 instruction slots used
#endif

const BYTE g_PS[] =
{
     68,  88,  66,  67, 221,  33, 
    208, 170, 129, 102, 124, 165, 
      3, 115, 142, 163, 238, 142, 
     94,  69,   1,   0,   0,   0, 
    100,  11,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
      0,   3,   0,   0,  52,   4, 
      0,   0, 104,   4,   0,   0, 
    232,  10,   0,   0,  82,  68, 
     69,  70, 196,   2,   0,   0, 
      1,   0,   0,   0, 200,   1, 
      0,   0,   9,   0,   0,   0, 
     28,   0,   0,   0,   0,   4, 
    255, 255,  16,   1,   0,   0, 
    144,   2,   0,   0,  60,   1, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     70,   1,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,  84,   1,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,  99,   1, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
    121,   1,   0,   0,   2,   0, 
      0,   0,   5,   0,   0,   0, 
      4,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
      1,   0,   0,   0,  13,   0, 
      0,   0, 131,   1,   0,   0, 
      2,   0,   0,   0,   5,   0, 
      0,   0,   4,   0,   0,   0, 
    255, 255, 255, 255,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     13,   0,   0,   0, 145,   1, 
      0,   0,   2,   0,   0,   0, 
      5,   0,   0,   0,   4,   0, 
      0,   0, 255, 255, 255, 255, 
      2,   0,   0,   0,   1,   0, 
      0,   0,  13,   0,   0,   0, 
    160,   1,   0,   0,   2,   0, 
      0,   0,   5,   0,   0,   0, 
      4,   0,   0,   0, 255, 255, 
    255, 255,   3,   0,   0,   0, 
      1,   0,   0,   0,  13,   0, 
      0,   0, 182,   1,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0, 103,  95, 
    115,  97, 109, 112, 108, 101, 
    114,   0, 103,  95,  98,  97, 
     99, 107,  83,  97, 109, 112, 
    108, 101, 114,   0, 103,  95, 
     97, 108, 112, 104,  97,  83, 
     97, 109, 112, 108, 101, 114, 
      0, 103,  95, 117, 118,  68, 
    105, 115, 116, 111, 114, 116, 
    105, 111, 110,  83,  97, 109, 
    112, 108, 101, 114,   0, 103, 
     95, 116, 101, 120, 116, 117, 
    114, 101,   0, 103,  95,  98, 
     97,  99, 107,  84, 101, 120, 
    116, 117, 114, 101,   0, 103, 
     95,  97, 108, 112, 104,  97, 
     84, 101, 120, 116, 117, 114, 
    101,   0, 103,  95, 117, 118, 
     68, 105, 115, 116, 111, 114, 
    116, 105, 111, 110,  84, 101, 
    120, 116, 117, 114, 101,   0, 
     80,  83,  95,  67, 111, 110, 
    115, 116,  97, 110,  66, 117, 
    102, 102, 101, 114,   0, 171, 
    182,   1,   0,   0,   4,   0, 
      0,   0, 224,   1,   0,   0, 
     64,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     64,   2,   0,   0,   0,   0, 
      0,   0,  16,   0,   0,   0, 
      2,   0,   0,   0,  72,   2, 
      0,   0,   0,   0,   0,   0, 
     88,   2,   0,   0,  16,   0, 
      0,   0,  16,   0,   0,   0, 
      2,   0,   0,   0,  72,   2, 
      0,   0,   0,   0,   0,   0, 
    104,   2,   0,   0,  32,   0, 
      0,   0,  16,   0,   0,   0, 
      2,   0,   0,   0,  72,   2, 
      0,   0,   0,   0,   0,   0, 
    122,   2,   0,   0,  48,   0, 
      0,   0,  16,   0,   0,   0, 
      2,   0,   0,   0,  72,   2, 
      0,   0,   0,   0,   0,   0, 
    103,  95, 115,  99,  97, 108, 
    101,   0,   1,   0,   3,   0, 
      1,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    109,  85,  86,  73, 110, 118, 
    101, 114, 115, 101, 100,  66, 
     97,  99, 107,   0, 102, 108, 
    105, 112,  98, 111, 111, 107, 
     80,  97, 114,  97, 109, 101, 
    116, 101, 114,   0, 117, 118, 
     68, 105, 115, 116, 111, 114, 
    116, 105, 111, 110,  80,  97, 
    114,  97, 109, 101, 116, 101, 
    114,   0,  77, 105,  99, 114, 
    111, 115, 111, 102, 116,  32, 
     40,  82,  41,  32,  72,  76, 
     83,  76,  32,  83, 104,  97, 
    100, 101, 114,  32,  67, 111, 
    109, 112, 105, 108, 101, 114, 
     32,  57,  46,  50,  57,  46, 
     57,  53,  50,  46,  51,  49, 
     49,  49,   0, 171, 171, 171, 
     73,  83,  71,  78,  44,   1, 
      0,   0,  11,   0,   0,   0, 
      8,   0,   0,   0,  16,   1, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
     15,   0,   0,   0,  28,   1, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
     15,  11,   0,   0,  34,   1, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   2,   0,   0,   0, 
      3,   3,   0,   0,  34,   1, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   2,   0,   0,   0, 
     12,  12,   0,   0,  34,   1, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   3,   0,   0,   0, 
     15,  11,   0,   0,  34,   1, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   4,   0,   0,   0, 
     15,  11,   0,   0,  34,   1, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   5,   0,   0,   0, 
     15,  11,   0,   0,  34,   1, 
      0,   0,   5,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   6,   0,   0,   0, 
      3,   3,   0,   0,  34,   1, 
      0,   0,   6,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   6,   0,   0,   0, 
      4,   4,   0,   0,  34,   1, 
      0,   0,   7,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   7,   0,   0,   0, 
      3,   3,   0,   0,  34,   1, 
      0,   0,   8,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   7,   0,   0,   0, 
      4,   4,   0,   0,  83,  86, 
     95,  80,  79,  83,  73,  84, 
     73,  79,  78,   0,  67,  79, 
     76,  79,  82,   0,  84,  69, 
     88,  67,  79,  79,  82,  68, 
      0, 171,  79,  83,  71,  78, 
     44,   0,   0,   0,   1,   0, 
      0,   0,   8,   0,   0,   0, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,  15,   0,   0,   0, 
     83,  86,  95,  84,  97, 114, 
    103, 101, 116,   0, 171, 171, 
     83,  72,  68,  82, 120,   6, 
      0,   0,  64,   0,   0,   0, 
    158,   1,   0,   0,  89,   0, 
      0,   4,  70, 142,  32,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,  90,   0,   0,   3, 
      0,  96,  16,   0,   0,   0, 
      0,   0,  90,   0,   0,   3, 
      0,  96,  16,   0,   1,   0, 
      0,   0,  90,   0,   0,   3, 
      0,  96,  16,   0,   2,   0, 
      0,   0,  90,   0,   0,   3, 
      0,  96,  16,   0,   3,   0, 
      0,   0,  88,  24,   0,   4, 
      0, 112,  16,   0,   0,   0, 
      0,   0,  85,  85,   0,   0, 
     88,  24,   0,   4,   0, 112, 
     16,   0,   1,   0,   0,   0, 
     85,  85,   0,   0,  88,  24, 
      0,   4,   0, 112,  16,   0, 
      2,   0,   0,   0,  85,  85, 
      0,   0,  88,  24,   0,   4, 
      0, 112,  16,   0,   3,   0, 
      0,   0,  85,  85,   0,   0, 
     98,  16,   0,   3, 178,  16, 
     16,   0,   1,   0,   0,   0, 
     98,  16,   0,   3,  50,  16, 
     16,   0,   2,   0,   0,   0, 
     98,  16,   0,   3, 194,  16, 
     16,   0,   2,   0,   0,   0, 
     98,  16,   0,   3, 178,  16, 
     16,   0,   3,   0,   0,   0, 
     98,  16,   0,   3, 178,  16, 
     16,   0,   4,   0,   0,   0, 
     98,  16,   0,   3, 178,  16, 
     16,   0,   5,   0,   0,   0, 
     98,  16,   0,   3,  50,  16, 
     16,   0,   6,   0,   0,   0, 
     98,  16,   0,   3,  66,  16, 
     16,   0,   6,   0,   0,   0, 
     98,  16,   0,   3,  50,  16, 
     16,   0,   7,   0,   0,   0, 
     98,  16,   0,   3,  66,  16, 
     16,   0,   7,   0,   0,   0, 
    101,   0,   0,   3, 242,  32, 
     16,   0,   0,   0,   0,   0, 
    104,   0,   0,   2,   3,   0, 
      0,   0,  69,   0,   0,   9, 
    242,   0,  16,   0,   0,   0, 
      0,   0,  70,  16,  16,   0, 
      6,   0,   0,   0,  70, 126, 
     16,   0,   3,   0,   0,   0, 
      0,  96,  16,   0,   3,   0, 
      0,   0,  50,   0,   0,  15, 
     50,   0,  16,   0,   0,   0, 
      0,   0,  70,   0,  16,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,  64, 
      0,   0,   0,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
    128, 191,   0,   0, 128, 191, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  56,   0,   0,   8, 
     50,   0,  16,   0,   0,   0, 
      0,   0,  70,   0,  16,   0, 
      0,   0,   0,   0,   6, 128, 
     32,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,  61,   0, 
      0,   7, 242,   0,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     70, 126,  16,   0,   0,   0, 
      0,   0,  14,   0,   0,  10, 
    194,   0,  16,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0, 128,  63,   0,   0, 
    128,  63,   0,   0, 128,  63, 
      0,   0, 128,  63,   6,   4, 
     16,   0,   1,   0,   0,   0, 
     50,   0,   0,   9,  50,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   0,  16,   0,   0,   0, 
      0,   0, 230,  10,  16,   0, 
      0,   0,   0,   0,  70,  16, 
     16,   0,   2,   0,   0,   0, 
     69,   0,   0,   9, 242,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   0,  16,   0,   1,   0, 
      0,   0,  70, 126,  16,   0, 
      0,   0,   0,   0,   0,  96, 
     16,   0,   0,   0,   0,   0, 
     56,   0,   0,   7,  66,   0, 
     16,   0,   1,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  58,  16,  16,   0, 
      1,   0,   0,   0,  49,   0, 
      0,   8, 130,   0,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     10, 128,  32,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
     31,   0,   4,   3,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     50,   0,   0,   9, 194,   0, 
     16,   0,   0,   0,   0,   0, 
      6,   4,  16,   0,   0,   0, 
      0,   0, 166,  14,  16,   0, 
      0,   0,   0,   0,   6,  20, 
     16,   0,   7,   0,   0,   0, 
     69,   0,   0,   9, 242,   0, 
     16,   0,   2,   0,   0,   0, 
    230,  10,  16,   0,   0,   0, 
      0,   0,  70, 126,  16,   0, 
      0,   0,   0,   0,   0,  96, 
     16,   0,   0,   0,   0,   0, 
     24,   0,   0,   8,  66,   0, 
     16,   0,   0,   0,   0,   0, 
     26, 128,  32,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
    128,  63,  50,   0,   0,  10, 
    114,   0,  16,   0,   2,   0, 
      0,   0,  70,   3,  16,   0, 
      2,   0,   0,   0,  70,  19, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16, 128,  65,   0, 
      0,   0,   1,   0,   0,   0, 
     50,   0,   0,   9, 114,   0, 
     16,   0,   2,   0,   0,   0, 
    166,  26,  16,   0,   6,   0, 
      0,   0,  70,   2,  16,   0, 
      2,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     55,   0,   0,   9, 114,   0, 
     16,   0,   1,   0,   0,   0, 
    166,  10,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      2,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     21,   0,   0,   1,  61,   0, 
      0,   7, 242,   0,  16,   0, 
      2,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     70, 126,  16,   0,   2,   0, 
      0,   0,  14,   0,   0,  10, 
    194,   0,  16,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0, 128,  63,   0,   0, 
    128,  63,   0,   0, 128,  63, 
      0,   0, 128,  63,   6,   4, 
     16,   0,   2,   0,   0,   0, 
     50,   0,   0,   9,  50,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   0,  16,   0,   0,   0, 
      0,   0, 230,  10,  16,   0, 
      0,   0,   0,   0, 230,  26, 
     16,   0,   2,   0,   0,   0, 
     69,   0,   0,   9, 242,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   0,  16,   0,   0,   0, 
      0,   0,  70, 126,  16,   0, 
      2,   0,   0,   0,   0,  96, 
     16,   0,   2,   0,   0,   0, 
     56,   0,   0,   7,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0,  29,   0, 
      0,   7,  34,   0,  16,   0, 
      0,   0,   0,   0,  42,  16, 
     16,   0,   7,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  13,   0,   4,   3, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  24,   0,   0,   7, 
     34,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     13,   0,   4,   3,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     14,   0,   0,   7,  98,   0, 
     16,   0,   0,   0,   0,   0, 
      6,  17,  16,   0,   3,   0, 
      0,   0, 246,  31,  16,   0, 
      3,   0,   0,   0,  14,   0, 
      0,   7, 194,   0,  16,   0, 
      1,   0,   0,   0,   6,  20, 
     16,   0,   4,   0,   0,   0, 
    246,  31,  16,   0,   4,   0, 
      0,   0,  14,   0,   0,   7, 
     50,   0,  16,   0,   2,   0, 
      0,   0,  70,  16,  16,   0, 
      5,   0,   0,   0, 246,  31, 
     16,   0,   5,   0,   0,   0, 
     50,   0,   0,  15,  50,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   0,  16,   0,   1,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,  64,   0,   0, 
      0,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0, 128, 191, 
      0,   0, 128, 191,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     56,   0,   0,   7,  50,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   0,  16,   0,   1,   0, 
      0,   0,  70,  16,  16,   0, 
      1,   0,   0,   0,  56,   0, 
      0,   8,  50,   0,  16,   0, 
      1,   0,   0,   0,  70,   0, 
     16,   0,   1,   0,   0,   0, 
      6, 128,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   8,  50,   0, 
     16,   0,   2,   0,   0,   0, 
    150,   5,  16, 128,  65,   0, 
      0,   0,   0,   0,   0,   0, 
     70,   0,  16,   0,   2,   0, 
      0,   0,  50,   0,   0,   9, 
     50,   0,  16,   0,   2,   0, 
      0,   0,  70,   0,  16,   0, 
      2,   0,   0,   0,   6,   0, 
     16,   0,   1,   0,   0,   0, 
    150,   5,  16,   0,   0,   0, 
      0,   0,   0,   0,   0,   8, 
     98,   0,  16,   0,   0,   0, 
      0,   0,  86,   6,  16, 128, 
     65,   0,   0,   0,   0,   0, 
      0,   0, 166,  11,  16,   0, 
      1,   0,   0,   0,  50,   0, 
      0,   9,  98,   0,  16,   0, 
      0,   0,   0,   0,  86,   6, 
     16,   0,   0,   0,   0,   0, 
     86,   5,  16,   0,   1,   0, 
      0,   0,   6,   1,  16,   0, 
      2,   0,   0,   0,   0,   0, 
      0,  10,  98,   0,  16,   0, 
      0,   0,   0,   0,  86,   6, 
     16,   0,   0,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0, 128,  63, 
      0,   0, 128,  63,   0,   0, 
      0,   0,  56,   0,   0,   7, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,  63, 
     50,   0,   0,  10,  34,   0, 
     16,   0,   0,   0,   0,   0, 
     42,   0,  16, 128,  65,   0, 
      0,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,  63,   1,  64,   0,   0, 
      0,   0, 128,  63,  50,   0, 
      0,  11,  66,   0,  16,   0, 
      1,   0,   0,   0,  26, 128, 
     32,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     10, 128,  32,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     69,   0,   0,   9, 242,   0, 
     16,   0,   1,   0,   0,   0, 
    134,   0,  16,   0,   1,   0, 
      0,   0,  70, 126,  16,   0, 
      1,   0,   0,   0,   0,  96, 
     16,   0,   1,   0,   0,   0, 
     54,   0,   0,   5, 114,  32, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  54,   0,   0,   5, 
    130,  32,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  62,   0, 
      0,   1,  83,  84,  65,  84, 
    116,   0,   0,   0,  44,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,  11,   0, 
      0,   0,  18,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      5,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   6,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0
};
