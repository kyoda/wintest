#include <windows.h>
#include <tchar.h>

//プロトタイプ宣言
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);


// 開始位置
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR pCmdLine, int showCmd)
{
    WNDCLASSEX wc;
    HWND hWnd;
    MSG msg;

    // ウィンドウクラスの情報を設定
    wc.cbSize = sizeof(wc);               // 構造体サイズ
    wc.style = CS_HREDRAW | CS_VREDRAW;   // スタイル
    wc.lpfnWndProc = WndProc;             // ウィンドウプロシージャ
    wc.cbClsExtra = 0;                    // 拡張情報１
    wc.cbWndExtra = 0;                    // 拡張情報２
    wc.hInstance = hInst;                 // インスタンスハンドル
    wc.hIcon = (HICON)LoadImage(          // アイコン
            NULL, MAKEINTRESOURCE(IDI_APPLICATION), IMAGE_ICON,
            0, 0, LR_DEFAULTSIZE | LR_SHARED
            );
    wc.hIconSm = wc.hIcon;                // 子アイコン
    wc.hCursor = (HCURSOR)LoadImage(      // マウスカーソル
            NULL, MAKEINTRESOURCE(IDC_ARROW), IMAGE_CURSOR,
            0, 0, LR_DEFAULTSIZE | LR_SHARED
            );
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // ウィンドウ背景
    wc.lpszMenuName = NULL;                     // メニュー名
    wc.lpszClassName = _T("Default Class Name");// ウィンドウクラス名

    // ウィンドウクラスを登録する
    if( RegisterClassEx( &wc ) == 0 ){ return 1; }

    // ウィンドウを作成する
    hWnd = CreateWindow(
            wc.lpszClassName,      // ウィンドウクラス名
            _T("Sample Program"),  // タイトルバーに表示する文字列
            WS_OVERLAPPEDWINDOW,   // ウィンドウの種類
            CW_USEDEFAULT,         // ウィンドウを表示する位置（X座標）
            CW_USEDEFAULT,         // ウィンドウを表示する位置（Y座標）
            CW_USEDEFAULT,         // ウィンドウの幅
            CW_USEDEFAULT,         // ウィンドウの高さ
            NULL,                  // 親ウィンドウのウィンドウハンドル
            NULL,                  // メニューハンドル
            hInst,                 // インスタンスハンドル
            NULL                   // その他の作成データ
            );
    if( hWnd == NULL ){ return 1; }

    // ウィンドウを表示する
    ShowWindow( hWnd, SW_SHOW );
    UpdateWindow( hWnd );

    // メッセージループ
    while( 1 )
    {
        BOOL ret = GetMessage( &msg, NULL, 0, 0 );  // メッセージを取得する
        if( ret == 0 || ret == -1 )
        {
            // アプリケーションを終了させるメッセージが来ていたら、
            // あるいは GetMessage() が失敗したら( -1 が返されたら ）、ループを抜ける
            break;
        }
        else
        {
            // メッセージを処理する
            TranslateMessage( &msg );
            DispatchMessage( &msg );
        }
    }

    return 0;
}

// ウィンドウプロシージャ
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
    switch( msg )
    {
        case WM_DESTROY:  // ウィンドウを破棄するとき
            PostQuitMessage( 0 );
            return 0;
    }

    // 他のメッセージは、デフォルトの処理を行う
    return DefWindowProc( hWnd, msg, wp, lp );
}
