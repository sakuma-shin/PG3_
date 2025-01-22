#pragma once
#include "ClearScene.h"
#include "IScene.h"
#include "OverScene.h"
#include "StageScene.h"
#include "TitleScene.h"
#include <memory>

/// GameManegerクラス
class GameManager {
private:
	// シーン保持メンバ関数
	std::unique_ptr<IScene> sceneArr_[4];

	// 現在のシーン
	int currentSceneNo_;

	// 1つ前のシーン
	int prevSceneNo_;

public:
	GameManager();  // コンストラクタ
	~GameManager(); // デストラクタ

	// ゲームループで呼び出す関数
	int Run();
};
