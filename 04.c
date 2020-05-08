//これやるならＤＸライブラリ使ってｃ＋＋でやるほうがいい　visualstudioアプリケーションプロジェクトだったっけ？
#include <windows.h>

#define SCW 1280
#define SCH 720

//タイトルバーの名前
#define TNAME "サンプル"
//windowクラスの名前（適当でおk）
#define WCNAME "windowclass"

void InitWindow(HINSTANCE hInstance, const char* name, int width, int height);
//ウインドウプロシージャ
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

//ウィンドウハンドル
HWND hWnd;


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{


	//windowの初期化
	InitWindow(hInstance, TNAME, SCW, SCH);

	//メインループ
	MSG hMsg;		//メッセージ構造体変数
	while (1) {
		// メッセージがあるかどうかを調べる。
		if (PeekMessage(&hMsg, NULL, 0, 0, PM_NOREMOVE))
		{
			if (!GetMessage(&hMsg, NULL, 0, 0))	 // hMsg にメッセージを格納する
				break;
			TranslateMessage(&hMsg);	//キー入力について前処理をする関数。キー入力しない場合は省略してもよい。
			DispatchMessage(&hMsg);		//ウィンドウプロシージャにも渡メッセージ渡す
		}
		else {
			// ゲームの処理------

			//エスケープキーで終了
			if (GetKeyState(VK_ESCAPE) & 0x8000) {
				break;
			}

		}
	}

	return 0;
}







//ウインドウプロシージャ
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_KEYDOWN:			//キーが押されたとき
		break;

	case WM_CLOSE:				//ウィンドウを閉じるとき
		PostMessage(hWnd, WM_DESTROY, 0, 0);	//プロシージャにメッセージを送る
		break;

	case WM_DESTROY:			//閉じられたとき
		PostQuitMessage(0);		//アプリケーションを閉じたいときに呼ぶ
		break;
	}

	return(DefWindowProc(hWnd, message, wParam, lParam));	//いるものはswitchの中に書き、いらないものはDefWindowProcで処理させている。
}

void InitWindow(HINSTANCE hInstance, const char* name, int width, int height)
{
	//ウィンドウクラスを登録

	WNDCLASS wcex;										//大まかなウィンドウの汎用的な設定を行うクラス
	wcex.style = CS_HREDRAW | CS_VREDRAW;				//基本スタイルを表す定数
	wcex.lpfnWndProc = WndProc;							//ウインドウプロシージャ　発生したイベントを処理する
	wcex.cbClsExtra = 0;								//クラス構造体の追加領域をバイト単位で予約するもの		多くの場合0を指定
	wcex.cbWndExtra = 0;								//ウィンドウ構造体の追加領域をバイト単位で予約するもの	多くの場合0を指定
	wcex.hInstance = hInstance;							//インスタンスハンドルを渡す。
	wcex.hIcon = NULL;									//タスクバーやタイトルバーに表示されるアイコンのビットマップを指定
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW); 							//マウスカーソルを指定します
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);	//クライアントエリアの背景色を指定
	wcex.lpszMenuName = NULL;							//クラスメニューを指定
	wcex.lpszClassName = WCNAME;						//ウィンドウクラスの名前を指定
	RegisterClass(&wcex);								//上で作ったウインドウクラスを登録



	hWnd = CreateWindowEx(0,				//拡張スタイルの設定 ファイルをドラッグアンドドロップとかもある
		WCNAME,								//登録されているウインドウクラスの名前
		name,								//ウインドウ名
		WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_POPUP,	//ウインドウスタイル
		0,//CW_USEDEFAULT,						//ウインドウの横位置　適当な位置に
		0,//CW_USEDEFAULT,						//ウインドウの縦位置　適当な位置に
		width,								//ウインドウの幅
		height,								//ウインドウの高さ
		NULL,								//親ウインドウまたはオーナーウインドウのハンドル
		NULL,								//メニューハンドルまたは子ウインドウID
		hInstance,							//アプリケーションインスタンスのハンドル
		NULL);								//ウインドウ作成データ

}