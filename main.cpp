#include <Windows.h>
#include <stdio.h>
#include <iostream>

// Enemyクラス
class Enemy {
public:
	void Update(); // 更新関数

	void Approach(); // 状態関数1: 接近
	void Shoot();    // 状態関数2: 射撃
	void Leave();  // 状態関数3: 離脱

	// メンバ関数ポインタのテーブル
	static void (Enemy::*stateTable[])();

private:
	int stateIndex = 0; // 状態を参照するインデックス
};

void Enemy::Approach() { std::cout << "敵の接近" << std::endl; }

void Enemy::Shoot() { std::cout << "敵の射撃" << std::endl; }

void Enemy::Leave() { std::cout << "敵の離脱" << std::endl; }

void Enemy::Update() {
	// 現在の状態を実行
	(this->*stateTable[stateIndex])();
		// 次の状態に遷移
		stateIndex = (stateIndex + 1) % 3;
	
}

// static宣言したメンバ関数ポインタテーブルの実体
void (Enemy::*Enemy::stateTable[])() = {
    &Enemy::Approach, // インデックス番号0
    &Enemy::Shoot,    // インデックス番号1
    &Enemy::Leave   // インデックス番号2
};

int main() {
	Enemy enemy;

	// 無限ループで敵の状態を更新
	for (int i = 0; i < 3; i++) {
		enemy.Update();
	}

	return 0;
}
