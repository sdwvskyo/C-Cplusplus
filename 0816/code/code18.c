/*************************************************************************
	> File Name: code18.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 日  8/17 00:14:35 2014
 ************************************************************************/
//18.约瑟夫问题:
//N 个人围成一个圆圈,首先第一个人从 1 开始一个人一个人顺时针报数,报道第 m 个人, 令其出列。然后再从下一个人开始,从 1 顺时针报数,报道第 m 个人,在令其出列,....如此 下去,直到圈中只剩下一个人为止。此人即为优胜者。写一个函数求 N 个人中的胜者。 例如:N=8,m= 5,则得到的出列次序为 4,8,5,2,1,3,7,6.最后的胜者为 6。

#include<stdio.h>

int main(int argc, char *argv[])
{
	int n, m;
	while (scanf("%d%d", &n, &m) == 2) {
		int ar[n];
		int i;
		for (i = 0; i < n; i++) {
			ar[i] = 1;
		}
		int index = - 1;
		for (i = 0; i < n; i++) {
			int cnt = 0;
			while (cnt < m) {
				index = (index + 1) % n;
				if (ar[index] != 0) {
					cnt++;
				}
			}
			ar[index] = 0;
			printf("%d,", index + 1);
		}
		printf("\n");
	}
	return 0;
}
