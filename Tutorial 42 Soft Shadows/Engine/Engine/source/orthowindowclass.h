////////////////////////////////////////////////////////////////////////////////
// Filename: orthowindowclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _ORTHOWINDOWCLASS_H_
#define _ORTHOWINDOWCLASS_H_


//////////////
// INCLUDES //
//////////////
#include <d3d11.h>
#include <DirectXMath.h>
using namespace DirectX;


////////////////////////////////////////////////////////////////////////////////
// Class name: OrthoWindowClass
////////////////////////////////////////////////////////////////////////////////
class OrthoWindowClass
{
private:
	struct VertexType
	{
		XMFLOAT3 position;
	    XMFLOAT2 texture;
	};

public:
	OrthoWindowClass();
	OrthoWindowClass(const OrthoWindowClass& other);
	~OrthoWindowClass();

	bool Initialize(ID3D11Device* device, int windowWidth, int windowHeight);
	void Shutdown();
	void Render(ID3D11DeviceContext* deviceContext);

	int GetIndexCount();

private:
	bool InitializeBuffers(ID3D11Device* device, int windowWidth, int windowHeight);
	void ShutdownBuffers();
	void RenderBuffers(ID3D11DeviceContext* deviceContext);

private:
	ID3D11Buffer *m_vertexBuffer, *m_indexBuffer;
	int m_vertexCount, m_indexCount;
};

#endif