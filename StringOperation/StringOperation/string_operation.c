#include<stdio.h>
#include<stdlib.h>
#include "string_operation.h"

void concat(SString t, SString s1, SString s2)
{
	int i, j;

	if (*s1 + *s2 <= MAX_STRING_LENGTH)
	{
		i = 1;
		while (i <= *s1)
		{
			*(t + i) = *(s1 + i);
			i++;
		}
		j = 1;
		while (j <= *s2)
		{
			*(t + i) = *(s2 + j);
			i++; j++;
		}
		*(t + i) = '\0';
		*t = *s1 + *s2;
	}
	else if (*s1 < MAX_STRING_LENGTH)
	{
		i = 1;
		while (i <= *s1)
		{
			*(t + i) = *(s1 + i);
			i++;
		}
		j = 1;
		while (i <= MAX_STRING_LENGTH)
		{
			*(t + i) = *(s2 + j);
			i++; j++;
		}
		*(t + i) = '\0';
		*t = MAX_STRING_LENGTH;
	} 
	else
	{
		i = 1;
		while (i <= MAX_STRING_LENGTH)
		{
			*(t + i) = *(s1 + i);
			i++;
		}
		*(t + i) = '\0';
		*t = MAX_STRING_LENGTH;
	}
}

void substring(SString sub, SString s, int position, int length)
{
	int i;

	if (position < 1 || position > s[0] || length < 1 || position + length - 1 > s[0])
	{
		printf("\nError!!");
		exit(INFEASIBLE);
	}
	i = 1;
	while (i <= length)
	{
		sub[i] = s[position + i - 1];
		++i;
	}
	sub[i] = '\0';
	sub[0] = length;
}