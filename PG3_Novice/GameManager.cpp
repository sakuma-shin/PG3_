#include "GameManager.h"

/// コンストラクタによる初期化処理
GameManager::GameManager() {

	// 各シーンの配列
	sceneArr_[TITLE] = std::make_unique<TitleScene>(); // シーンタイトル
	sceneArr_[STAGE] = std::make_unique<StageScene>(); // シーンゲーム
	sceneArr_[CLEAR] = std::make_unique<ClearScene>(); // シーンクリア
	sceneArr_[OVER] = std::make_unique<OverScene>();   // シーンオーバー

	// 初期シーンをタイトルに設定する
	currentSceneNo_ = TITLE;
	prevSceneNo_ = 0;
}

// デストラクタによるdelete処理
GameManager::~GameManager() {}

int GameManager::Run() {

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	while (Novice::ProcessMessage() == 0) {
		Novice::BeginFrame(); // フレームの開始

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		// シーンのチェック
		prevSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

		// シーン変更チェック
		if (prevSceneNo_ != currentSceneNo_)
			sceneArr_[currentSceneNo_]->Initialize();

		/// ↓更新処理ここから
		// シーンごとの更新処理
		sceneArr_[currentSceneNo_]->Update(keys, preKeys);
		/// ↑更新処理ここまで

		/// ↓描画処理ここから
		// シーンごとの描画処理
		sceneArr_[currentSceneNo_]->Draw();
		/// ↑描画処理ここまで

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0)
			break;
	}

	return 0;
}
