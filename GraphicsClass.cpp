#include "graphicsclass.h"


GraphicsClass::GraphicsClass()
{
	m_Direct3D = 0;
}


GraphicsClass::GraphicsClass(const GraphicsClass& other)
{
}


GraphicsClass::~GraphicsClass()
{
}


bool GraphicsClass::Initialize(int screenWidth, int screenHeight, HWND hwnd)
{
	bool result;

	m_Direct3D = new D3DClass;
	if (!m_Direct3D) {
		return false;
	}

	result = m_Direct3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);

	if (!result) {
		MessageBox(hwnd, "Nah", "Error", MB_OK);
		return false;
	}

	return true;
}


void GraphicsClass::Shutdown()
{

	return;
}


bool GraphicsClass::Frame()
{
	bool result;

	result = Render();

	if (!result) {

		return false;

	}

	return true;
}


bool GraphicsClass::Render()
{
	m_Direct3D->BeginScene(5.0f, 5.0f, 5.0f, 1.0f);

	m_Direct3D->EndScene();
	return true;
}