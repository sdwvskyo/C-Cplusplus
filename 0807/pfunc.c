#include <stdio.h>
#include <string.h>

char map(char ch);
void handle(char *str, char (*pfun)(char));
char change_ch(char ch);

int main(int argc, char *argv[]) 
{
	char str[1024];
	while (fflush(stdin), memset(str, 0, 1024), gets(str) != NULL) {
		handle(str, map);
		puts(str);
		handle(str, change_ch);
		puts(str);
	}
	
}

void handle(char *str,char (*pfun)(char))
{
	while(*str != '\0')	{
		*str = (*pfun)(*str);
		str++;
	}
}

char map(char ch)
{
	if (ch >= 'a' && ch <= 'z') {
		return (ch - 91) % 26 + 'a';
	}
	else if(ch >= 'A' && ch <= 'Z') {
		return (ch - 59) % 26 + 'A';
	}
	else { 
		return ch;
	}
}

char change_ch(char ch)
{
	if (ch >= 'a' && ch <= 'z') {
		return ch - 32;
	} else if (ch >= 'A' && ch <= 'Z'){
		return ch + 32;
	} else {
		return ch;
	}
}	
