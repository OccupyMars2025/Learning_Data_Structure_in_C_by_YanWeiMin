#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;

typedef enum {A, B, C, D, E} SchoolName;
typedef enum {FEMALE, MALE} SexType;

typedef struct {
    char program_name[20];
    SexType sex;
    SchoolName school;
    int score;
} Component;

typedef struct {
    int male_sum;
    int female_sum;
    int total_sum;
} Sum;

Status construct_a_table_and_its_statistics(void);

int main()
{
    construct_a_table_and_its_statistics();
    return 0;
}
