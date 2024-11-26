#include<stdio.h>
#include<windows.h>
#include <iostream>
#include <list>


int main() {
    // 山手線の1970年の駅リスト (英語表記)
    std::list<const char*> yamanote1970 = {
        "Tabata", "Nippori", "Ueno", "Okachimachi", "Akihabara", "Kanda", "Tokyo",
        "Yurakucho", "Shimbashi", "Hamamatsucho", "Tamachi", "Shinagawa", "Osaki",
        "Gotanda", "Meguro", "Ebisu", "Shibuya", "Harajuku", "Yoyogi", "Shinjuku",
        "Shin-Okubo", "Takadanobaba", "Mejiro", "Ikebukuro", "Otsuka", "Sugamo",
        "Komagome", "Tabata"
    };

    // 西日暮里駅 (1971年開業) を適切な位置に挿入
    auto it = yamanote1970.begin();
    while (*it != "Nippori") ++it;
    yamanote1970.insert(it, "Nishi-Nippori");

    std::cout << "1970の山手線の駅:\n";
    for (const char* station : yamanote1970) {
        std::cout << station << std::endl;
    }

    // 2019年の駅リスト (高輪ゲートウェイ駅は未開業)
    std::list<const char*> yamanote2019 = yamanote1970;

    std::cout << "\n2019の山手線の駅:\n";
    for (const char* station : yamanote2019) {
        std::cout << station << std::endl;
    }

    // 高輪ゲートウェイ駅 (2020年開業) を挿入
    it = yamanote2019.begin();
    while (*it != "Tamachi") ++it;
    ++it; // Shinagawa の後に挿入
    yamanote2019.insert(it, "Takanawa Gateway");

    std::cout << "\n2022年の山手線の駅\n";
    for (const char* station : yamanote2019) {
        std::cout << station << std::endl;
    }

    return 0;
}
