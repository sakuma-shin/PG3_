#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

// コールバック関数の型を定義
typedef void (*Callback)(int);

// サイコロを振る関数（抽選結果をランダムで決める）
int RollDice() {
    return rand() % 6 + 1;
}

// 結果を判定し、コールバック関数を呼び出す
void CheckResult(int result, int guess, Callback callback) {
    // 三秒間待機
    Sleep(3000);
    // コールバック関数を呼び出し
    callback(result == guess);
}

// 結果を表示するコールバック関数
void ShowResult(int is_correct) {
    if (is_correct) {
        printf("当たりです\n");
    } else {
        printf("ハズレです\n");
    }
}

int main() {
    // 乱数の種を設定
    srand(time(nullptr));

    // サイコロの出目を決定
    int diceResult = RollDice();

    // 出目の奇数・偶数を判定
    int diceParity = diceResult % 2;

    // ユーザーから奇数か偶数かの入力を受け取る
    int userGuess;
    printf("奇数(1)か偶数(0)かを当ててください: ");
    scanf_s("%d", &userGuess);

    // 結果を判定し、コールバック関数を使用
    CheckResult(diceParity, userGuess, ShowResult);

    return 0;
}
