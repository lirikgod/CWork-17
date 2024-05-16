#include <Windows.h>


LRESULT CALLBACK MainWinProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE h;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {

WNDCLASS wc;
HWND hwnd;
MSG msg;

wc.style = 0;
wc.lpfnWndProc = MainWinProc;
wc.cbClsExtra = wc.cbWndExtra=0;
wc.hInstance = hInst;
wc.hIcon = NULL;
wc.hCursor = NULL;
wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
wc.lpszMenuName = "testprogram17";
wc.lpszClassName = "class_test_program";

if(!RegisterClass(&wc)) { return FALSE; }

hwnd = CreateWindowA("class_test_program", "testprogram17", WS_OVERLAPPEDWINDOW,
                     CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL,hInst,NULL);

if(!hwnd) { return FALSE; }

ShowWindow(hwnd, nShowCmd);
UpdateWindow(hwnd);

while (GetMessage(&msg, NULL, 0, 0)) {
TranslateMessage(&msg);
DispatchMessage(&msg);
}

return msg.wParam;
}

LRESULT CALLBACK MainWinProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {

switch (msg) {

case WM_CREATE:
CreateWindow("Button", TEXT("Button1"), WS_CHILD | WS_VISIBLE | BS_TEXT, 0, 0
, 80, 30, hwnd, (HMENU)1, NULL, NULL);

CreateWindow("Button", TEXT("Button2"), WS_CHILD | WS_VISIBLE | BS_TEXT, 100, 0
, 80, 30, hwnd, (HMENU)2, NULL, NULL);

CreateWindow("Button", TEXT("Button3"), WS_CHILD | WS_VISIBLE | BS_TEXT, 200, 0
, 80, 30, hwnd, (HMENU)3, NULL, NULL);
return 0;

case WM_COMMAND:
if (LOWORD(wp) == 1) {
MessageBox(hwnd, "modal button", "test", MB_OK | MB_ICONINFORMATION | MB_ABORTRETRYIGNORE);
} else if (LOWORD(wp) == 2) {
MessageBox(NULL, "non-modal button", "test", MB_OK | MB_ICONINFORMATION);
} else if (LOWORD(wp) == 3) {
MessageBox(hwnd, "win1", "test3", MB_HELP | MB_ICONINFORMATION | MB_ICONQUESTION);
MessageBox(hwnd, "win2", "test3", MB_HELP |  MB_ICONQUESTION);
}
return 0;

case WM_DESTROY:
PostQuitMessage(0);
return 0;

}

return DefWindowProc(hwnd, msg, wp, lp);
}