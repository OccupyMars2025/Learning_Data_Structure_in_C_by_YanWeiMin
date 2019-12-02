#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "string_operation.h"

int main()
{
	SString t, s1, s2, s, sub;
	
	strcpy_s(s1 + 1, MAX_STRING_LENGTH, "abc");
	s1[0] = 3;
	strcpy_s(s2 + 1, MAX_STRING_LENGTH, "123");
	s2[0] = 3;
	
	concat(t, s1, s2);

	printf("%s\n", t + 1);
	printf("%d", t[0]);

	strcpy_s(s + 1, MAX_STRING_LENGTH, "hello,ai,computer!!!");
	s[0] = strlen("hello,ai,computer!!!");
	substring(sub, s, 3, 4);
	printf("\n%s\n", sub + 1);
	printf("\n%d", sub[0]);

	printf("\n%d", strlen("abc"));

	return 0;
}