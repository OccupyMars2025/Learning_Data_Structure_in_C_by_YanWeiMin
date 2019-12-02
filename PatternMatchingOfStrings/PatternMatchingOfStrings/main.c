#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "heap_string.h"

int main()
{
	HString s, sub;

	init_hstring(&s);
	init_hstring(&sub);

	hstring_assign(&s, "hello,china!!!");
	hstring_assign(&sub, "ch");
	printf("\n%s,len=%d\n%s,len=%d", s.ch, s.length, sub.ch, sub.length);
	printf("\nindex=%d", index(&s, &sub, 8));

	return 0;
}