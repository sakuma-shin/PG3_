#pragma once
#include <KamataEngine.h>

class Player {
public:
	Player();
	~Player();

	void Initialize(/*KamataEngine::Vector2 position,uint32_t textureHandle*/);
	void Update(/*char* keys*/);
	void Draw();

private:
	 KamataEngine::Vector2 position_;
	 KamataEngine::Vector2 velocity_;
	 uint32_t textureHandle_;
	 int width_;
	 int height_;
	 KamataEngine::Input* input_ = nullptr;
};
