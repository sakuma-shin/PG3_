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
