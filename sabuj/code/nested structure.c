#include<stdio.h>
#include<string.h>
struct student
{
    char name[100];
    char id[100];

    struct student_marks
    {
        char sub[100];
        double mark;

    }input[100];

}std[1000];

int main()
{

    int N,i,j;
    double max = 0,sum = 0;

    printf("Enter The Total Student Number's :  ");
    scanf("%d",&N);
    printf("\n\n");

    for ( i = 0; i < N; i++ )
    {
        printf("Enter The Student's Name :  ");
        scanf("%s",std[i].name);

        printf("Enter The Student's Id  :  ");
        scanf("%s",std[i].id);

        printf("Enter The Student's Subject Name :  ");
        for( j = 0 ; j < 3; j++ )
        scanf("%s",std[i].input[j].sub);

        printf("Enter The Student's Marks :  ");
        for( j = 0; j < 3; j++ )
        {
            scanf("%lf",&std[i].input[j].mark);
            sum += std[i].input[j].mark;
        }
        if(  sum > max )
        max = sum;
        sum = 0;
    }
    printf("First Student Details Is...\n\n\n");
    for( i = 0; i < N; i++ )
    {
        double cheek = 0;
        for( j = 0; j < 3; j++ )
        cheek += std[i].input[j].mark;
        if ( max == cheek )
        {
            printf("The First Student Name Is %s  :  \n\n",std[i].name );

            printf("The First Student ID Is %s  :  \n\n",std[i].id);

            printf("The First Student Subject's Is : " );
            for( j = 0 ; j < 3; j++ )
            printf("%s ",std[i].input[j].sub);
            printf("\n\n");

            printf("The First Student Mark's Is :  ");
            for( j = 0 ; j < 3; j++ )
            printf("%.2lf ",std[i].input[j].mark);
            printf("\n\n\a");

            break;
        }
        else
            cheek = 0;
    }
    return 0;
}

