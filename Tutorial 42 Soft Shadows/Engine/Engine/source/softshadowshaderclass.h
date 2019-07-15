////////////////////////////////////////////////////////////////////////////////
// Filename: softshadowshaderclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _SOFTSHADOWSHADERCLASS_H_
#define _SOFTSHADOWSHADERCLASS_H_


//////////////
// INCLUDES //
//////////////
#include <d3d11.h>
#include <fstream>
#include <d3dcompiler.h>
#include <DirectXMath.h>
using namespace DirectX;
using namespace std;


#pragma comment(lib, "d3dcompiler.lib")



////////////////////////////////////////////////////////////////////////////////
// Class name: SoftShadowShaderClass
////////////////////////////////////////////////////////////////////////////////
class SoftShadowShaderClass
{
private:
	struct MatrixBufferType
	{
		XMMATRIX world;
		XMMATRIX view;
		XMMATRIX projection;
	};

	struct LightBufferType
	{
		XMFLOAT4 ambientColor;
		XMFLOAT4 diffuseColor;
	};

	struct LightBufferType2
	{
		XMFLOAT3 lightPosition;
		float padding;
	};

public:
	SoftShadowShaderClass();
	SoftShadowShaderClass(const SoftShadowShaderClass&);
	~SoftShadowShaderClass();

	bool Initialize(ID3D11Device* device, HWND hwnd);
	void Shutdown();
	bool Render(ID3D11DeviceContext* deviceContext, int indexCount, XMMATRIX worldMatrix, XMMATRIX viewMatrix,
		XMMATRIX projectionMatrix, ID3D11ShaderResourceView* texture, ID3D11ShaderResourceView* shadowTexture,
		XMFLOAT3 lightPosition, XMFLOAT4 ambientColor, XMFLOAT4 diffuseColor);

private:
	bool InitializeShader(ID3D11Device* device, HWND hwnd, WCHAR* vsFilename, WCHAR* psFilename);
	void ShutdownShader();
	void OutputShaderErrorMessage(ID3D10Blob* errorMessage, HWND hwnd, WCHAR* shaderFilename);

	bool SetShaderParameters(ID3D11DeviceContext* deviceContext, XMMATRIX worldMatrix, XMMATRIX viewMatrix,
		XMMATRIX projectionMatrix, ID3D11ShaderResourceView* texture, ID3D11ShaderResourceView* shadowTexture,
		XMFLOAT3 lightPosition, XMFLOAT4 ambientColor, XMFLOAT4 diffuseColor);

	void RenderShader(ID3D11DeviceContext* deviceContext, int indexCount);

private:
	ID3D11VertexShader* m_vertexShader;
	ID3D11PixelShader* m_pixelShader;
	ID3D11InputLayout* m_layout;
	ID3D11SamplerState* m_sampleStateWrap;
	ID3D11SamplerState* m_sampleStateClamp;
	ID3D11Buffer* m_matrixBuffer;
	ID3D11Buffer* m_lightBuffer;
	ID3D11Buffer* m_lightBuffer2;
};

#endif