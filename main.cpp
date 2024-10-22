#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>
#include <string.h>

// SetTimeout関数のプロトタイプ宣言
void SetTimeout(int seconds, void (*func)(int, bool, bool), int diceRoll, bool userGuess, bool isEven);

// ユーザーから奇数か偶数かの入力を受け付ける関数
bool GetUserGuess() {
    char userInput[10];
    printf("サイコロの出目が奇数か偶数かを予想してください (奇数: odd, 偶数: even): ");
    scanf_s("%9s", userInput, (unsigned)_countof(userInput));

    // 入力を検証
    if (strcmp(userInput, "odd") == 0) {
        return false; // 奇数
    } else if (strcmp(userInput, "even") == 0) {
        return true; // 偶数
    }
}

// 判定関数（結果を表示する）
void Result(int diceRoll, bool userGuess, bool isEven) {
    printf("サイコロの出目は %d です。\n", diceRoll);
    if (userGuess == isEven) {
        printf("当たりです。\n");
    } else {
        printf("ハズレです。\n");
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

// サイコロを振る関数
int RollDice() {
    return rand() % 6 + 1;
}

//コールバック関数を呼び出す
void CheckResult(int result, int guess, void(*callback)(int)) {
    // 三秒間待機
    Sleep(3000);
    //呼び出し
    callback(result == guess);
}

int main() {

    srand(time(nullptr));

    // サイコロの出目を決定
    int diceResult = RollDice();

    // 出目の奇数・偶数を判定
    int diceParity = diceResult % 2;

    // ユーザーから奇数か偶数かの入力を受け取る
    int userGuess;
    printf("奇数(1)か偶数(0)かを当ててください: ");
    scanf_s("%d", &userGuess);

    // ラムダ式を使った結果表示
    CheckResult(diceParity, userGuess, [](int isCorrect) {
        if (isCorrect) {
            printf("当たりです\n");
        } else {
            printf("ハズレです\n");
        }
        });

    return 0;
}

int main() {

    srand((unsigned int)time(NULL));

    // サイコロの出目をランダムで生成（1〜6の整数）
    int diceRoll = rand() % 6 + 1;
    bool isEven = (diceRoll % 2 == 0);

    // 予想を取得
    bool userGuess = GetUserGuess();

    // 3秒待機してから結果を表示
    SetTimeout(3, Result, diceRoll, userGuess, isEven);

    return 0;
}

// SetTimeout関数の実装
void SetTimeout(int seconds, void (*func)(int, bool, bool), int diceRoll, bool userGuess, bool isEven) {
    Sleep(seconds * 1000); 
    func(diceRoll, userGuess, isEven);
}
