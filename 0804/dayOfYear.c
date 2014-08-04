//输入日期，计算是当年的第几天，星期几；
//输入两个日期，计算相差几天；

#include <stdio.h>
#define ISLEAPYEAR(year) ((year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0)))

int dayOfYear(int year, int month, int day); //计算当年第几天
int isValid(int year, int month, int day);  //检查输入日期是否合法
int diffDay(int y1, int m1, int d1, int y2, int m2, int d2);   //计算两年之间差多少天
int dayOfWeek(int year, int month, int day); //计算星期几      

char weekday[7][10] = {"Sun", "Mon", "Tur", "Wed", "Thu", "Fri", "San"};

int main(void) {
	int y1, m1, d1;
	int y2, m2, d2;
	printf("Enter the date like: YYYYMMDD\n");
	while(fflush(stdin), scanf("%4d%2d%2d", &y1, &m1, &d1) == 3) {
		printf("Enter another date:\n");
		scanf("%4d%2d%2d", &y2, &m2, &d2);
		if(isValid(y1, m1, d1) && isValid(y2, m2, d2)) {
			printf("%d-%d-%d is %dth day of the year. %s\n", 
					y1, m1, d1, dayOfYear(y1, m1, d1), weekday[dayOfWeek(y1, m1, d1)]);
			printf("%d-%d-%d is %dth day of the year. %s\n", 
					y2, m2, d2, dayOfYear(y2, m2, d2), weekday[dayOfWeek(y2, m2, d2)]);
			printf("The sub of two date is: %d\n", diffDay(y1, m1, d1, y2, m2, d2));
		} else {
			fflush(stdin);
			continue;
		}
	}

	return 0;
}

int dayOfWeek(int year, int month, int day) {
	int n = diffDay(year, month, day, 1900, 1, 7) % 7;
	return n;
}


int diffDay(int y1, int m1, int d1, int y2, int m2, int d2) {
	int bigYear = y1 > y2 ?  y1 : y2;
	int smallYear = y1 < y2 ? y1 : y2;
	int tmp =  dayOfYear(y1, m1, d1) - dayOfYear(y2, m2, d2);
	int sum = (tmp > 0 ? tmp : -tmp);
	if (y1 != y2) {
		for(int i = smallYear; i < bigYear; i++) {
			if (ISLEAPYEAR(i)) {
				sum += 366;
			} else {
				sum += 365;
			}
		}
	}	
	return sum; 
}

int isValid(int year, int month, int day) {
	if(month > 12) {
		printf("Wrong month!Enter again.\n");
			return 0;
	} else {
		switch(month) {
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if (day > 31 || day < 1) {
					printf("Wrong day!Enter again.\n");
					return 0;
				} else
					return 1;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				if (day > 30 || day < 1) {
					printf("Wrong day!Enter again.\n");
					return 0;
				}
				break;
			case 2:
				if (ISLEAPYEAR(year)) {
					if (day > 29 || day < 1) {
						printf("Wrong day!.Enter again.\n");
						return 0;
					} else 
						return 1;
				} else {
					if (day > 28 || day < 1) {
						printf("Wrong day!.Enter again.\n");
						return 0;
					}
					else 
						return 1;
				}
				break;
			default: printf("check error!\n"); return 0;break;
		}
	}
	return 0;
}

	

int dayOfYear(int year, int month, int day) {
	int sum = 0;
	for (int i = 1; i < month; i++) {
		switch(i) {
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				sum += 31;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				sum += 30;
				break;
			case 2:
				if (ISLEAPYEAR(year)) {
					sum += 29;
				} else {
					sum += 28;
				}
				break;
			default:printf("data error!\n");break;
		}
	}
	return sum + day;
}
