#ifndef _STRING_OPERATION_
#define _STRING_OPERATION_

#define OVERFLOW 1
#define INFEASIBLE 2

#define MAX_STRING_LENGTH 100

typedef unsigned char SString[MAX_STRING_LENGTH + 2];

void concat(SString t, SString s1, SString s2);
void substring(SString sub, SString s, int position, int length);

#endif // !_STRING_OPERATION_
