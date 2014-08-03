/*
【程序 31】输入星期几的第一个字母来判断一下是星期几。 题目:请输入星期几的第一个字母来判断一下是星期几,如果第一个字母一样,则继续判断第二个字母。
*/

#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
	char letter;
	while ((letter = getchar()) != '\n') {
		letter = toupper(letter);
		switch(letter) {
			case 'S': printf("Please enter second letter:\n");
					  getchar();
					  if((letter = getchar()) == 'a')
						  printf("Saturday\n");
					  else if((letter = getchar()) == 'u')
						  printf("Sunnday\n");
					  else 
						  printf("data error!\n");
					  break;
			case 'F': printf("Friday\n"); break;
			case 'M': printf("Monday\n"); break;
			case 'W': printf("Wednesday\n"); break;
			case 'T': printf("Please enter second letter:\n");
					  getchar();
					  if ((letter = getchar()) == 'h')
						  printf("Thursday\n");
					  else if ((letter = getchar()) == 'u')
						  printf("tuesday\n");
					  else 
						  printf("data error!\n");
					  break;
			default: printf("data error!\n"); break;
		}
	}

	return 0;
}
