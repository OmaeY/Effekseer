#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//
//   fxc /Zpc /Tvs_4_0 /Emain /Fh ShaderHeader/ad_sprite_distortion_vs.h
//    Shader/ad_sprite_distortion_vs.fx
//
//
// Buffer Definitions: 
//
// cbuffer VS_ConstantBuffer
// {
//
//   float4x4 mCamera;                  // Offset:    0 Size:    64 [unused]
//   float4x4 mCameraProj;              // Offset:   64 Size:    64
//   float4 mUVInversed;                // Offset:  128 Size:    16
//   float4 fFlipbookParameter;         // Offset:  144 Size:    16
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// VS_ConstantBuffer                 cbuffer      NA          NA    0        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// POSITION                 0   xyz         0     NONE  float   xyz 
// NORMAL                   0   xyzw        1     NONE  float   xyzw
// NORMAL                   1   xyzw        2     NONE  float   xyz 
// NORMAL                   2   xyzw        3     NONE  float   xyz 
// TEXCOORD                 0   xy          4     NONE  float   xy  
// TEXCOORD                 1   xy          5     NONE  float       
// TEXCOORD                 2   xyzw        6     NONE  float   xyzw
// TEXCOORD                 3   xy          7     NONE  float   xy  
// TEXCOORD                 4   xyzw        8     NONE  float   xyzw
// TEXCOORD                 5   x           9     NONE  float   x   
// TEXCOORD                 6   x          10     NONE  float   x   
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_POSITION              0   xyzw        0      POS  float   xyzw
// TEXCOORD                 0   xyzw        1     NONE  float   xyzw
// TEXCOORD                 1   xyzw        2     NONE  float   xyzw
// TEXCOORD                 2   xyzw        3     NONE  float   xyzw
// TEXCOORD                 3   xyzw        4     NONE  float   xyzw
// COLOR                    0   xyzw        5     NONE  float   xyzw
// TEXCOORD                 4   xyzw        6     NONE  float   xyzw
// TEXCOORD                 5   xyzw        7     NONE  float   xyzw
// TEXCOORD                 6   xyzw        8     NONE  float   xyzw
//
vs_4_0
dcl_constantbuffer cb0[10], immediateIndexed
dcl_input v0.xyz
dcl_input v1.xyzw
dcl_input v2.xyz
dcl_input v3.xyz
dcl_input v4.xy
dcl_input v6.xyzw
dcl_input v7.xy
dcl_input v8.xyzw
dcl_input v9.x
dcl_input v10.x
dcl_output_siv o0.xyzw, position
dcl_output o1.xyzw
dcl_output o2.xyzw
dcl_output o3.xyzw
dcl_output o4.xyzw
dcl_output o5.xyzw
dcl_output o6.xyzw
dcl_output o7.xyzw
dcl_output o8.xyzw
dcl_temps 8
add r0.xyz, v2.zxyz, l(-0.500000, -0.500000, -0.500000, 0.000000)
add r0.xyz, r0.xyzx, r0.xyzx
add r1.xyz, v3.xyzx, l(-0.500000, -0.500000, -0.500000, 0.000000)
add r2.xyz, r1.xyzx, r1.xyzx
mul r3.xyz, r0.xyzx, r2.yzxy
mad r0.xyz, r0.zxyz, r2.zxyz, -r3.xyzx
mad r2.z, cb0[8].y, v4.y, cb0[8].x
mul r3.xyzw, v0.yyyy, cb0[5].xyzw
mad r3.xyzw, cb0[4].xyzw, v0.xxxx, r3.xyzw
mad r3.xyzw, cb0[6].xyzw, v0.zzzz, r3.xyzw
add r3.xyzw, r3.xyzw, cb0[7].xyzw
mad r1.xyz, r1.xyzx, l(2.000000, 2.000000, 2.000000, 0.000000), v0.xyzx
mul r4.xyzw, r1.yyyy, cb0[5].xyzw
mad r4.xyzw, cb0[4].xyzw, r1.xxxx, r4.xyzw
mad r1.xyzw, cb0[6].xyzw, r1.zzzz, r4.xyzw
add o3.xyzw, r1.xyzw, cb0[7].xyzw
add r0.xyz, r0.xyzx, v0.xyzx
mul r1.xyzw, r0.yyyy, cb0[5].xyzw
mad r1.xyzw, cb0[4].xyzw, r0.xxxx, r1.xyzw
mad r0.xyzw, cb0[6].xyzw, r0.zzzz, r1.xyzw
add o2.xyzw, r0.xyzw, cb0[7].xyzw
mad o6.yw, cb0[8].yyyy, v6.yyyw, cb0[8].xxxx
mad r0.x, cb0[8].y, v7.y, cb0[8].x
mad o7.yw, cb0[8].yyyy, v8.yyyw, cb0[8].xxxx
lt r1.x, l(0.000000), cb0[9].x
if_nz r1.x
  frc r1.x, v9.x
  round_ni r4.x, v9.x
  add r1.y, r4.x, l(1.000000)
  mul r1.z, cb0[9].w, cb0[9].z
  eq r1.w, cb0[9].y, l(0.000000)
  if_nz r1.w
    ge r1.w, r1.y, r1.z
    mad r4.w, cb0[9].z, cb0[9].w, l(-1.000000)
    add r4.y, r4.x, l(1.000000)
    movc r4.yw, r1.wwww, r4.wwww, r4.xxxy
  else 
    eq r1.w, cb0[9].y, l(1.000000)
    if_nz r1.w
      mul r1.w, r1.z, r4.x
      ge r1.w, r1.w, -r1.w
      movc r1.w, r1.w, r1.z, -r1.z
      div r5.x, l(1.000000, 1.000000, 1.000000, 1.000000), r1.w
      mul r5.x, r4.x, r5.x
      frc r5.x, r5.x
      mul r4.y, r1.w, r5.x
      mul r1.w, r1.z, r1.y
      ge r1.w, r1.w, -r1.w
      movc r1.w, r1.w, r1.z, -r1.z
      div r5.x, l(1.000000, 1.000000, 1.000000, 1.000000), r1.w
      mul r5.x, r1.y, r5.x
      frc r5.x, r5.x
      mul r4.w, r1.w, r5.x
    else 
      eq r1.w, cb0[9].y, l(2.000000)
      div r5.x, r4.x, r1.z
      round_ni r5.x, r5.x
      add r5.y, r5.x, r5.x
      ge r5.y, r5.y, -r5.y
      movc r5.yz, r5.yyyy, l(0,2.000000,0.500000,0), l(0,-2.000000,-0.500000,0)
      mul r5.x, r5.z, r5.x
      frc r5.x, r5.x
      mul r5.x, r5.x, r5.y
      eq r5.x, r5.x, l(1.000000)
      mul r5.y, r1.z, r4.x
      ge r5.y, r5.y, -r5.y
      movc r5.y, r5.y, r1.z, -r1.z
      div r5.z, l(1.000000, 1.000000, 1.000000, 1.000000), r5.y
      mul r5.z, r4.x, r5.z
      frc r5.z, r5.z
      mul r5.y, r5.z, r5.y
      mad r5.z, cb0[9].z, cb0[9].w, l(-1.000000)
      round_ni r5.w, r5.y
      add r5.w, -r5.w, r5.z
      movc r5.x, r5.x, r5.w, r5.y
      div r5.w, r1.y, r1.z
      round_ni r5.w, r5.w
      add r6.x, r5.w, r5.w
      ge r6.x, r6.x, -r6.x
      movc r6.xy, r6.xxxx, l(2.000000,0.500000,0,0), l(-2.000000,-0.500000,0,0)
      mul r5.w, r5.w, r6.y
      frc r5.w, r5.w
      mul r5.w, r5.w, r6.x
      eq r5.w, r5.w, l(1.000000)
      mul r6.x, r1.z, r1.y
      ge r6.x, r6.x, -r6.x
      movc r1.z, r6.x, r1.z, -r1.z
      div r6.x, l(1.000000, 1.000000, 1.000000, 1.000000), r1.z
      mul r1.y, r1.y, r6.x
      frc r1.y, r1.y
      mul r1.y, r1.y, r1.z
      round_ni r1.z, r1.y
      add r1.z, -r1.z, r5.z
      movc r5.y, r5.w, r1.z, r1.y
      add r4.z, r4.x, l(1.000000)
      movc r4.yw, r1.wwww, r5.xxxy, r4.xxxz
    endif 
  endif 
  ftoi r1.yz, r4.yywy
  ftoi r1.w, cb0[9].z
  and r4.xy, r1.yzyy, l(0x80000000, 0x80000000, 0, 0)
  imax r4.zw, r1.yyyz, -r1.yyyz
  imax r5.x, r1.w, -r1.w
  udiv r6.x, r7.x, r4.z, r5.x
  ineg r4.z, r7.x
  movc r4.x, r4.x, r4.z, r7.x
  itof r7.x, r4.x
  xor r1.yz, r1.wwww, r1.yyzy
  ineg r1.w, r6.x
  and r1.yz, r1.yyzy, l(0, 0x80000000, 0x80000000, 0)
  movc r1.y, r1.y, r1.w, r6.x
  itof r7.y, r1.y
  div r1.yw, l(1.000000, 1.000000, 1.000000, 1.000000), cb0[9].zzzw
  mov r2.x, v4.x
  mad r4.xz, -r7.xxyx, r1.yywy, r2.xxzx
  mul r4.xz, r4.xxzx, cb0[9].zzwz
  udiv r5.x, r6.x, r4.w, r5.x
  ineg r4.w, r6.x
  movc r4.y, r4.y, r4.w, r6.x
  itof r6.x, r4.y
  ineg r4.y, r5.x
  movc r1.z, r1.z, r4.y, r5.x
  itof r6.y, r1.z
  mul r4.yw, r1.yyyw, r6.xxxy
  mad r0.yz, r4.xxzx, r1.yywy, r4.yywy
  mov r2.x, r1.x
