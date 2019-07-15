////////////////////////////////////////////////////////////////////////////////
// Filename: lightclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "lightclass.h"


LightClass::LightClass()
{
}


LightClass::LightClass(const LightClass& other)
{
}


LightClass::~LightClass()
{
}


void LightClass::SetAmbientColor(float red, float green, float blue, float alpha)
{
	m_ambientColor = XMFLOAT4(red, green, blue, alpha);
	return;
}


void LightClass::SetDiffuseColor(float red, float green, float blue, float alpha)
{
	m_diffuseColor = XMFLOAT4(red, green, blue, alpha);
	return;
}


void LightClass::SetPosition(float x, float y, float z)
{
	m_position = XMFLOAT3(x, y, z);
	return;
}


void LightClass::SetLookAt(float x, float y, float z)
{
	m_lookAt.x = x;
	m_lookAt.y = y;
	m_lookAt.z = z;
	return;
}


XMFLOAT4 LightClass::GetAmbientColor()
{
	return m_ambientColor;
}


XMFLOAT4 LightClass::GetDiffuseColor()
{
	return m_diffuseColor;
}


XMFLOAT3 LightClass::GetPosition()
{
	return m_position;
}


void LightClass::GenerateViewMatrix()
{
	XMFLOAT3 up, position, lookAt;
	XMVECTOR UPv, positionV, lookAtV;
	float radians = 0.0f;


	// Setup the vector that points upwards.
	up.x = 0.0f;
	up.y = 1.0f;
	up.z = 0.0f;
	UPv = XMLoadFloat3(&up);

	// Setup the position of the camera in the world.
	position.x = m_position.x;
	position.y = m_position.y;
	position.z = m_position.z;

	positionV = XMLoadFloat3(&position);


	// Setup where the camera is looking.
	lookAt.x = sinf(radians) + m_position.x;
	lookAt.y = m_position.y;
	lookAt.z = cosf(radians) + m_position.z;
	lookAtV = XMLoadFloat3(&lookAt);

	// Create the base view matrix from the three vectors.

	m_viewMatrix = XMMatrixLookAtLH(positionV, lookAtV, UPv);

}


void LightClass::GenerateProjectionMatrix(float screenDepth, float screenNear)
{
	float fieldOfView, screenAspect;


	// Setup field of view and screen aspect for a square light source.
	fieldOfView = 3.141592654f / 2.0f;
	screenAspect = 1.0f;

	// Create the projection matrix for the light.
	m_projectionMatrix = XMMatrixPerspectiveFovLH(fieldOfView, screenAspect, screenNear, screenDepth);
}


void LightClass::GetViewMatrix(XMMATRIX& viewMatrix)
{
	viewMatrix = m_viewMatrix;
	return;
}


void LightClass::GetProjectionMatrix(XMMATRIX& projectionMatrix)
{
	projectionMatrix = m_projectionMatrix;
	return;
}