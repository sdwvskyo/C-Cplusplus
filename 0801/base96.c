/*
96: 第 96 题 请编写函数 fun,其功能使:计算并输出给定数组(长度为 9)中每相邻两个元素 之平均值的平方根之和。
*/

double fun(double x[9]) {
	double sum = 0.0;
	for (int i = 0; i < 8; i++) {
		sum += sqrt((x[i] + x[i+1]) / 2);
	}

	return sum;
}

