#include "my_string.h"

#define N 100

int main(int argc, char *argv[]) 
{
	char str[N];
	gets(str);
	int num = word_cnt(str);
	printf("word =  %d\n", num);
	puts("Replace space by %020: ");
	replace_space(str, "%020");
	//printf("Delete space:\n");
	//delete_space(str);
	//puts("List every word:");
	//word_split(str);

	//puts("Reversal :");
	//rever_word(str);

	puts("Sort word: ");
	sort_str(str);
	/*
	srand(time(NULL));
	char a[N];
	char b[N];
	str_init(a, rand() % N);
	puts(a);

	puts("strcpy:");
	str_cpy(b, a);
	puts(b);

	puts("\n");
	puts("strcat:");
	str_cat(b, a);
	puts(b);

	puts("\n");
	str_init(a, rand() % N);
	puts(a);
	str_init(b, rand() % N);
	puts(b);
	puts("strcmp:");
	int n = str_cmp(a, b);
	printf("%d\n", n);

	printf("atoi: \n");
	str_init_num(a, rand() % 9);
	puts(a);
	printf("atoi result: %d\n", my_atoi(a));

	int num;
	printf("itoa:\n");
	scanf("%d", &num);
	my_itoa(a, num);
	printf("itoa result: %s\n", a);
	*/
	return 0;
}
