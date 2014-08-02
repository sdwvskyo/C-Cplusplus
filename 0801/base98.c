/*
98: 第 98 题 请编写函数 fun,它的功能是:计算并输出 n(包括 n)以内能被 5 或 9 整除的所 有自然数的倒数之和。
*/

double fun(int n) {
	double sum = 0;
	for (int i = 1; i <=n; i++) {
		if (i % 5 == 0 || i % 9 == 0)
			sum += 1.0 / i;
	}
	return sum;
}

