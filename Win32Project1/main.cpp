#include <Windows.h>


LRESULT CALLBACK  WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance, 
	_In_ LPSTR lpCmdLine, 
	_In_ int nShowCmd) {

	MSG uMsg;
	HWND hWnd;

	WNDCLASS wc = { 0 };
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = TEXT("CLASSNAME");
	wc.style = CS_VREDRAW | CS_HREDRAW;

	//ע�ᴰ��
	if (!RegisterClass(&wc))
	{
		MessageBox(NULL, TEXT("ERROR"), nullptr, MB_OK);
		return 0;
	}
	//��������
	hWnd = CreateWindow(
		TEXT("CLASSNAME"), 
		TEXT("����һ������"), 
		WS_SYSMENU, 
		100, 
		100, 
		500, 
		680, 
		nullptr, 
		nullptr, 
		hInstance, nullptr);
	if (hWnd==nullptr)
	{
		MessageBox(nullptr,TEXT("���ڴ���ʧ��"),nullptr,MB_OKCANCEL);
		return 0;
	}
	//��ʾ����
	ShowWindow(hWnd, nShowCmd);
	//�޸Ĵ���
	UpdateWindow(hWnd);

	while (GetMessage(&uMsg,hWnd,0,0)>0)
	{
		TranslateMessage(&uMsg);
		DispatchMessage(&uMsg);
	}
	return uMsg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:

		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;
}