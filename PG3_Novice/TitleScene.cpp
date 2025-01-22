#include "TitleScene.h"

void TitleScene::Initialize() {}

void TitleScene::Update(char* keys, char* preKeys) {

	// スペースキーを押した瞬間
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		// シーンをSTAGEに切り替える
		sceneNo = STAGE;
	}
}

void TitleScene::Draw() {
	Novice::ScreenPrintf(0, 0, "Title Scene");
	Novice::ScreenPrintf(0, 30, "Push Space");
}
