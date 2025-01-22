#pragma once
#include "OverScene.h"

void OverScene::Initialize() {}

void OverScene::Update(char* keys, char* preKeys) {
	// スペースキーを押した瞬間
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		// シーンをTITLEに切り替える
		IScene::sceneNo = TITLE;
	}
}

void OverScene::Draw() {
	Novice::ScreenPrintf(0, 0, "Over Scene");
	Novice::ScreenPrintf(0, 30, "Push Space");
}