else 
  mov r0.yz, l(0,0,0,0)
  mov r2.x, l(0)
endif 
mov o0.xyzw, r3.xyzw
mov r2.y, v4.x
mov r2.w, v10.x
mov o1.xyzw, r2.yzxw
mov o4.xyzw, r3.xyzw
mov o5.xyzw, v1.xyzw
mov o6.xz, v6.xxzx
mov o7.xz, v8.xxzx
mov r0.w, v7.x
mov o8.xyzw, r0.wxyz
ret 
// Approximately 141 instruction slots used
#endif

const BYTE g_main[] =
{
     68,  88,  66,  67, 111,  15, 
     87, 137,  45,  53,  49, 146, 
     38,  19, 255, 145, 215,  67, 
    157, 166,   1,   0,   0,   0, 
     56,  21,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
    136,   1,   0,   0, 188,   2, 
      0,   0, 192,   3,   0,   0, 
    188,  20,   0,   0,  82,  68, 
     69,  70,  76,   1,   0,   0, 
      1,   0,   0,   0,  80,   0, 
      0,   0,   1,   0,   0,   0, 
     28,   0,   0,   0,   0,   4, 
    254, 255,  16,   1,   0,   0, 
     27,   1,   0,   0,  60,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     86,  83,  95,  67, 111, 110, 
    115, 116,  97, 110, 116,  66, 
    117, 102, 102, 101, 114,   0, 
    171, 171,  60,   0,   0,   0, 
      4,   0,   0,   0, 104,   0, 
      0,   0, 160,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 200,   0,   0,   0, 
      0,   0,   0,   0,  64,   0, 
      0,   0,   0,   0,   0,   0, 
    208,   0,   0,   0,   0,   0, 
      0,   0, 224,   0,   0,   0, 
     64,   0,   0,   0,  64,   0, 
      0,   0,   2,   0,   0,   0, 
    208,   0,   0,   0,   0,   0, 
      0,   0, 236,   0,   0,   0, 
    128,   0,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
    248,   0,   0,   0,   0,   0, 
      0,   0,   8,   1,   0,   0, 
    144,   0,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
    248,   0,   0,   0,   0,   0, 
      0,   0, 109,  67,  97, 109, 
    101, 114,  97,   0,   3,   0, 
      3,   0,   4,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 109,  67,  97, 109, 
    101, 114,  97,  80, 114, 111, 
    106,   0, 109,  85,  86,  73, 
    110, 118, 101, 114, 115, 101, 
    100,   0,   1,   0,   3,   0, 
      1,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    102,  70, 108, 105, 112,  98, 
    111, 111, 107,  80,  97, 114, 
     97, 109, 101, 116, 101, 114, 
      0,  77, 105,  99, 114, 111, 
    115, 111, 102, 116,  32,  40, 
     82,  41,  32,  72,  76,  83, 
     76,  32,  83, 104,  97, 100, 
    101, 114,  32,  67, 111, 109, 
    112, 105, 108, 101, 114,  32, 
     57,  46,  50,  57,  46,  57, 
     53,  50,  46,  51,  49,  49, 
     49,   0,  73,  83,  71,  78, 
     44,   1,   0,   0,  11,   0, 
      0,   0,   8,   0,   0,   0, 
     16,   1,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   7,   7,   0,   0, 
     25,   1,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,  15,  15,   0,   0, 
     25,   1,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   2,   0, 
      0,   0,  15,   7,   0,   0, 
     25,   1,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   3,   0, 
      0,   0,  15,   7,   0,   0, 
     32,   1,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   4,   0, 
      0,   0,   3,   3,   0,   0, 
     32,   1,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   5,   0, 
      0,   0,   3,   0,   0,   0, 
     32,   1,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   6,   0, 
      0,   0,  15,  15,   0,   0, 
     32,   1,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   7,   0, 
      0,   0,   3,   3,   0,   0, 
     32,   1,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   8,   0, 
      0,   0,  15,  15,   0,   0, 
     32,   1,   0,   0,   5,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   9,   0, 
      0,   0,   1,   1,   0,   0, 
     32,   1,   0,   0,   6,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,  10,   0, 
      0,   0,   1,   1,   0,   0, 
     80,  79,  83,  73,  84,  73, 
     79,  78,   0,  78,  79,  82, 
     77,  65,  76,   0,  84,  69, 
     88,  67,  79,  79,  82,  68, 
      0, 171, 171, 171,  79,  83, 
     71,  78, 252,   0,   0,   0, 
      9,   0,   0,   0,   8,   0, 
      0,   0, 224,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,  15,   0, 
      0,   0, 236,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      1,   0,   0,   0,  15,   0, 
      0,   0, 236,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      2,   0,   0,   0,  15,   0, 
      0,   0, 236,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      3,   0,   0,   0,  15,   0, 
      0,   0, 236,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      4,   0,   0,   0,  15,   0, 
      0,   0, 245,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      5,   0,   0,   0,  15,   0, 
      0,   0, 236,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      6,   0,   0,   0,  15,   0, 
      0,   0, 236,   0,   0,   0, 
      5,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      7,   0,   0,   0,  15,   0, 
      0,   0, 236,   0,   0,   0, 
      6,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      8,   0,   0,   0,  15,   0, 
      0,   0,  83,  86,  95,  80, 
     79,  83,  73,  84,  73,  79, 
     78,   0,  84,  69,  88,  67, 
     79,  79,  82,  68,   0,  67, 
     79,  76,  79,  82,   0, 171, 
     83,  72,  68,  82, 244,  16, 
      0,   0,  64,   0,   1,   0, 
     61,   4,   0,   0,  89,   0, 
      0,   4,  70, 142,  32,   0, 
      0,   0,   0,   0,  10,   0, 
      0,   0,  95,   0,   0,   3, 
    114,  16,  16,   0,   0,   0, 
      0,   0,  95,   0,   0,   3, 
    242,  16,  16,   0,   1,   0, 
      0,   0,  95,   0,   0,   3, 
    114,  16,  16,   0,   2,   0, 
      0,   0,  95,   0,   0,   3, 
    114,  16,  16,   0,   3,   0, 
      0,   0,  95,   0,   0,   3, 
     50,  16,  16,   0,   4,   0, 
      0,   0,  95,   0,   0,   3, 
    242,  16,  16,   0,   6,   0, 
      0,   0,  95,   0,   0,   3, 
     50,  16,  16,   0,   7,   0, 
      0,   0,  95,   0,   0,   3, 
    242,  16,  16,   0,   8,   0, 
      0,   0,  95,   0,   0,   3, 
     18,  16,  16,   0,   9,   0, 
      0,   0,  95,   0,   0,   3, 
     18,  16,  16,   0,  10,   0, 
      0,   0, 103,   0,   0,   4, 
    242,  32,  16,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
    101,   0,   0,   3, 242,  32, 
     16,   0,   1,   0,   0,   0, 
    101,   0,   0,   3, 242,  32, 
     16,   0,   2,   0,   0,   0, 
    101,   0,   0,   3, 242,  32, 
     16,   0,   3,   0,   0,   0, 
    101,   0,   0,   3, 242,  32, 
     16,   0,   4,   0,   0,   0, 
    101,   0,   0,   3, 242,  32, 
     16,   0,   5,   0,   0,   0, 
    101,   0,   0,   3, 242,  32, 
     16,   0,   6,   0,   0,   0, 
    101,   0,   0,   3, 242,  32, 
     16,   0,   7,   0,   0,   0, 
    101,   0,   0,   3, 242,  32, 
     16,   0,   8,   0,   0,   0, 
    104,   0,   0,   2,   8,   0, 
      0,   0,   0,   0,   0,  10, 
    114,   0,  16,   0,   0,   0, 
      0,   0,  38,  25,  16,   0, 
      2,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0, 191, 
      0,   0,   0, 191,   0,   0, 
      0, 191,   0,   0,   0,   0, 
      0,   0,   0,   7, 114,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,   0,   0, 
      0,  10, 114,   0,  16,   0, 
      1,   0,   0,   0,  70,  18, 
     16,   0,   3,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0, 191,   0,   0,   0, 191, 
      0,   0,   0, 191,   0,   0, 
      0,   0,   0,   0,   0,   7, 
    114,   0,  16,   0,   2,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     56,   0,   0,   7, 114,   0, 
     16,   0,   3,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0, 150,   4,  16,   0, 
      2,   0,   0,   0,  50,   0, 
      0,  10, 114,   0,  16,   0, 
      0,   0,   0,   0,  38,   9, 
     16,   0,   0,   0,   0,   0, 
     38,   9,  16,   0,   2,   0, 
      0,   0,  70,   2,  16, 128, 
     65,   0,   0,   0,   3,   0, 
      0,   0,  50,   0,   0,  11, 
     66,   0,  16,   0,   2,   0, 
      0,   0,  26, 128,  32,   0, 
      0,   0,   0,   0,   8,   0, 
      0,   0,  26,  16,  16,   0, 
      4,   0,   0,   0,  10, 128, 
     32,   0,   0,   0,   0,   0, 
      8,   0,   0,   0,  56,   0, 
      0,   8, 242,   0,  16,   0, 
      3,   0,   0,   0,  86,  21, 
     16,   0,   0,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   5,   0,   0,   0, 
     50,   0,   0,  10, 242,   0, 
     16,   0,   3,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
      6,  16,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      3,   0,   0,   0,  50,   0, 
      0,  10, 242,   0,  16,   0, 
      3,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      6,   0,   0,   0, 166,  26, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   3,   0, 
      0,   0,   0,   0,   0,   8, 
    242,   0,  16,   0,   3,   0, 
      0,   0,  70,  14,  16,   0, 
      3,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      7,   0,   0,   0,  50,   0, 
      0,  12, 114,   0,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,  64,   0,   0,   0,  64, 
      0,   0,   0,  64,   0,   0, 
      0,   0,  70,  18,  16,   0, 
      0,   0,   0,   0,  56,   0, 
      0,   8, 242,   0,  16,   0, 
      4,   0,   0,   0,  86,   5, 
     16,   0,   1,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   5,   0,   0,   0, 
     50,   0,   0,  10, 242,   0, 
     16,   0,   4,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
      6,   0,  16,   0,   1,   0, 
      0,   0,  70,  14,  16,   0, 
      4,   0,   0,   0,  50,   0, 
      0,  10, 242,   0,  16,   0, 
      1,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      6,   0,   0,   0, 166,  10, 
     16,   0,   1,   0,   0,   0, 
     70,  14,  16,   0,   4,   0, 
      0,   0,   0,   0,   0,   8, 
    242,  32,  16,   0,   3,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      7,   0,   0,   0,   0,   0, 
      0,   7, 114,   0,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
     70,  18,  16,   0,   0,   0, 
      0,   0,  56,   0,   0,   8, 
    242,   0,  16,   0,   1,   0, 
      0,   0,  86,   5,  16,   0, 
      0,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      5,   0,   0,   0,  50,   0, 
      0,  10, 242,   0,  16,   0, 
      1,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      4,   0,   0,   0,   6,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,  50,   0,   0,  10, 
    242,   0,  16,   0,   0,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,   6,   0, 
      0,   0, 166,  10,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   1,   0,   0,   0, 
      0,   0,   0,   8, 242,  32, 
     16,   0,   2,   0,   0,   0, 
     70,  14,  16,   0,   0,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0,  50,   0,   0,  11, 
    162,  32,  16,   0,   6,   0, 
      0,   0,  86, 133,  32,   0, 
      0,   0,   0,   0,   8,   0, 
      0,   0,  86,  29,  16,   0, 
      6,   0,   0,   0,   6, 128, 
     32,   0,   0,   0,   0,   0, 
      8,   0,   0,   0,  50,   0, 
      0,  11,  18,   0,  16,   0, 
      0,   0,   0,   0,  26, 128, 
     32,   0,   0,   0,   0,   0, 
      8,   0,   0,   0,  26,  16, 
     16,   0,   7,   0,   0,   0, 
     10, 128,  32,   0,   0,   0, 
      0,   0,   8,   0,   0,   0, 
     50,   0,   0,  11, 162,  32, 
     16,   0,   7,   0,   0,   0, 
     86, 133,  32,   0,   0,   0, 
      0,   0,   8,   0,   0,   0, 
     86,  29,  16,   0,   8,   0, 
      0,   0,   6, 128,  32,   0, 
      0,   0,   0,   0,   8,   0, 
      0,   0,  49,   0,   0,   8, 
     18,   0,  16,   0,   1,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,   0,  10, 128, 
     32,   0,   0,   0,   0,   0, 
      9,   0,   0,   0,  31,   0, 
      4,   3,  10,   0,  16,   0, 
      1,   0,   0,   0,  26,   0, 
      0,   5,  18,   0,  16,   0, 
      1,   0,   0,   0,  10,  16, 
     16,   0,   9,   0,   0,   0, 
     65,   0,   0,   5,  18,   0, 
     16,   0,   4,   0,   0,   0, 
     10,  16,  16,   0,   9,   0, 
      0,   0,   0,   0,   0,   7, 
     34,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      4,   0,   0,   0,   1,  64, 
      0,   0,   0,   0, 128,  63, 
     56,   0,   0,   9,  66,   0, 
     16,   0,   1,   0,   0,   0, 
     58, 128,  32,   0,   0,   0, 
      0,   0,   9,   0,   0,   0, 
     42, 128,  32,   0,   0,   0, 
      0,   0,   9,   0,   0,   0, 
     24,   0,   0,   8, 130,   0, 
     16,   0,   1,   0,   0,   0, 
     26, 128,  32,   0,   0,   0, 
      0,   0,   9,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,  31,   0,   4,   3, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  29,   0,   0,   7, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,  42,   0, 
     16,   0,   1,   0,   0,   0, 
     50,   0,   0,  11, 130,   0, 
     16,   0,   4,   0,   0,   0, 
     42, 128,  32,   0,   0,   0, 
      0,   0,   9,   0,   0,   0, 
     58, 128,  32,   0,   0,   0, 
      0,   0,   9,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
    128, 191,   0,   0,   0,   7, 
     34,   0,  16,   0,   4,   0, 
      0,   0,  10,   0,  16,   0, 
      4,   0,   0,   0,   1,  64, 
      0,   0,   0,   0, 128,  63, 
     55,   0,   0,   9, 162,   0, 
     16,   0,   4,   0,   0,   0, 
    246,  15,  16,   0,   1,   0, 
      0,   0, 246,  15,  16,   0, 
      4,   0,   0,   0,   6,   4, 
     16,   0,   4,   0,   0,   0, 
     18,   0,   0,   1,  24,   0, 
      0,   8, 130,   0,  16,   0, 
      1,   0,   0,   0,  26, 128, 
     32,   0,   0,   0,   0,   0, 
      9,   0,   0,   0,   1,  64, 
      0,   0,   0,   0, 128,  63, 
     31,   0,   4,   3,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     56,   0,   0,   7, 130,   0, 
     16,   0,   1,   0,   0,   0, 
     42,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      4,   0,   0,   0,  29,   0, 
      0,   8, 130,   0,  16,   0, 
      1,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     58,   0,  16, 128,  65,   0, 
      0,   0,   1,   0,   0,   0, 
     55,   0,   0,  10, 130,   0, 
     16,   0,   1,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0,  42,   0, 
     16, 128,  65,   0,   0,   0, 
      1,   0,   0,   0,  14,   0, 
      0,  10,  18,   0,  16,   0, 
      5,   0,   0,   0,   2,  64, 
      0,   0,   0,   0, 128,  63, 
      0,   0, 128,  63,   0,   0, 
    128,  63,   0,   0, 128,  63, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  56,   0,   0,   7, 
     18,   0,  16,   0,   5,   0, 
      0,   0,  10,   0,  16,   0, 
      4,   0,   0,   0,  10,   0, 
     16,   0,   5,   0,   0,   0, 
     26,   0,   0,   5,  18,   0, 
     16,   0,   5,   0,   0,   0, 
     10,   0,  16,   0,   5,   0, 
      0,   0,  56,   0,   0,   7, 
     34,   0,  16,   0,   4,   0, 
      0,   0,  58,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   5,   0,   0,   0, 
     56,   0,   0,   7, 130,   0, 
     16,   0,   1,   0,   0,   0, 
     42,   0,  16,   0,   1,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,  29,   0, 
      0,   8, 130,   0,  16,   0, 
      1,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     58,   0,  16, 128,  65,   0, 
      0,   0,   1,   0,   0,   0, 
     55,   0,   0,  10, 130,   0, 
     16,   0,   1,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0,  42,   0, 
     16, 128,  65,   0,   0,   0, 
      1,   0,   0,   0,  14,   0, 
      0,  10,  18,   0,  16,   0, 
      5,   0,   0,   0,   2,  64, 
      0,   0,   0,   0, 128,  63, 
      0,   0, 128,  63,   0,   0, 
    128,  63,   0,   0, 128,  63, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  56,   0,   0,   7, 
     18,   0,  16,   0,   5,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   5,   0,   0,   0, 
     26,   0,   0,   5,  18,   0, 
     16,   0,   5,   0,   0,   0, 
     10,   0,  16,   0,   5,   0, 
      0,   0,  56,   0,   0,   7, 
    130,   0,  16,   0,   4,   0, 
      0,   0,  58,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   5,   0,   0,   0, 
     18,   0,   0,   1,  24,   0, 
      0,   8, 130,   0,  16,   0, 
      1,   0,   0,   0,  26, 128, 
     32,   0,   0,   0,   0,   0, 
      9,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,  64, 
     14,   0,   0,   7,  18,   0, 
     16,   0,   5,   0,   0,   0, 
     10,   0,  16,   0,   4,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0,  65,   0, 
      0,   5,  18,   0,  16,   0, 
      5,   0,   0,   0,  10,   0, 
     16,   0,   5,   0,   0,   0, 
      0,   0,   0,   7,  34,   0, 
     16,   0,   5,   0,   0,   0, 
     10,   0,  16,   0,   5,   0, 
      0,   0,  10,   0,  16,   0, 
      5,   0,   0,   0,  29,   0, 
      0,   8,  34,   0,  16,   0, 
      5,   0,   0,   0,  26,   0, 
     16,   0,   5,   0,   0,   0, 
     26,   0,  16, 128,  65,   0, 
      0,   0,   5,   0,   0,   0, 
     55,   0,   0,  15,  98,   0, 
     16,   0,   5,   0,   0,   0, 
     86,   5,  16,   0,   5,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,  64,   0,   0,   0,  63, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0, 192,   0,   0, 
      0, 191,   0,   0,   0,   0, 
     56,   0,   0,   7,  18,   0, 
     16,   0,   5,   0,   0,   0, 
     42,   0,  16,   0,   5,   0, 
      0,   0,  10,   0,  16,   0, 
      5,   0,   0,   0,  26,   0, 
      0,   5,  18,   0,  16,   0, 
      5,   0,   0,   0,  10,   0, 
     16,   0,   5,   0,   0,   0, 
     56,   0,   0,   7,  18,   0, 
     16,   0,   5,   0,   0,   0, 
     10,   0,  16,   0,   5,   0, 
      0,   0,  26,   0,  16,   0, 
      5,   0,   0,   0,  24,   0, 
      0,   7,  18,   0,  16,   0, 
      5,   0,   0,   0,  10,   0, 
     16,   0,   5,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
    128,  63,  56,   0,   0,   7, 
     34,   0,  16,   0,   5,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   4,   0,   0,   0, 
     29,   0,   0,   8,  34,   0, 
     16,   0,   5,   0,   0,   0, 
     26,   0,  16,   0,   5,   0, 
      0,   0,  26,   0,  16, 128, 
     65,   0,   0,   0,   5,   0, 
      0,   0,  55,   0,   0,  10, 
     34,   0,  16,   0,   5,   0, 
      0,   0,  26,   0,  16,   0, 
      5,   0,   0,   0,  42,   0, 
     16,   0,   1,   0,   0,   0, 
     42,   0,  16, 128,  65,   0, 
      0,   0,   1,   0,   0,   0, 
     14,   0,   0,  10,  66,   0, 
     16,   0,   5,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
    128,  63,   0,   0, 128,  63, 
      0,   0, 128,  63,   0,   0, 
    128,  63,  26,   0,  16,   0, 
      5,   0,   0,   0,  56,   0, 
      0,   7,  66,   0,  16,   0, 
      5,   0,   0,   0,  10,   0, 
     16,   0,   4,   0,   0,   0, 
     42,   0,  16,   0,   5,   0, 
      0,   0,  26,   0,   0,   5, 
     66,   0,  16,   0,   5,   0, 
      0,   0,  42,   0,  16,   0, 
      5,   0,   0,   0,  56,   0, 
      0,   7,  34,   0,  16,   0, 
      5,   0,   0,   0,  42,   0, 
     16,   0,   5,   0,   0,   0, 
     26,   0,  16,   0,   5,   0, 
      0,   0,  50,   0,   0,  11, 
     66,   0,  16,   0,   5,   0, 
      0,   0,  42, 128,  32,   0, 
      0,   0,   0,   0,   9,   0, 
      0,   0,  58, 128,  32,   0, 
      0,   0,   0,   0,   9,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0, 128, 191,  65,   0, 
      0,   5, 130,   0,  16,   0, 
      5,   0,   0,   0,  26,   0, 
     16,   0,   5,   0,   0,   0, 
      0,   0,   0,   8, 130,   0, 
     16,   0,   5,   0,   0,   0, 
     58,   0,  16, 128,  65,   0, 
      0,   0,   5,   0,   0,   0, 
     42,   0,  16,   0,   5,   0, 
      0,   0,  55,   0,   0,   9, 
     18,   0,  16,   0,   5,   0, 
      0,   0,  10,   0,  16,   0, 
      5,   0,   0,   0,  58,   0, 
     16,   0,   5,   0,   0,   0, 
     26,   0,  16,   0,   5,   0, 
      0,   0,  14,   0,   0,   7, 
    130,   0,  16,   0,   5,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,  42,   0, 
     16,   0,   1,   0,   0,   0, 
     65,   0,   0,   5, 130,   0, 
     16,   0,   5,   0,   0,   0, 
     58,   0,  16,   0,   5,   0, 
      0,   0,   0,   0,   0,   7, 
     18,   0,  16,   0,   6,   0, 
      0,   0,  58,   0,  16,   0, 
      5,   0,   0,   0,  58,   0, 
     16,   0,   5,   0,   0,   0, 
     29,   0,   0,   8,  18,   0, 
     16,   0,   6,   0,   0,   0, 
     10,   0,  16,   0,   6,   0, 
      0,   0,  10,   0,  16, 128, 
     65,   0,   0,   0,   6,   0, 
      0,   0,  55,   0,   0,  15, 
     50,   0,  16,   0,   6,   0, 
      0,   0,   6,   0,  16,   0, 
      6,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,  64, 
      0,   0,   0,  63,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0, 192,   0,   0,   0, 191, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  56,   0,   0,   7, 
    130,   0,  16,   0,   5,   0, 
      0,   0,  58,   0,  16,   0, 
      5,   0,   0,   0,  26,   0, 
     16,   0,   6,   0,   0,   0, 
     26,   0,   0,   5, 130,   0, 
     16,   0,   5,   0,   0,   0, 
     58,   0,  16,   0,   5,   0, 
      0,   0,  56,   0,   0,   7, 
    130,   0,  16,   0,   5,   0, 
      0,   0,  58,   0,  16,   0, 
      5,   0,   0,   0,  10,   0, 
     16,   0,   6,   0,   0,   0, 
     24,   0,   0,   7, 130,   0, 
     16,   0,   5,   0,   0,   0, 
     58,   0,  16,   0,   5,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0, 128,  63,  56,   0, 
      0,   7,  18,   0,  16,   0, 
      6,   0,   0,   0,  42,   0, 
     16,   0,   1,   0,   0,   0, 
     26,   0,  16,   0,   1,   0, 
      0,   0,  29,   0,   0,   8, 
     18,   0,  16,   0,   6,   0, 
      0,   0,  10,   0,  16,   0, 
      6,   0,   0,   0,  10,   0, 
     16, 128,  65,   0,   0,   0, 
      6,   0,   0,   0,  55,   0, 
      0,  10,  66,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   6,   0,   0,   0, 
     42,   0,  16,   0,   1,   0, 
      0,   0,  42,   0,  16, 128, 
     65,   0,   0,   0,   1,   0, 
      0,   0,  14,   0,   0,  10, 
     18,   0,  16,   0,   6,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0, 128,  63,   0,   0, 
    128,  63,   0,   0, 128,  63, 
      0,   0, 128,  63,  42,   0, 
     16,   0,   1,   0,   0,   0, 
     56,   0,   0,   7,  34,   0, 
     16,   0,   1,   0,   0,   0, 
     26,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      6,   0,   0,   0,  26,   0, 
      0,   5,  34,   0,  16,   0, 
      1,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
     56,   0,   0,   7,  34,   0, 
     16,   0,   1,   0,   0,   0, 
     26,   0,  16,   0,   1,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0,  65,   0, 
      0,   5,  66,   0,  16,   0, 
      1,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
      0,   0,   0,   8,  66,   0, 
     16,   0,   1,   0,   0,   0, 
     42,   0,  16, 128,  65,   0, 
      0,   0,   1,   0,   0,   0, 
     42,   0,  16,   0,   5,   0, 
      0,   0,  55,   0,   0,   9, 
     34,   0,  16,   0,   5,   0, 
      0,   0,  58,   0,  16,   0, 
      5,   0,   0,   0,  42,   0, 
     16,   0,   1,   0,   0,   0, 
     26,   0,  16,   0,   1,   0, 
      0,   0,   0,   0,   0,   7, 
     66,   0,  16,   0,   4,   0, 
      0,   0,  10,   0,  16,   0, 
      4,   0,   0,   0,   1,  64, 
      0,   0,   0,   0, 128,  63, 
     55,   0,   0,   9, 162,   0, 
     16,   0,   4,   0,   0,   0, 
    246,  15,  16,   0,   1,   0, 
      0,   0,   6,   4,  16,   0, 
      5,   0,   0,   0,   6,   8, 
     16,   0,   4,   0,   0,   0, 
     21,   0,   0,   1,  21,   0, 
      0,   1,  27,   0,   0,   5, 
     98,   0,  16,   0,   1,   0, 
      0,   0,  86,   7,  16,   0, 
      4,   0,   0,   0,  27,   0, 
      0,   6, 130,   0,  16,   0, 
      1,   0,   0,   0,  42, 128, 
     32,   0,   0,   0,   0,   0, 
      9,   0,   0,   0,   1,   0, 
      0,  10,  50,   0,  16,   0, 
      4,   0,   0,   0, 150,   5, 
     16,   0,   1,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0, 128,   0,   0,   0, 128, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  36,   0,   0,   8, 
    194,   0,  16,   0,   4,   0, 
      0,   0,  86,   9,  16,   0, 
      1,   0,   0,   0,  86,   9, 
     16, 128,  65,   0,   0,   0, 
      1,   0,   0,   0,  36,   0, 
      0,   8,  18,   0,  16,   0, 
      5,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     58,   0,  16, 128,  65,   0, 
      0,   0,   1,   0,   0,   0, 
     78,   0,   0,   9,  18,   0, 
     16,   0,   6,   0,   0,   0, 
     18,   0,  16,   0,   7,   0, 
      0,   0,  42,   0,  16,   0, 
      4,   0,   0,   0,  10,   0, 
     16,   0,   5,   0,   0,   0, 
     40,   0,   0,   5,  66,   0, 
     16,   0,   4,   0,   0,   0, 
     10,   0,  16,   0,   7,   0, 
      0,   0,  55,   0,   0,   9, 
     18,   0,  16,   0,   4,   0, 
      0,   0,  10,   0,  16,   0, 
      4,   0,   0,   0,  42,   0, 
     16,   0,   4,   0,   0,   0, 
     10,   0,  16,   0,   7,   0, 
      0,   0,  43,   0,   0,   5, 
     18,   0,  16,   0,   7,   0, 
      0,   0,  10,   0,  16,   0, 
      4,   0,   0,   0,  87,   0, 
      0,   7,  98,   0,  16,   0, 
      1,   0,   0,   0, 246,  15, 
     16,   0,   1,   0,   0,   0, 
     86,   6,  16,   0,   1,   0, 
      0,   0,  40,   0,   0,   5, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      6,   0,   0,   0,   1,   0, 
      0,  10,  98,   0,  16,   0, 
      1,   0,   0,   0,  86,   6, 
     16,   0,   1,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   0, 128, 
      0,   0,   0, 128,   0,   0, 
      0,   0,  55,   0,   0,   9, 
     34,   0,  16,   0,   1,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   6,   0, 
      0,   0,  43,   0,   0,   5, 
     34,   0,  16,   0,   7,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,  14,   0, 
      0,  11, 162,   0,  16,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0,   0,   0, 128,  63, 
      0,   0, 128,  63,   0,   0, 
    128,  63,   0,   0, 128,  63, 
    166, 142,  32,   0,   0,   0, 
      0,   0,   9,   0,   0,   0, 
     54,   0,   0,   5,  18,   0, 
     16,   0,   2,   0,   0,   0, 
     10,  16,  16,   0,   4,   0, 
      0,   0,  50,   0,   0,  10, 
     82,   0,  16,   0,   4,   0, 
      0,   0,   6,   1,  16, 128, 
     65,   0,   0,   0,   7,   0, 
      0,   0,  86,   7,  16,   0, 
      1,   0,   0,   0,   6,   2, 
     16,   0,   2,   0,   0,   0, 
     56,   0,   0,   8,  82,   0, 
     16,   0,   4,   0,   0,   0, 
      6,   2,  16,   0,   4,   0, 
      0,   0, 166, 139,  32,   0, 
      0,   0,   0,   0,   9,   0, 
      0,   0,  78,   0,   0,   9, 
     18,   0,  16,   0,   5,   0, 
      0,   0,  18,   0,  16,   0, 
      6,   0,   0,   0,  58,   0, 
     16,   0,   4,   0,   0,   0, 
     10,   0,  16,   0,   5,   0, 
      0,   0,  40,   0,   0,   5, 
    130,   0,  16,   0,   4,   0, 
      0,   0,  10,   0,  16,   0, 
      6,   0,   0,   0,  55,   0, 
      0,   9,  34,   0,  16,   0, 
      4,   0,   0,   0,  26,   0, 
     16,   0,   4,   0,   0,   0, 
     58,   0,  16,   0,   4,   0, 
      0,   0,  10,   0,  16,   0, 
      6,   0,   0,   0,  43,   0, 
      0,   5,  18,   0,  16,   0, 
      6,   0,   0,   0,  26,   0, 
     16,   0,   4,   0,   0,   0, 
     40,   0,   0,   5,  34,   0, 
     16,   0,   4,   0,   0,   0, 
     10,   0,  16,   0,   5,   0, 
      0,   0,  55,   0,   0,   9, 
     66,   0,  16,   0,   1,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0,  26,   0, 
     16,   0,   4,   0,   0,   0, 
     10,   0,  16,   0,   5,   0, 
      0,   0,  43,   0,   0,   5, 
     34,   0,  16,   0,   6,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0,  56,   0, 
      0,   7, 162,   0,  16,   0, 
      4,   0,   0,   0,  86,  13, 
     16,   0,   1,   0,   0,   0, 
      6,   4,  16,   0,   6,   0, 
      0,   0,  50,   0,   0,   9, 
     98,   0,  16,   0,   0,   0, 
      0,   0,   6,   2,  16,   0, 
      4,   0,   0,   0,  86,   7, 
     16,   0,   1,   0,   0,   0, 
     86,   7,  16,   0,   4,   0, 
      0,   0,  54,   0,   0,   5, 
     18,   0,  16,   0,   2,   0, 
      0,   0,  10,   0,  16,   0, 
      1,   0,   0,   0,  18,   0, 
      0,   1,  54,   0,   0,   8, 
     98,   0,  16,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  54,   0, 
      0,   5,  18,   0,  16,   0, 
      2,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     21,   0,   0,   1,  54,   0, 
      0,   5, 242,  32,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   3,   0,   0,   0, 
     54,   0,   0,   5,  34,   0, 
     16,   0,   2,   0,   0,   0, 
     10,  16,  16,   0,   4,   0, 
      0,   0,  54,   0,   0,   5, 
    130,   0,  16,   0,   2,   0, 
      0,   0,  10,  16,  16,   0, 
     10,   0,   0,   0,  54,   0, 
      0,   5, 242,  32,  16,   0, 
      1,   0,   0,   0, 150,  12, 
     16,   0,   2,   0,   0,   0, 
     54,   0,   0,   5, 242,  32, 
     16,   0,   4,   0,   0,   0, 
     70,  14,  16,   0,   3,   0, 
      0,   0,  54,   0,   0,   5, 
    242,  32,  16,   0,   5,   0, 
      0,   0,  70,  30,  16,   0, 
      1,   0,   0,   0,  54,   0, 
      0,   5,  82,  32,  16,   0, 
      6,   0,   0,   0,   6,  18, 
     16,   0,   6,   0,   0,   0, 
     54,   0,   0,   5,  82,  32, 
     16,   0,   7,   0,   0,   0, 
      6,  18,  16,   0,   8,   0, 
      0,   0,  54,   0,   0,   5, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  10,  16,  16,   0, 
      7,   0,   0,   0,  54,   0, 
      0,   5, 242,  32,  16,   0, 
      8,   0,   0,   0,  54,   9, 
     16,   0,   0,   0,   0,   0, 
     62,   0,   0,   1,  83,  84, 
     65,  84, 116,   0,   0,   0, 
    141,   0,   0,   0,   8,   0, 
      0,   0,   0,   0,   0,   0, 
     19,   0,   0,   0,  70,   0, 
      0,   0,   6,   0,   0,   0, 
      3,   0,   0,   0,   4,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  28,   0, 
      0,   0,  14,   0,   0,   0, 
     18,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0
};
