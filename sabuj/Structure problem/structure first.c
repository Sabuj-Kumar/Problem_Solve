#include<stdio.h>
struct student
{
    char name[100];
    long long  id;
    float mark[100];
 };
 int main()
 {
    int flag = 0;
    while( 1 )
    {
        struct student std;
        int N,i;
        float sum = 0,gpa = 0;

        printf("Enter Name : ");
        scanf("%s",std.name);

        printf("Enter Id : ");
        scanf("%lld",&std.id);


        printf("Enter The Number Of Subjects : ");
        scanf("%d",&N);

        printf("Enter The Number Of Subject'S Mark's : ");
        for( i = 0; i < N; i++ )
        {
            scanf("%f",&std.mark[i]);
            sum += std.mark[i];

            if( 80 <= std.mark[ i ] && std.mark[ i ] <= 100 )
             gpa += 4.00 * 3;
            else if( 75 <= std.mark[ i ] && std.mark[ i ] <= 79 )
             gpa += 3.75 * 3;
            else if( 70 <= std.mark[ i ] && std.mark[ i ] <= 74 )
             gpa += 3.50 * 3;
            else if( 65 <= std.mark[ i ] && std.mark[ i ] <= 69 )
             gpa += 3.25 * 3;
            else if( 60 <= std.mark[ i ] && std.mark[ i ] <= 64 )
             gpa += 3.00 * 3;
            else if( 55 <= std.mark[ i ] && std.mark[ i ] <= 59 )
             gpa += 2.75 * 3;
            else if( 50 <= std.mark[ i ] && std.mark[ i ] <= 54 )
             gpa += 2.50 * 3;
            else if( 40 <= std.mark[ i ] && std.mark[ i ] <= 49 )
             gpa += 2.25 * 3;
        }
        printf("\n");
        printf("Name : %s\n\n\aID : %lld\n\n",std.name,std.id);

        printf("Total Number Is : %.2f\n\n\aAverage Number Is : %.2f\n\nTotal GPA Is : %.2f\n\n\n\n",sum,sum/N,(gpa/(N * 3 )));

        printf("If You Not Continue Press 0 .... If You Continue press 1 ....   ");

        scanf("%d",&flag);
        printf("\n\n");

        if ( flag == 0 )
         break;
    }

    return 0;
 }
