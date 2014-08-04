/*
编写程序，输入日期显示第几天，星期几。
*/

#include <stdio.h>
#define LEAP(x) ((x % 100 != 0) && (x % 4 == 0) || (x % 400 == 0)) ? 1 : 0

int dayOfMonth[13][2] = {
	0, 0,
	31, 31,
	28, 29,
	31, 31,
	30, 30,
	31, 31,
	30, 30,
	31, 31,
	31, 31,
	30, 30,
	31, 31,
	30, 30,
	31, 31
};

struct Date {
	int Day;
	int Month;
	int Year;
	void nextDay(){
		Day++;
		if (Day > dayOfMonth[Month][LEAP(Year)]) {
			Day = 1;
			Month++;
			if (Month > 12) {
				Month = 1;
				Year++;
			}
		}
	}
};

int buf[5001][13][32];

int fabs(int x) {
	return x < 0 ? -x : x;
}


int main(int argc, char *argv[]) {
	struct Date date;
	date.Day = 1;
	date.Month = 1;
	date.Year = 1;
	int cnt = 1;
	while (date.Year != 5001) {
		buf[date.Year][date.Month][date.Day] = cnt;
		date.nextDay();
		cnt++;
	}
	printf("Enter two date:year,month,day \n");
	int y1, m1, d1;
	int y2, m2, d2;
	int tmp1, tmp2, tmp3;
	printf("Enter the first day: \n");
	scanf("%d,%d,%d", &y1, &m1, &d1);
	tmp1 = buf[y1][m1][d1] - buf[y1][1][1];
	printf("This is the %dth day of %d year\n", tmp1, y1);
	tmp2 = buf[y1][m1][d1] % 7;
	printf("This is the %dth dy of the week\n", tmp2);
	printf("Enter the second day: \n");
	scanf("%d,%d,%d", &y2, &m2, &d2);
	
	tmp3 = buf[y1][m1][d1] - buf[y2][m2][d2] + 1;
	tmp3 = fabs(tmp3);

	printf("Distance: %d\n", tmp3);

	return 0;
}
