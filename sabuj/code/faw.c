#include <stdio.h>
#include <math.h>
double power( double n )
{
    double mul = 1,i;
    for ( i = 0; i < 2; i++ )
     mul *= n;
    return mul;
}
int main()
{
    double v_a[100],v_b[100];
    double n,result=0,a_d_b=0,v_of_a=0,v_of_b=0;
    int i;

    printf("Enter The Range Of coefficient Of I,J And K:\t");
     scanf("%lf",&n);
    printf("\n");

    printf("Enter The A vector's coefficient of I,J and K:\t");
    for( i = 0; i < n; i++ )
      scanf("%lf",&v_a[i]);
    printf("\n");

    printf("Enter The B vector's coefficient of I,J and K:\t");
    for( i = 0; i < n; i++ )
      scanf("%lf",&v_b[i]);
    printf("\n");

    for( i = 0; i < n; i++ )
    {
         a_d_b += v_a[i] * v_b[i];
         v_of_a += power(v_a[i]);
         v_of_b += power(v_b[i]);
    }

    v_of_a = sqrt(v_of_a);
    v_of_b = sqrt(v_of_b);

    result = a_d_b / (v_of_a * v_of_b);
    printf("The Result Is =\t%0.2lf\n",result);

    return 0;
}

