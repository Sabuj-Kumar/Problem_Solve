#ifndef _TASNIA_H
#define _TASNIA_H
#include<stdio.h>


///Factorial function


long long int fac(int n)
{
    long long int i;
    long long int  F=1;
    for(i=2;i<=n;i++)
    {
        F=F*i;
    }
    return F;
}

///power function

double power(double n,int p)
{
    double Pw=1;
    int i;
    for(i=1;i<=p;i++)
    {
        Pw=Pw*n;
    }
    return Pw;
}


///sinx function


void sinx()
{
    int n,i;
    double x;
    printf("Enter the value of x: ");
    scanf("%lf",&x);
    double X=x;
    double sinX=0;
    x=(((int)x)%360)*(3.1416/180);
    for(i=1;i<=10;i++)
    {
        int temp=2*i-1;
        double pow=(double)power(x,temp);
        double Fac=(double)fac(temp);
        if(i%2==0)
        {
            sinX=sinX-(pow/Fac);
        }
        else
        {
            sinX=sinX+(pow/Fac);
        }
    }
    printf("sin(%.0lf) %lf\n",X,sinX);
    getch();
}


///Xor function



void Xor()
{
    char number1[200],number2[200],XOR[200];
    printf("Enter 1st number: ");
    scanf("%s",number1);
    printf("Enter 2nd number: ");
    scanf("%s",number2);
    int i;
    for(i=0;number1[i];i++)
    {
        if(number1[i]==number2[i])
        {
            XOR[i]='0';
        }
        else
        {
            XOR[i]='1';
        }
    }
    XOR[i]=NULL;
    printf("Xor value: %s\n",XOR);
    getch();
}


///matrix multiplication



void mat_multiplication()
{
    int Matrix_A[3][3],Matrix_B[3][3],Matrix_C[3][3],i,j,k;
    printf("enter your first matrix A:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&Matrix_A[i][j]);
        }
    }
    printf("enter your second matrix B:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&Matrix_B[i][j]);
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            Matrix_C[i][j]=0;
            for(k=0;k<3;k++)
            {
                Matrix_C[i][j]+=Matrix_A[i][k]*Matrix_B[k][j];
            }
        }
    }
    printf("Ans:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",Matrix_C[i][j]);
        }
        printf("\n");
    }
    getch();
}



///binary number to octal number convert

void bin_to_octal()
{
    char binary_number[200],octal[200];
    int decimal=0,i,indx;
    printf("Enter Binary Number: ");
    scanf("%s",binary_number);
    for(i=0;binary_number[i];i++)
    {
        decimal=decimal*2+(binary_number[i]-48);
    }
    indx=0;
    while(decimal!=0)
    {
        octal[indx]=(decimal%8)+48;
        decimal/=8;
        indx++;
    }
    printf("Octal: ");
    for(i=indx-1;i>=0;i--)
    {
        printf("%c",octal[i]);
    }
    printf("\n");
    getch();
}


///decimal to binary


void deci_to_bin()
{
    int number,convert[1000],i,j;
    printf("Enter Decimal number: ");
    scanf("%d",&number);
    for(i=0;number!=0;i++)
    {
        convert[i]=number%2;
        number/=2;
    }
    printf("Binary Number: ");
    for(j=i-1;j>=0;j--)
    {
        printf("%d",convert[j]);
    }
    printf("\n");
    getch();
}


///combination

void NcR()
{
    long long int N,R;
    printf("N: ");
    scanf("%lld",&N);
    printf("R: ");
    scanf("%lld",&R);
    long long int ncr=fac(N)/(fac(N-R)*fac(R));
    printf("ncr %lld\n",ncr);
    getch();
}


///ex series

void ex()
{
    int i;
    double x;
    printf("Enter the value of x: ");
    scanf("%lf",&x);
    double Ans=1;
    for(i=1;i<10;i++)
    {
        Ans+=(power(x,i)/fac(i));
    }
    printf("e(%.0lf): %lf\n",x,Ans);
    getch();
}

#endif // _tasnia_H
