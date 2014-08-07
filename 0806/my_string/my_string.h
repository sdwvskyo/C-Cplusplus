#ifndef _MY_STRING_H
#define _MY_STRING_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

void str_init_num(char *str, int len);

void str_init(char *str, int len);

void str_cpy(char *dst, const char *src);

void str_cat(char *s1, const char *s2);

int str_cmp(const char *s1, const char *s2);

int my_atoi(const char *tr);

void my_itoa(char *str, int num);

int word_cnt(char *str);

void word_split(const char *str);

void delete_space(char *str);

void replace_space(const char *str, const char *rpl);

void rever_word(char *str);

void sort_str(const char *str);
#endif
