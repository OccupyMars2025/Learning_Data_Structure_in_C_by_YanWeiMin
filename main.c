#include <stdio.h>
#include <stdlib.h>

#define GO_ON 1
#define QUIT 0

typedef int Status;
typedef int ElemType;

typedef struct {
    ElemType *elem;
    int length;
    int listsize;
} SqList;

Status InitList_Sq(SqList *);
Status ListInsert_Sq(SqList *, int , ElemType);
Status ListDelete_Sq(SqList *, int, ElemType *);
int LocateElem_Sq(SqList, ElemType,
                  Status (*compare)(ElemType, ElemType));
Status ElemEqual(ElemType, ElemType);
void MergeList_Sq(SqList, SqList, SqList *);
void PrintList_Sq(SqList);

int main()
{
    SqList La, Lb, Lc;
    InitList_Sq(&La);
    ElemType elem;
    int choice = GO_ON;
    int i;

    printf("Construct list La(insert at head):\n");
    do {
        printf("Enter an integer:");
        scanf("%d", &elem);
        ListInsert_Sq(&La, 1, elem);

        printf("\nContinue: 1(yes) or 0(no)? ");
        scanf("%d", &choice);
        printf("\n");
    } while (choice == GO_ON);

    printf("The final list is as follows:\n");
    PrintList_Sq(La);

    printf("Delete 3rd element:\n");
    ListDelete_Sq(&La, 3, &elem);
    printf("The 3rd element = %d\n", elem);
    PrintList_Sq(La);

    printf("Enter an element to locate:");
    scanf("%d", &elem);
    i = LocateElem_Sq(La, elem, ElemEqual);
    printf("\nThe location is:%d\n", i);

    printf("Construct list Lb(insert at end):\n");
    do {
        printf("Enter an integer:");
        scanf("%d", &elem);
        ListInsert_Sq(&Lb, Lb.length+1, elem);

        printf("\nContinue: 1(yes) or 0(no)? ");
        scanf("%d", &choice);
        printf("\n");
    } while (choice == GO_ON);
    PrintList_Sq(Lb);

    MergeList_Sq(La, Lb, &Lc);
    printf("Merged list:\n");
    PrintList_Sq(Lc);

    return 0;
}

