#include<stdio.h>
#include<string.h>
struct student
{
    char name[100];
    char id[100];
    char email[100];
    double mark;
};
int main()
{
    int N,i,max = 0;
    printf("Enter The Student Number :  ");
    scanf("%d",&N);

    struct student std[N];
    for( i = 0; i < N; i++ )
    {
        printf("%d Student.\n\n",i+1);

        printf("Enter The Student Name :  ");
        scanf("%s",std[i].name);

        printf("Enter The Student ID :  ");
        scanf("%s",std[i].id);

        printf("Enter The Student Email :  ");
        scanf("%s",std[i].email);

        printf("Enter The Student Mark's :  ");
        scanf("%lf",&std[i].mark);

        if ( std[i].mark > max )
            max = std[i].mark;

        printf("\n\n");

        ///printf(" %d Student Name Is : %s\n\n",i+1,std[i].name);

        ///printf(" %d Student Id Is : %s\n\n",i+1,std[i].id);

        ///printf(" %d Student Email Is : %s\n\n",i+1,std[i].email);

        ///printf(" %d Student Mark's Is : %.2lf\n\n",i+1,std[i].mark);
    }
    printf("\n\n");
    for( i = 0 ; i < N; i++ )
    {
        if ( max == std[i].mark )
        {
            printf("The First Student Is.... \n\n");
            printf("Student Name Is : %s\n\n",std[i].name);

            printf("Student Id Is : %s\n\n",std[i].id);

            printf("Student Email Is : %s\n\n",std[i].email);

            printf("Student Mark's Is : %.2lf\n\n",std[i].mark);
            break;
        }
    }
}
