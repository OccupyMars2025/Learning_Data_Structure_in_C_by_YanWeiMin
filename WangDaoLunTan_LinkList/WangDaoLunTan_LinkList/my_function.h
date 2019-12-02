#ifndef _MY_FUNCTION_
#define _MY_FUNCTION_

typedef int ElemType;
typedef struct LNode 
{
	ElemType data;
	struct LNode* next;
}LNode, *LinkList;

void CreateList1(LinkList* L);
void PrintList(LinkList* L);
void CreateList2(LinkList* L);

#endif // !_MY_FUNCTION_
