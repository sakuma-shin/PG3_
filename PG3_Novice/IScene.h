#pragma once
#include <Novice.h>

// シーン名を列挙で定義
enum Scene {
	TITLE,
	STAGE,
	CLEAR,
	OVER,
};

// シーン内での処理を行う基底クラス
class IScene {
protected:
	// シーン番号を管理する変数
	static int sceneNo;

public:
	// 継承先で実装される関数
	// 抽象クラスなので純粋仮想関数

	// 初期化処理
	virtual void Initialize() = 0;

	// 更新処理
	virtual void Update(char* keys, char* preKeys) = 0;

	// 描画処理
	virtual void Draw() = 0;

	// 仮想デストラクタ
	virtual ~IScene();

	// シーン番号ゲッタ
	int GetSceneNo();
};
