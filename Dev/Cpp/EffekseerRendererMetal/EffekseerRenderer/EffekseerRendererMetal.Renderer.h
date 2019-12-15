
#ifndef __EFFEKSEERRENDERER_METAL_RENDERER_H__
#define __EFFEKSEERRENDERER_METAL_RENDERER_H__

#include "../../EffekseerRendererCommon/EffekseerRenderer.Renderer.h"
#include "EffekseerRendererMetal.Base.h"
#include <functional>

namespace EffekseerRendererMetal
{
/**
@brief	Create an instance
@param	device			directX12 device
@param int32_t	the number of maximum sprites
@return	instance
*/
::EffekseerRenderer::Renderer* Create(ID3D12Device* device,
									  ID3D12CommandQueue* commandQueue,
									  int32_t swapBufferCount,
									  DXGI_FORMAT* renderTargetFormats,
									  int32_t renderTargetCount,
									  bool hasDepth,
									  bool isReversedDepth,
									  int32_t squareMaxCount);

Effekseer::TextureData* CreateTextureData(::EffekseerRenderer::Renderer* renderer, ID3D12Resource* texture);

void DeleteTextureData(::EffekseerRenderer::Renderer* renderer, Effekseer::TextureData* textureData);

void FlushAndWait(::EffekseerRenderer::Renderer* renderer);

EffekseerRenderer::CommandList* CreateCommandList(::EffekseerRenderer::Renderer* renderer,
												  ::EffekseerRenderer::SingleFrameMemoryPool* memoryPool);

EffekseerRenderer::SingleFrameMemoryPool* CreateSingleFrameMemoryPool(::EffekseerRenderer::Renderer* renderer);

void BeginCommandList(EffekseerRenderer::CommandList* commandList, ID3D12GraphicsCommandList* dx12CommandList);

void EndCommandList(EffekseerRenderer::CommandList* commandList);

} // namespace EffekseerRendererMetal

#endif