#include "holy_bible.h"

int main(int argc, char *argv[])
{
	clock_t start, end;
	start = clock();
	pNode L = NULL;
	sortByWordOder("the_holy_bible123.txt", &L);
	end = clock();
	printf("Word sort Time: %.2f\n", (float)(end - start) / CLOCKS_PER_SEC);
	sortByFreq(&L);
	end = clock();
	printf("Freq sort Time: %.2f\n", (float)(end - start) / CLOCKS_PER_SEC);
	printLinkList(L, 20);


	return 0;
}
