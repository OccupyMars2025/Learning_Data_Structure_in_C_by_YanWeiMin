#ifndef _HEAP_STRING_
#define _HEAP_STRING_

#define OVERFLOW 1
#define INFEASIBLE 2

typedef struct 
{
	char* ch;
	int length;
} HString;

void string_init(HString* s);
void string_insert(HString* s, int position, HString* t);
void string_assign(HString* s, char* ch);
int string_compare(HString* s1, HString* s2);
void clear_string(HString* s);
void string_concat(HString* s, HString* s1, HString* s2);
void substring(HString* sub, HString* s, int position, int length);

#endif // !_HEAP_STRING_
