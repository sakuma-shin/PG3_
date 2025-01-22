#include "ClearScene.h"

void ClearScene::Initialize() {}

void ClearScene::Update(char* keys, char* preKeys) {
	// スペースキーを押した瞬間
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		// シーンをTITLEに切り替える
		IScene::sceneNo = TITLE;
	}
}

void ClearScene::Draw() {
	Novice::ScreenPrintf(0, 0, "Clear Scene");
	Novice::ScreenPrintf(0, 30, "Push Space");
}
