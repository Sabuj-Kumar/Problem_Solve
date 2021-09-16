#include<stdio.h>
#include<math.h>
#define pi 3.14159

///add function
int add(int a,int b)
{
    int sum=0;

    printf("Enter The First Value : ");
    scanf("%d",&a);

    printf("Enter The second Value : ");
    scanf("%d",&b);

    sum=a+b;

    return sum;

}

/// power function

int power(int a,int b)
{
    int p;

    printf("Enter The Value Of Base :  ");
    scanf("%d",&a);

    printf("Enter The Value Of Power : ");
    scanf("%d",&b);

    p=pow(a,b);

    return p;

}
///sine operator function.

double sine()
{
    double a, sn;
    double rad = pi/180.00;

    printf("Enter The Digit Of Degree : ");
    scanf("%lf",&a);
    rad =a*rad;

    sn=sin(rad);

    return sn;
}
///cosine function

double cosine()
{
    double a,cn, rad=pi/180.00;

    printf("Enter The Digit Of Degree : ");
    scanf("%lf",&a);

    rad =a*rad;
    cn=cos(rad);

    return cn;
}
///inverse sine operator function.

double inversesine()
{
    double a, sn;
    double rad ;
    rad= 180.00/pi;

    printf("Enter The Digit Of Degree : ");
    scanf("%lf",&a);

    sn=asin(a)*rad;

    return sn;
}

int main()
{
    int n,sum=0,pw=0;
    double i,j,sn=0,cn=0,sn1=0;

    printf("If You Want To Add Number's Press 1.\n");
    printf("If You Want To Use Power Function Press 2.\n");
    printf("If You Want To Use Sine Function Press 3.\n");
    printf("If You Want To Use Cosine Function Press 4.\n");
    printf("If You Want To Inverse Sine Function Press 5.\n");

    scanf("%d",&n);
  ///add
    if(n==1)
    {
        sum=add(i,j);
        printf("\nThe Result Is= %d",sum);
    }
    ///power
    else if(n==2)
    {
        pw=power(i,j);
        printf("\nThe Result Is= %d",pw);
    }
    ///sine
    else if(n==3)
    {
        sn=sine();
        printf("\nThe Result Is= %.2lf",sn);
    }
    ///cosine
    else if(n==4)
    {
        cn=cosine();
        printf("\nThe Result Is= %.2lf",cn);
    }
    ///inverse sine
    else if(n==5)
    {
        sn1=inversesine();
        printf("\nThe Result Is= %.2lf",sn1);
    }

}
