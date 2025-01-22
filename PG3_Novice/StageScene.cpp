#include "StageScene.h"

void StageScene::Initialize() {
	// プレイヤー初期化
	/*player_.Initialize();*/
}

void StageScene::Update(char* keys, char* preKeys) {

	if (sceneNo == STAGE) {
		// プレイヤー移動処理
		//	player_.Update(keys);

		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
			// シーンをCLEARに変える
			sceneNo = CLEAR;
		}
		if (keys[DIK_T] && !preKeys[DIK_T]) {
			// シーンをOVERに変える
			sceneNo = OVER;
		}
	}
}

void StageScene::Draw() {
	if (sceneNo == STAGE) {
		Novice::ScreenPrintf(0, 0, "Stage Scene");
		Novice::ScreenPrintf(0, 30, "CLEAR = Push Space");
		Novice::ScreenPrintf(0, 60, "OVER = Push T");
		player_.Draw();
	}
}
