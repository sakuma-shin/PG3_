#pragma once
#include"KamataEngine.h"
using namespace KamataEngine;
class Enemy {
public:
	void Initialize(Vector2 enemyPos);

	void Update();

	void Draw();

private:
	Vector2 pos_;
	float radius_;
	Input* input_ = nullptr;
	
};
