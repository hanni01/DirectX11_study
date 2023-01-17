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
	//���� �� �ȼ� ���̴� �ʱ�ȭ
	WCHAR vs[] = L"../Dx11Demo_04/Color.vs";
	WCHAR ps[] = L"../Dx11Demo_04/Color.ps";
	return InitializeShader(device, hwnd, vs, ps);
}

void ColorshaderClass::shutdown()
{
	//���� �� �ȼ� ���̴��� ���õ� ��ü ����
	ShutdownShader();
}

bool ColorshaderClass::Render(ID3D11DeviceContext* deviceContext, int indexCount, XMMATRIX worldMatrix, XMMATRIX viewMatrix, XMMATRIX projectionMatrix)
{
	if (!SetShaderParameters(deviceContext, worldMatrix, viewMatrix, projectionMatrix))
	{
		return false;
	}

	//������ ���۸� ���̴��� ������
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
