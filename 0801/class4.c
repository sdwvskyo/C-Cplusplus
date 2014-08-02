/*
【程序 4】年月日判断是年份的第几天。 题目:输入某年某月某日,判断这一天是这一年的第几天?
*/

#include <stdio.h>

int main(void) {
	int year, month, day, sum, leap = 0;
	printf("Please input year,month,day\n");
	while (scanf("%d,%d,%d", &year, &month, &day) == 3) {
		switch(month) {
			case 1 : sum = 0; break;
			case 2 : sum = 31; break;
			case 3 : sum = 59; break;
			case 4 : sum = 90; break;
			case 5 : sum = 120; break;
			case 6 : sum = 151; break;
			case 7 : sum = 181; break;
			case 8 : sum = 212; break;
			case 9 : sum = 243; break;
			case 10 : sum = 273; break;
			case 11 : sum = 304; break;
			case 12 : sum = 334; break;
			default : printf("month is wrong!\n"); break;
		}
		sum += day;
		if ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0)
			leap = 1;
		if (leap == 1 && month > 2)
			sum++;
		printf("It is the %dth day.\n", sum);
	}
	return 0;
}

