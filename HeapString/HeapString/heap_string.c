#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "heap_string.h"

void string_init(HString* s)
{
	s->ch = NULL;
	s->length = 0;
}

void string_insert(HString* s, int position, HString* t)
{
	/*
		insert the string t into the string s before the position-th char
	*/
	int i;
	char* ch = NULL;

	// 1 <= position <= s->length + 1
	if (position < 1 || position > s->length + 1)
	{
		printf("\nError: invalid position!!!");
		exit(INFEASIBLE);
	}
	ch = (char*)realloc(s->ch, (s->length + t->length + 1) * sizeof(char));
	if (ch == NULL)
	{
		printf("\nrealloc failure!!!");
		exit(OVERFLOW);
	}
	s->ch = ch;
	for (i = s->length - 1; i >= position - 1; --i)
	{
		s->ch[i + t->length] = s->ch[i];
	}
	for (i = 0; i < t->length; ++i)
	{
		s->ch[i + position - 1] = t->ch[i];
	}
	s->ch[s->length + t->length] = '\0';
	s->length += t->length;
}

void string_assign(HString* s, char* ch)
{
	int i;
	
	if (s->ch != NULL)
		free(s->ch);
	for (i = 0; ch[i] != '\0'; ++i);
	if (i == 0)
	{
		s->ch = NULL;
		s->length = 0;
	}
	else
	{
		s->ch = (char*)malloc((i + 1) * sizeof(char));
		if (s->ch == NULL)
		{
			printf("\nmalloc failure!!!");
			exit(OVERFLOW);
		}
		s->length = i;
		strcpy_s(s->ch, s->length + 1, ch);
	}
}

int string_compare(HString* s1, HString* s2)
{
	int i;

	for (i = 0; i < s1->length && i < s2->length; ++i)
	{
		if (s1->ch[i] != s2->ch[i])
			return s1->ch[i] - s2->ch[i];
	}
	return s1->length - s2->length;
}

void clear_string(HString* s)
{
	if (s->ch != NULL)
	{
		free(s->ch);
		s->ch = NULL;
	}
	s->length = 0;
}

void string_concat(HString* s, HString* s1, HString* s2)
{
	int i;

	if (s->ch != NULL)
		free(s->ch);
	s->ch = (char*)malloc((s1->length + s2->length + 1) * sizeof(char));
	if (s->ch == NULL)
	{
		printf("\nmalloc failure!!!");
		exit(OVERFLOW);
	}
	s->length = s1->length + s2->length;
	s->ch[s->length] = '\0';
	for (i = 0; i < s1->length; i++)
	{
		s->ch[i] = s1->ch[i];
	}
	for (i = 0; i < s2->length; i++)
	{
		s->ch[s1->length + i] = s2->ch[i];
	}
}

void substring(HString* sub, HString* s, int position, int length)
{
	int i;

	// 1 <= position <= s->length
	// 1 <= length <= s->length - position + 1
	if (position < 1 || position > s->length || length < 1 || length > s->length - position + 1)
	{
		printf("\ninvalid parameters!!!");
		exit(INFEASIBLE);
	}
	if (sub->ch != NULL)
		free(sub->ch);
	sub->ch = (char*)malloc((length + 1) * sizeof(char));
	if (sub->ch == NULL)
	{
		printf("\nmalloc failure!!");
		exit(OVERFLOW);
	}
	sub->ch[length] = '\0';
	sub->length = length;
	for (i = 0; i < length; i++)
	{
		sub->ch[i] = s->ch[position - 1 + i];
	}
}