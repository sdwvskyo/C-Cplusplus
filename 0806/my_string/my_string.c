#include "my_string.h"

static int my_isspace(char ch)
{
	return ch == ' ' || ch == '\t' || ch == '\v' || ch == '\n';
}

static void rever_str(char *str, int start, int end)
{
	while (start < end) {
		char tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}	
}

void str_init_num(char *str, int len)
{
	int i;
	if (rand() % 2 == 0) {
		*str++ = '-';
	}
	*str++ = rand() % 9 + 49;

	for (i = 1; i < len; i++) {
		*str++ = rand() % 10 + 48;
	}
	*str = '\0';
}

void str_init(char *str, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		if(rand() % 2 == 0) {
			*str++ = rand() % 26 + 97;
		} else {
			*str++ = rand() % 26 + 65;
		}
	}
	*str = '\0';
}

void str_cpy(char *dst, const char *src)
{
	assert(dst && src);
	const char *p = src;
	while (*p++ != '\0')
		dst++;
	while (p != src)
		*dst-- = *(--p);
}

void str_cat(char *s1, const char *s2)
{
	assert(s1 && s2);
	while (*s1++ != '\0')
		;
	s1--;
	while ((*s1++ = *s2++) != '\0')
		;
}

int str_cmp(const char *s1, const char *s2)
{
	assert(s1 && s2);
	while (*s1 != '0' && *s1++ == *s2++)
		;
	return *(--s1) - *(--s2);
}

int my_atoi(const char *str)
{
	int num = 0;
	int flag = 0;
	if (*str == '-' || *str == '+') {
		if(*str == '-') {
			flag = 1;
		} else {
			flag = 0;
		}
		str++;
	}

	while (*str != '\0') {
		if (*str < '0' || *str > '9') {
			break;
		}
		num = num * 10 + *str - '0';
		str++;
	}
	return flag ? -num : num;
}

void my_itoa(char *str, int num)
{
	int index = 0;
	int tmp = num;
	do {
		tmp /= 10;
		index++;
	} while(tmp != 0);

	if (num < 0) {
		*str = '-';
		index++;
		num = -num;
	}

	str[index--] = '\0';
	do {
		str[index--] = num % 10 + 48;
		num /= 10;
	} while(num != 0);
}

int word_cnt(char *str) 
{
	int word = 0;
	int cnt = 0;
	while (*str != '\0') {
		if (my_isspace(*str)) {
			word = 0;
		} else if (word == 0) {
			cnt++;
			word = 1;
		}
		str++;
	}
	return cnt;
}

void word_split(const char *str)
{
	int word = 0;
	while (*str != '\0') {
		if (my_isspace(*str)) {
			if (word == 1) {
				word = 0;
				putchar('\n');
			}
		} else {
			putchar(*str);
			if (word == 0) {
	word = 1;
			}
		}
		str++;
	}
	putchar('\n');
}



void delete_space(char *str)
{
	int word = 0;
	int start = 0;
	int end = 0;
	while (str[end] != '\0') {
		if (my_isspace(str[end])) {
			if (word == 1) {
				word = 0;
				str[start++] = ' ';
			}
			end++;
		} else {
			str[start++] = str[end++];
			if (word == 0) {
				word = 1;
			}
		}
	}
	str[--start] = '\0';
	puts(str);
}


void replace_space(const char *str, const char *rpl)
{
	char ar[100*4];
	ar[0] = '\0';
	int index = 0;
	while (*str != '\0') {
		if (my_isspace(*str)) {
			str_cat(ar, rpl);
			index += 4;
		} else {
			ar[index++] = *str;
			ar[index] = '\0';
		}
		str++;
	}
	puts(ar);
}

void rever_word(char *str) 
{
	int index = 0;
	char *p = str;
	while (*p++ != '\0') {
		index++;
	}
	rever_str(str, 0, index - 1);

	int word = 0;
	int start = 0;
	int end =0;
	while (str[end] != '\0') {
		if (my_isspace(str[end])) {
			if (word == 1) {
				word = 0;
				rever_str(str, start, end - 1);
			}
		} else if (word == 0){
				word = 1;
				start = end;
			}
		end++;
	}
	if (!my_isspace(str[end])) {
		rever_str(str, start, end - 1);
	}
	puts(str);
}

static void str_ncpy(char *dst, const char *src, int start, int end)
{
	while (start <= end) {
		*dst++ = src[start++];
	}
	*dst = '\0';
}

static void sort_word(char ar[][100], int n) 
{
	int i, j;
	for(i = 0; i < n; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (str_cmp(ar[j], ar[j+1]) > 0) {
				char tmp[100];
				str_cpy(tmp, ar[j]);
				str_cpy(ar[j], ar[j+1]);
				str_cpy(ar[j+1], tmp);
			}
		}
	}
}

static void print_word(char ar[][100], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		puts(ar[i]);
	}
}

void sort_str(const char *str)
{
	char ar[100][100];
	int index = 0;
	int word = 0;
	int start = 0;
	int end = 0;
	while (str[end] != '\0') {
		if (my_isspace(str[end])) {
			if (word == 1) {
				word = 0;
				str_ncpy(ar[index], str, start, end - 1);
				index++;
			}
		} else if (word == 0){
				word = 1;
				start = end;
			}
		end++;
	}
	if (!my_isspace(--end)) {
		str_ncpy(ar[index++], str, start, end);
	}
	sort_word(ar, index);
	print_word(ar, index);
}
