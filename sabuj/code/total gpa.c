#include<stdio.h>
int main()
{
    double input_grade[8],input_credit[8],sum=0,sum1=0,gpa=0;
    int i;
    ///printf("Enter The Total Number Of Subject : ");
    ///scanf("%d",&n);
    printf("Enter The Grades : ");
    for(i=0;i<8;i++)
    scanf("%lf",&input_grade[i]);
    ///printf("\n");
    printf("Enter The Credits : ");
    for(i=0;i<8;i++)
    scanf("%lf",&input_credit[i]);
    for(i=0;i<8;i++)
    {
        sum+=input_credit[i]*input_grade[i];
        sum1+=input_credit[i];
    }
    gpa=sum/sum1;
    printf("\nTotal GPA Is : %.2lf\n",gpa);

  return 0;
}
///creditHours[] ={3.0 3.0 3.0 3.0 3.0 3.0 1.5 1.5};
///gradePoints[] ={3.5 4.0 3.75 4.0 3.5 4.0 3.75 4.0};

