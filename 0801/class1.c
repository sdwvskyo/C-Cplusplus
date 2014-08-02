/*
【程序 1】1~4 组成无重复数字的三位数。
题目:有 1、2、3、4 个数字,能组成多少个互不相同且无重复数字的三位数?都是多少? 1.程序分析:可填在百位、十位、个位的数字都是 1、2、3、4。组成所有的排列后再去掉不满足条件的排 列。
*/

#include <stdio.h>

int main(void) {
	for (int i = 1; i < 5; i++)
		for (int j = 1; j < 5; j++)
			for (int k = 1; k < 5; k++)
				if (i != j && i != k && j != k)
					printf("%d%d%d\n",i, j, k);
	printf("\n");
	return 0;
}

