#include "GameManager.h"
#include <Novice.h>



const char kWindowTitle[] = "LE2C_10_サクマ_シン_PG3";

// Windowsアプリでのmain関数
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// GameManegerクラスのインスタンスを作成する
	GameManager* gameManager = new GameManager();

	// GameManegerクラスからメンバ関数Runを呼び出す
	gameManager->Run();

	// ライブラリの終了
	Novice::Finalize();

	// GameManegerを解放
	delete gameManager;

	return 0;
}
