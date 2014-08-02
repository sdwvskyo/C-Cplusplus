/*
95: 第 95 题 假定输入的字符串中只包含字母和*号。请编写函数 fun,它的功能是:使字符 串的前导*号不得多于 n 个;若多于 n 个,则删除多于的*号;若少于或等于 n 个,则什么 也不做。字符串中间和尾部的*号不删除。
*/

void fun(char *a, int n) {
	int cnt = 0;
	char *tmp;
	while (*a) {
		a++;
		cnt++;
	}
	if (cnt > n)
		temp = a + cnt -n;
	int i = 0;
	while (*temp) {
		a[i]  = *temp;
		i++;
		temp++;
	}
	a[i] = '\0';
}



