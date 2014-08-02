/*
4: 第 4 题 请编写一个函数 void fun(char *tt,int pp[]),统计在 tt 字符中"a"到"z"26 各字母各自 出现的次数,并依次放在 pp 所指的数组中。
*/

void fun(char *tt, int pp[]) {
	for (int i = 0; i < 26; i++)
		pp[i] = 0;
	int n = 0;
	int temp;
	while(tt[n] != '\0') {
		if (tt[n] >= 'a' && tt[n] <= 'z') {
			temp = tt[n] - 'a';
			pp[temp]++
		}
		n++; 
	}
}

	


