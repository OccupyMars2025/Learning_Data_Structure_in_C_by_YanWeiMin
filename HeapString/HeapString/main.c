#include<stdio.h>
#include<stdlib.h>
#include "heap_string.h"

int main()
{
	HString s, t, s1, s2, sub;
	char ch[] = "hello";
	char ch2[] = "CHINA";

	string_init(&s);
	string_init(&t);
	string_init(&s1);
	string_init(&s2);
	string_init(&sub);

	printf("\n%s\n%s", ch, ch2);
	string_assign(&s, ch);
	string_assign(&t, ch2);
	printf("\n%s", s.ch);
	printf("\n%s", t.ch);

	string_insert(&s, 6, &t);
	printf("\n%s, len=%d\n%s, len=%d", s.ch, s.length, t.ch, t.length);

	string_assign(&s, "abc1");
	string_assign(&t, "abc1");
	printf("\ncompare: %d", string_compare(&s, &t));

	string_assign(&s1, "hello, ");
	string_assign(&s2, "China!!!");
	string_concat(&s, &s1, &s2);
	printf("\n=====concat====\n%s,len=%d\n%s,len=%d\n%s,len=%d", s1.ch, s1.length, s2.ch, s2.length, s.ch, s.length);

	string_assign(&s, "hello,china!!!");
	substring(&sub, &s, 3, 4);
	printf("\n===substring=======\n%s,len=%d", sub.ch, sub.length);

	return 0;
}