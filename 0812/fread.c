#include <stdio.h>
int main(void)
{
	int ar[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	FILE *fp = fopen("fread.txt", "w+");
	int count;
	count = fwrite(ar, sizeof(int), 10, fp);
	printf("count = %d\n", count);
	int val[1];
	fread(val, 4, 1, fp);
	printf("read val = %d\n", val[0]);
	fclose(fp);
	return 0;
}
