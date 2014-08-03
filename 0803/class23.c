/*
【程序 23】打印出如下图案(菱形)
题目:打印出如下图案(菱形)
      * 
     *** 
    *****
   *******
	*****
	 *** 
	  *
*/

#include <stdio.h>

int main(int argc, char *argv[]) {

	int n;
	while (scanf("%d", &n) == 1) {
		
		for (int i = 0; i <= n / 2; i++) {
			for (int j = n / 2 - i; j >= 0; j--)
				printf(" ");
			for (int k = 0; k <= i * 2; k ++)
				printf("*");
			printf("\n");
		}
		for (int i = n / 2; i > 0; i--) {
			for (int j = 0; j <= n / 2 - i + 1; j++)
			   printf(" ");
			for (int k = i * 2 - 1; k > 0; k--)
				printf("*");
			printf("\n");
		}
	}
	return 0;
}


