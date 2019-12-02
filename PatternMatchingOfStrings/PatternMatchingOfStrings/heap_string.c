#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "heap_string.h"

void init_hstring(HString* s)
{
	s->ch = NULL;
	s->length = 0;
}

void hstring_assign(HString* s, char* ch)
{
	int i;

	if (s->ch != NULL)
		free(s->ch);
	for (i = 0; ch[i] != '\0'; i++);
	if (i == 0)
	{
		s->ch = NULL;
		s->length = 0;
	}
	else
	{
		s->length = i;
		s->ch = (char*)malloc((i + 1) * sizeof(char));
		if (s->ch == NULL)
		{
			printf("\nmalloc failure!!!");
			exit(OVERFLOW);
		}
		strcpy_s(s->ch, i + 1, ch);
	}
}

int index(HString* s, HString* sub, int position)
{
	/*
		1 <= position <= s->length
	*/
	int i, j;

	if (position < 1 || position > s->length)
	{
		printf("\nError: invalid parameter!!!");
		exit(INFEASIBLE);
	}
	i = position - 1;
	j = 0;
	while (i < s->length && j < sub->length)
	{
		if (s->ch[i] == sub->ch[j])
		{
			++i; ++j;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= sub->length)
		return i - j + 1;
	else
		return -1;
}
