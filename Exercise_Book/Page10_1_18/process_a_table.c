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

Status construct_a_table_and_its_statistics(void)
{
    int n;
    printf("Enter number of records:\n");
    scanf("%d", &n);

    Component *records; // Component records[n] cannot work
    Sum *schools;       // Sum schools[5] cannot work
    int i;
    int sex;
    int school;
    int score;

    records = (Component *) malloc(n * sizeof(Component));
    if (!records) {
        fprintf(stderr, "error: overflow\n");
        return OVERFLOW;
    }
    schools = (Sum *) malloc(5 * sizeof(Sum));
    if (!schools) {
        fprintf(stderr, "error: overflow\n");
        return OVERFLOW;
    }

    printf("Now, enter %d records:\n", n);
    for (i = 0; i < n; i++) {
        printf("record %d:\n", i);
        printf("school name(A=0,B=1,C=2,D=3,E=4):\n");
        scanf("%d", &school);
        records[i].school = school;

        printf("sex type(FEMALE=0, MALE=1):\n");
        scanf("%d", &sex);
        records[i].sex = sex;

        printf("score(an integer):\n");
        scanf("%d", &score);
        records[i].score = score;

        printf("\n");
    }

    for (i = 0; i < 5; i++) {
        schools[i].female_sum = 0;
        schools[i].male_sum = 0;
        schools[i].total_sum = 0;
    }

    for (i = 0; i < n; i++) {
        if (records[i].sex == FEMALE)
            schools[records[i].school].female_sum += records[i].score;
        else
            schools[records[i].school].male_sum += records[i].score;
    }

    for (i = 0; i < 5; i++) {
        schools[i].total_sum = schools[i].female_sum + schools[i].male_sum;
        printf("School %c:\n", (char)(((int)'A') + i));
        printf("female score sum:%d\n", schools[i].female_sum);
        printf("male score sum:%d\n", schools[i].male_sum);
        printf("total score sum:%d\n", schools[i].total_sum);
        printf("\n");
    }
    return OK;
}
