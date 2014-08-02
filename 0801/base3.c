/*
3: 第 3 题 请编写函数 void fun(int x,int pp[],int *n),它的功能是:求出能整除 x 且不是偶数的 各整数,并按从小到大的顺序放在 pp 所指的数组中,这些除数的个数通过形参 n 返回。
*/

void fun(int x, int pp[], int *n) {
	*n = 0;
	for (int i = 0; i < x; i++) {
		if (i % 2 != 0) {
			if ( x % i == 0)
				pp[(*n)++] = i;
		}
	}
}

