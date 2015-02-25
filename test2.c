#include <windows.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR pCmdLine, int showCmd)
{
    WNDCLASSEX wc;
    HWND hWnd;
    MSG msg;

    /* initialize window class */
    wc.cbSize = sizeof(wc);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInst;
    wc.hIcon = (HICON)LoadImage(
            NULL, MAKEINTRESOURCE(IDI_APPLICATION), IMAGE_ICON,
            0, 0, LR_DEFAULTSIZE | LR_SHARED
            );
    wc.hIconSm = wc.hIcon;
    wc.hCursor = (HCURSOR)LoadImage(
            NULL, MAKEINTRESOURCE(IDC_ARROW), IMAGE_CURSOR,
            0, 0, LR_DEFAULTSIZE | LR_SHARED
            );
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = _T("Default Class Name");

    /* register window class */
    if (RegisterClassEx(&wc) == 0) { return 1; }

    /* create window */
    hWnd = CreateWindow(
            wc.lpszClassName,
            _T("はじめてのウインドウ"),  // title bar strings
            WS_OVERLAPPEDWINDOW,   // window type
            CW_USEDEFAULT,         // window positin (x)
            CW_USEDEFAULT,         //  window positin (y)
            CW_USEDEFAULT,         // window width
            CW_USEDEFAULT,         // windwo height
            NULL,                  // window handle of parent
            NULL,                  // menu handle
            hInst,                 // instance handle
            NULL                   // other create data
            );
    if(hWnd == NULL){ return 1; }

    // show window
    ShowWindow(hWnd, SW_SHOW);
    UpdateWindow(hWnd);

    // message loop
    while (1)
    {
        BOOL ret = GetMessage(&msg, NULL, 0, 0);
        if (ret == 0 || ret == -1) {
            break;
        } else {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return 0;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
    static HMENU hMenu;
    int wmId;

    switch (msg) {

        case WM_CREATE:
            hMenu = LoadMenu(NULL, "WIN_MENU");
            SetMenu(hWnd, hMenu);
            return 0;

        case WM_COMMAND:
            wmId = LOWORD(wp);
            switch (wmId) {
                case 40007:
                    MessageBox(NULL, "ツールバー","サブメニュー", MB_OK);
                    break;
                case 40008:
                    MessageBox(NULL, "イ","サブメニュー", MB_OK);
                    break;
                case 40009:
                    MessageBox(NULL, "ロ","サブメニュー", MB_OK);
                    break;
                case 40010:
                    MessageBox(NULL, "ハ","サブメニュー", MB_OK);
                    break;
                case 40012:
                    MessageBox(NULL, "使い方：ボタンを押す","help", MB_OK);
                    break;
                case 40013:
                    MessageBox(NULL, "ver0.01","バージョン情報", MB_OK);
                    break;
            }
            break;

        case WM_CLOSE:
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

    }

    return DefWindowProc(hWnd, msg, wp, lp);
}


