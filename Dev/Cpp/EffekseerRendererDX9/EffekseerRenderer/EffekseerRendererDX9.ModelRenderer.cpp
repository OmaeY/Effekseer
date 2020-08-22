﻿
//----------------------------------------------------------------------------------
// Include
//----------------------------------------------------------------------------------
#include "EffekseerRendererDX9.RenderState.h"
#include "EffekseerRendererDX9.RendererImplemented.h"

#include "EffekseerRendererDX9.IndexBuffer.h"
#include "EffekseerRendererDX9.ModelRenderer.h"
#include "EffekseerRendererDX9.Shader.h"
#include "EffekseerRendererDX9.VertexBuffer.h"

//-----------------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------------
namespace EffekseerRendererDX9
{
//-----------------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------------

namespace ShaderLightingTextureNormal_VS_Ad
{
static
#include "ShaderHeader/EffekseerRenderer.ModelRenderer.ShaderLightingTextureNormal_VS.h"
} // namespace ShaderLightingTextureNormal_VS_Ad

namespace ShaderLightingTextureNormal_PS_Ad
{
static
#include "ShaderHeader/EffekseerRenderer.ModelRenderer.ShaderLightingTextureNormal_PS.h"

} // namespace ShaderLightingTextureNormal_PS_Ad

namespace ShaderTexture_VS_Ad
{
static
#include "ShaderHeader/EffekseerRenderer.ModelRenderer.ShaderTexture_VS.h"
} // namespace ShaderTexture_VS_Ad

namespace ShaderTexture_PS_Ad
{
static
#include "ShaderHeader/EffekseerRenderer.ModelRenderer.ShaderTexture_PS.h"
} // namespace ShaderTexture_PS_Ad

namespace ShaderDistortionTexture_VS_Ad
{
static
#include "ShaderHeader/EffekseerRenderer.ModelRenderer.ShaderDistortion_VS.h"
} // namespace ShaderDistortionTexture_VS_Ad

namespace ShaderDistortionTexture_PS_Ad
{
static
#include "ShaderHeader/EffekseerRenderer.ModelRenderer.ShaderDistortion_PS.h"
} // namespace ShaderDistortionTexture_PS_Ad

namespace ShaderLightingTextureNormal_VS
{
static
#include "ShaderHeader/model_lit_vs.h"
} // namespace ShaderLightingTextureNormal_VS

namespace ShaderLightingTextureNormal_PS
{
static
#include "ShaderHeader/model_lit_ps.h"

} // namespace ShaderLightingTextureNormal_PS

namespace ShaderTexture_VS
{
static
#include "ShaderHeader/model_unlit_vs.h"
} // namespace ShaderTexture_VS

namespace ShaderTexture_PS
{
static
#include "ShaderHeader/model_unlit_ps.h"
} // namespace ShaderTexture_PS

namespace ShaderDistortionTexture_VS
{
static
#include "ShaderHeader/model_distortion_vs.h"
} // namespace ShaderDistortionTexture_VS

namespace ShaderDistortionTexture_PS
{
static
#include "ShaderHeader/model_distortion_ps.h"
} // namespace ShaderDistortionTexture_PS

#ifdef __EFFEKSEER_BUILD_VERSION16__
const int32_t ModelRendererInstanceCount = 10;
#else
const int32_t ModelRendererInstanceCount = 20;
#endif

ModelRenderer::ModelRenderer(RendererImplemented* renderer,
							 Shader* shader_advanced_lit,
							 Shader* shader_advanced_unlit,
							 Shader* shader_advanced_distortion,
							 Shader* shader_lit,
							 Shader* shader_unlit,
							 Shader* shader_distortion)
	: m_renderer(renderer)
	, shader_advanced_lit_(shader_advanced_lit)
	, shader_advanced_unlit_(shader_advanced_unlit)
	, shader_advanced_distortion_(shader_advanced_distortion)
	, shader_lit_(shader_lit)
	, shader_unlit_(shader_unlit)
	, shader_distortion_(shader_distortion)
{
	{
		Shader* shaders[2];
		shaders[0] = shader_advanced_lit_;
		shaders[1] = shader_advanced_unlit_;

		for (int32_t i = 0; i < 2; i++)
		{
			shaders[i]->SetVertexConstantBufferSize(sizeof(::EffekseerRenderer::ModelRendererAdvancedVertexConstantBuffer<ModelRendererInstanceCount>));
			shaders[i]->SetPixelConstantBufferSize(sizeof(::EffekseerRenderer::ModelRendererAdvancedPixelConstantBuffer));
		}

		shader_advanced_distortion_->SetVertexConstantBufferSize(sizeof(::EffekseerRenderer::ModelRendererAdvancedVertexConstantBuffer<ModelRendererInstanceCount>));
		shader_advanced_distortion_->SetPixelConstantBufferSize(sizeof(::EffekseerRenderer::ModelRendererDistortionPixelConstantBuffer));
	}

	{
		Shader* shaders[2];
		shaders[0] = shader_lit_;
		shaders[1] = shader_unlit_;

		for (int32_t i = 0; i < 2; i++)
		{
			shaders[i]->SetVertexConstantBufferSize(sizeof(::EffekseerRenderer::ModelRendererVertexConstantBuffer<ModelRendererInstanceCount>));
			shaders[i]->SetPixelConstantBufferSize(sizeof(::EffekseerRenderer::ModelRendererPixelConstantBuffer));
		}

		shader_distortion_->SetVertexConstantBufferSize(sizeof(::EffekseerRenderer::ModelRendererVertexConstantBuffer<ModelRendererInstanceCount>));
		shader_distortion_->SetPixelConstantBufferSize(sizeof(::EffekseerRenderer::ModelRendererDistortionPixelConstantBuffer));
	}
}

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
ModelRenderer::~ModelRenderer()
{
	ES_SAFE_DELETE(shader_advanced_lit_);
	ES_SAFE_DELETE(shader_advanced_unlit_);
	ES_SAFE_DELETE(shader_advanced_distortion_);
	ES_SAFE_DELETE(shader_lit_);
	ES_SAFE_DELETE(shader_unlit_);
	ES_SAFE_DELETE(shader_distortion_);
}

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
ModelRenderer* ModelRenderer::Create(RendererImplemented* renderer)
{
	assert(renderer != NULL);
	assert(renderer->GetDevice() != NULL);

	// 座標(3) 法線(3)*3 UV(2)
	D3DVERTEXELEMENT9 decl[] = {{0, 0, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 0},
								{0, 12, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 1},
								{0, 24, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 2},
								{0, 36, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 3},
								{0, 48, D3DDECLTYPE_FLOAT2, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 4},
								{0, 56, D3DDECLTYPE_D3DCOLOR, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 5},
								{0, 60, D3DDECLTYPE_UBYTE4, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 6},
								D3DDECL_END()};

	Shader* shader_ad_lit = Shader::Create(renderer,
										   ShaderLightingTextureNormal_VS_Ad::g_vs30_main,
										   sizeof(ShaderLightingTextureNormal_VS_Ad::g_vs30_main),
										   ShaderLightingTextureNormal_PS_Ad::g_ps30_main,
										   sizeof(ShaderLightingTextureNormal_PS_Ad::g_ps30_main),
										   "ModelRendererLightingTextureNormal",
										   decl,
										   true);

	Shader* shader_ad_unlit = Shader::Create(renderer,
											 ShaderTexture_VS_Ad::g_vs30_main,
											 sizeof(ShaderTexture_VS_Ad::g_vs30_main),
											 ShaderTexture_PS_Ad::g_ps30_main,
											 sizeof(ShaderTexture_PS_Ad::g_ps30_main),
											 "ModelRendererTexture",
											 decl,
											 true);

	auto shader_ad_distortion = Shader::Create(renderer,
											   ShaderDistortionTexture_VS_Ad::g_vs30_main,
											   sizeof(ShaderDistortionTexture_VS_Ad::g_vs30_main),
											   ShaderDistortionTexture_PS_Ad::g_ps30_main,
											   sizeof(ShaderDistortionTexture_PS_Ad::g_ps30_main),
											   "ModelRendererDistortionTexture",
											   decl,
											   true);

	Shader* shader_lit = Shader::Create(renderer,
										ShaderLightingTextureNormal_VS::g_vs30_main,
										sizeof(ShaderLightingTextureNormal_VS::g_vs30_main),
										ShaderLightingTextureNormal_PS::g_ps30_main,
										sizeof(ShaderLightingTextureNormal_PS::g_ps30_main),
										"ModelRendererLightingTextureNormal",
										decl,
										true);

	Shader* shader_unlit = Shader::Create(renderer,
										  ShaderTexture_VS::g_vs30_main,
										  sizeof(ShaderTexture_VS::g_vs30_main),
										  ShaderTexture_PS::g_ps30_main,
										  sizeof(ShaderTexture_PS::g_ps30_main),
										  "ModelRendererTexture",
										  decl,
										  true);

	auto shader_distortion = Shader::Create(renderer,
											ShaderDistortionTexture_VS::g_vs30_main,
											sizeof(ShaderDistortionTexture_VS::g_vs30_main),
											ShaderDistortionTexture_PS::g_ps30_main,
											sizeof(ShaderDistortionTexture_PS::g_ps30_main),
											"ModelRendererDistortionTexture",
											decl,
											true);

	if (shader_ad_lit == NULL || shader_ad_unlit == NULL || shader_ad_distortion == NULL ||
		shader_lit == NULL || shader_unlit == NULL || shader_distortion == NULL)
	{
		ES_SAFE_DELETE(shader_ad_lit);
		ES_SAFE_DELETE(shader_ad_unlit);
		ES_SAFE_DELETE(shader_ad_distortion);
		ES_SAFE_DELETE(shader_lit);
		ES_SAFE_DELETE(shader_unlit);
		ES_SAFE_DELETE(shader_distortion);
	}

	return new ModelRenderer(renderer, shader_ad_lit, shader_ad_unlit, shader_ad_distortion, shader_lit, shader_unlit, shader_distortion);
}

void ModelRenderer::BeginRendering(const efkModelNodeParam& parameter, int32_t count, void* userData)
{
	BeginRendering_(m_renderer, parameter, count, userData);
}

void ModelRenderer::Rendering(const efkModelNodeParam& parameter, const InstanceParameter& instanceParameter, void* userData)
{
	Rendering_<RendererImplemented>(m_renderer, parameter, instanceParameter, userData);
}

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
void ModelRenderer::EndRendering(const efkModelNodeParam& parameter, void* userData)
{
	if (parameter.ModelIndex < 0)
	{
		return;
	}

	auto model = (Model*)parameter.EffectPointer->GetModel(parameter.ModelIndex);
	if (model == nullptr)
	{
		return;
	}

	model->LoadToGPU();
	if (!model->IsLoadedOnGPU)
	{
		return;
	}

	EndRendering_<
		RendererImplemented,
		Shader,
		Model,
		true,
		ModelRendererInstanceCount>(
		m_renderer,
		shader_advanced_lit_,
		shader_advanced_unlit_,
		shader_advanced_distortion_,
		shader_lit_,
		shader_unlit_,
		shader_distortion_,
		parameter);
}

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
} // namespace EffekseerRendererDX9
//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
