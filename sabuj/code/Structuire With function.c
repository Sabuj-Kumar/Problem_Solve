#include<stdio.h>
struct student
{
    char name[100];
    char id[100];
    char email[100];
    double gpa;
};
int highest( struct student std )
{
    printf("The Student Name Is : %s\n",std.name);

    printf("The Student ID Is : %s\n",std.id);

    printf("The Student Email Is : %s\n",std.email);

    printf("The student GPA Is : %.2lf\n",std.gpa);
}
int main()
{
    struct student st;

    printf("Enter The Student Name : ");
     scanf("%s",st.name);

    printf("Enter The Student Id : ");
     scanf("%s",st.id);

    printf("Enter The Student Email : ");
     scanf("%s",st.email);

    printf("Enter The Student GPA :  ");
     scanf("%lf",&st.gpa);

    printf("\n");

    highest(st);

    return 0;
}
