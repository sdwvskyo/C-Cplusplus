/*
【程序 2】企业利润计算(switch)
题目:企业发放的奖金根据利润提成。利润(I)低于或等于 10 万元时,奖金可提 10%;利润高于 10 万元, 低于 20 万元时,低于 10 万元的部分按 10%提成,高于 10 万元的部分,可可提成 7.5%;20 万到 40 万之 间时,高于 20 万元的部分,可提成 5%;40 万到 60 万之间时高于 40 万元的部分,可提成 3%;60 万到 100 万之间时,高于 60 万元的部分,可提成 1.5%,高于 100 万元时,超过 100 万元的部分按 1%提成,从 键盘输入当月利润 I,求应发放奖金总数?
*/

#include <stdio.h>

int main(void) {
	int bonus = 0;
	int bonus10 = 100000 * 0.1;
	int bonus20 = bonus10 + 100000* 0.075;
	int bonus40 = bonus20 + 200000 * 0.05;
	int bonus60 = bonus40 + 200000 * 0.03;
	int bonus100 = bonus60 + 400000 * 0.015;

	long profit;
	printf("Enter the profit: \n");
	while (scanf("%ld", &profit) != EOF) {
		if (profit < 0)
			break;
		if (profit <= 100000)
			bonus = profit * 0.1;
		else if (profit <= 200000)
			bonus = bonus10 + (profit - 100000) * 0.075;
		else if (profit <= 400000)
			bonus = bonus20 + (profit - 200000) * 0.05;
		else if (profit <= 600000)
			bonus = bonus40 + (profit - 400000) * 0.03;
		else if (profit <= 1000000)
			bonus = bonus60 + (profit - 600000) * 0.015;
		else
			bonus = bonus100 + (profit - 1000000) * 0.01;
		printf ("bonus = %d\n", bonus);	
	}
	return 0;
}
