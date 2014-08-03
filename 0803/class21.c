/*
【程序 21】 题目:猴子吃桃问题:猴子第一天摘下若干个桃子,当即吃了一半,还不瘾,又多吃了一个 第二天早上又将剩下的桃子吃掉一半,又多吃了一个。以后每天早上都吃了前一天剩下 的一半零一个。到第 10 天早上想再吃时,见只剩下一个桃子了。求第一天共摘了多少。
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int sum = 1;
	for (int i = 1; i <= 10; i++) {
		sum++;
		sum *= 2;
		printf("daoshu di %d tian you %d ge taozi.\n", i + 1, sum);
	}

	return 0;
}
