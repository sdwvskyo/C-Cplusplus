/*************************************************************************
	> File Name: execlp_test.c
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 日  8/17 10:35:38 2014
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	execlp("ps", "ps", "-o", "pid,ppid,pgrp,session,tpgid,comm", NULL);
	perror("exec ps");
	exit(1);	
}

