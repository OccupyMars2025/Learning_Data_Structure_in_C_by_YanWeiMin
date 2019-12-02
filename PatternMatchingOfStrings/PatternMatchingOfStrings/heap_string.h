#ifndef _HEAP_STRING_
#define _HEAP_STRING_

#define OVERFLOW 1
#define INFEASIBLE 2

typedef struct 
{
	char* ch;
	int length;
} HString;

void init_hstring(HString* s);
void hstring_assign(HString* s, char* ch);
int index(HString* s, HString* sub, int position);

#endif // !_HEAP_STRING_
