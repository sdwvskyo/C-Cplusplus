/*
99: 第 99 题 请编写函数 fun ,其功能是:计算并输出 3 到 n 之间所有素数的平方根之和。
*/

double fun(int n) {
	double sum = 0;
	for (int i = 3; i < n; i++) {
		int n = (int)sqrt(i);
		for (int j = 2; j <= n + 1; j++) {
			if (i % j == 0)
				break;
		}
		if (j == n + 1)
			sum += sprt(i);
	}
	return sum;
}

