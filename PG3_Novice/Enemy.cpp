#include "Enemy.h"

using namespace KamataEngine;
void Enemy::Initialize(Vector2 enemyPos) { 
	pos_ = enemyPos;
	radius_ = 16.0f;
	input_ = Input::GetInstance();
}
