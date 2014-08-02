/*
  1: 第 1 题 m 个人的成绩存放在 score 数组中,请编写函数 fun,它的功能是:将低于平均分
的人作为函数值返回,将低于平均分的分数放在 below 所指定的函数中。
*/

int fun(int *score, int m, int *below) {
	int counter = 0;
	int aver = 0;

	for (int i = 0; i < m; i++)
		aver += score[i];
	aver /= m;
	
	for (int i = 0; i < m; i++) {
		if (score[i] < aver) {
			below[counter++] = score[i];
		}
	}
	return counter;
}
