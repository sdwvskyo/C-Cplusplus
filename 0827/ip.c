/*************************************************************************
	> File Name: ip.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 三  8/27 15:39:51 2014
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#define IS_IP(n) ((n <= 255) && (n >= 0))

int ip_transform(char *str)
{
	int ar[4];
	int ip;
	sscanf(str, "%d.%d.%d.%d", &ar[0], &ar[1], &ar[2], &ar[3]);
	for (int index = 0; index < 4; index++) {
		if (!IS_IP(ar[index])) {
			printf("IP format wrong!\n");
			return 0;
		}
		ar[0] |= ar[index] << (index * 8);
	}
	return ar[0];
}

int hton1(int ip)
{
	int result = 0;
	int index1, index2;
	for (index1 = 0, index2 = 3; index1 < 4; index1++, index2--) {
		result |= ((ip >> index1 * 8) & 0xff) << index2 * 8;
	}
	return result;
}

int hton2(int ip) 
{
	char *ch = (char *)&ip;
	char tmp = ch[0];
	ch[0] = ch[3];
	ch[3] = tmp;
	tmp = ch[1];
	ch[1] = ch[2];
	ch[2] = tmp;
	return ip;
}

int main(int argc, char *argv[])
{
	char str[20];
	int small;
	int big;
	while (memset(str, 0, 20), fgets(str, 20, stdin)) {
		small = ip_transform(str);
		big = (hton2(small));
		printf("small: %x, big: %x\n", small, big);
	}
	return 0;
}

