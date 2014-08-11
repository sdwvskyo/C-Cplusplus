#include <stdio.h>

void uppers(char *s, char *us) {
	while (*s != '\0') {
		if (*s >= 'a' && *s <= 'z')
			*us = *s - 32;
		else *us = *s;

		s++;
		us++;
	}
}

int main(void) {
	char *s, *us;
	char s1[20], s2[20];
	printf("Please enter a strig: \n");
	scanf("%s", s1);
	us = s2;
	s = s1;
	uppers(s, us);
	printf("The result is: %s", us);
	return 0;
}

