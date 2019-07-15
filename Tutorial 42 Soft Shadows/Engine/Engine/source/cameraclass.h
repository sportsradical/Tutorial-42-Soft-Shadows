////////////////////////////////////////////////////////////////////////////////
// Filename: cameraclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _CAMERACLASS_H_
#define _CAMERACLASS_H_


//////////////
// INCLUDES //
//////////////

#include <DirectXMath.h>
using namespace DirectX;

////////////////////////////////////////////////////////////////////////////////
// Class name: CameraClass
////////////////////////////////////////////////////////////////////////////////
class CameraClass
{
public:
	CameraClass();
	CameraClass(const CameraClass&);
	~CameraClass();

	void SetPosition(float x, float y, float z);
	void SetRotation(float x, float y, float z);

	XMFLOAT3 GetPosition();
	XMFLOAT3 GetRotation();

	void Render();
	void GetViewMatrix(XMMATRIX&);

	void RenderBaseViewMatrix();
	void GetBaseViewMatrix(XMMATRIX&);

private:
	XMFLOAT3 m_position;
	XMFLOAT3 m_rotation;
	XMMATRIX m_viewMatrix, m_baseViewMatrix;
};

#endif