#include "framework.h"
#include "ColorshaderClass.h"

ColorshaderClass::ColorshaderClass()
{
}

ColorshaderClass::ColorshaderClass(const ColorshaderClass&)
{
}

ColorshaderClass::~ColorshaderClass()
{
}

bool ColorshaderClass::Initialize(ID3D11Device* device, HWND hwnd)
{
	//정점 및 픽셀 쉐이더 초기화
	WCHAR vs[] = L"../Dx11Demo_04/Color.vs";
	WCHAR ps[] = L"../Dx11Demo_04/Color.ps";
	return InitializeShader(device, hwnd, vs, ps);
}

void ColorshaderClass::shutdown()
{
	//정점 및 픽셀 쉐이더와 관련된 객체 종료
	ShutdownShader();
}

bool ColorshaderClass::Render(ID3D11DeviceContext* deviceContext, int indexCount, XMMATRIX worldMatrix, XMMATRIX viewMatrix, XMMATRIX projectionMatrix)
{
	if (!SetShaderParameters(deviceContext, worldMatrix, viewMatrix, projectionMatrix))
	{
		return false;
	}

	//설정된 버퍼를 쉐이더로 렌더링
	RenderShader(deviceContext, indexCount);

	return true;
}

bool ColorshaderClass::InitializeShader(ID3D11Device* device, HWND hwnd, WCHAR* vsFilename, WCHAR* psFilename)
{
	ID3D10Blob* errorMessage = nullptr;

	ID3D10Blob* vertexShaderBuffer = nullptr;
	if (FAILED(D3DCompileFromFile(vsFilename, NULL, NULL, "ColorVertexShader", "vs_5_0", D3D10_SHADER_ENABLE_STRICTNESS,
		0, &vertexShaderBuffer, &errorMessage)))
	{

	}
	return false;
}

void ColorshaderClass::ShutdownShader()
{
}

void ColorshaderClass::OutputShaderErrorMessage(ID3D10Blob*, HWND, WCHAR*)
{
}

bool ColorshaderClass::SetShaderParameters(ID3D11DeviceContext*, XMMATRIX, XMMATRIX, XMMATRIX)
{
	return false;
}

void ColorshaderClass::RenderShader(ID3D11DeviceContext*, int)
{
}
