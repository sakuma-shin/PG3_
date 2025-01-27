#include <stdio.h>
#include <Windows.h>
#include <chrono>
#include <iostream>
#include <string>

int main() {
	// 100,000文字のstd::stringを初期化
	std::string original(100000, 'a');

	// コピー操作の計測
	auto startCopy = std::chrono::high_resolution_clock::now();
	std::string copy = original; // コピー
	auto endCopy = std::chrono::high_resolution_clock::now();

	// 移動操作の計測
	auto startMove = std::chrono::high_resolution_clock::now();
	std::string moved = std::move(original); // ムーブ
	auto endMove = std::chrono::high_resolution_clock::now();

	// 計測結果をps（マイクロ秒）で表示
	auto copyDuration = std::chrono::duration_cast<std::chrono::microseconds>(endCopy - startCopy).count();
	auto moveDuration = std::chrono::duration_cast<std::chrono::microseconds>(endMove - startMove).count();

	std::cout << "Copy operation time: " << copyDuration << " microSecond\n";
	std::cout << "Move operation time: " << moveDuration << " microSecond\n";

	return 0;
}
