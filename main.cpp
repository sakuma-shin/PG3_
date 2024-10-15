#include<stdio.h>
#include<Windows.h>

float Pay(int n,float firstPay) {
	if (n <= 1) {
		return firstPay;
	}

	return Pay(n - 1, firstPay * 2.0f - 50.0f) ;
}
int main() {
	
	
	float pay = 100.0f;
	float hourlyPay = 1072.0f;
	int workTime = 8;

	//再帰的な給料計算
	pay=Pay(workTime, pay);

	//一般的な給料計算
	hourlyPay*=static_cast<float>(workTime);


	printf("一般的な資金体系の%d時間の給料は%f円\n", workTime, hourlyPay);
	printf("再帰的な資金体系の%d時間の給料は%f円\n", workTime, pay);

	
	return 0;
}