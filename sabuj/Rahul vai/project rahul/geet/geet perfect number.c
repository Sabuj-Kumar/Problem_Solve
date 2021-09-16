#include<stdio.h>//perfect number
#include<conio.h>//ekti number k joto gula number dia vag kora jai , toto gola number er jog korle jodi jog fol oi number er soman hoi tahole oi number k perferc number bole; jemon;;6==(1+2+3=6};so eta ekta perfect number ;;9==1+3=5;not perfect
int main()

{
    int i,n,sum=0;
    scanf("%d", &n);
    printf("the number is\n");
    for(i=1;i<n;i++)
    {
        if(n%i==0)
        {
          sum=sum+i;
        }

    }
    if(sum==n) {printf("perfect number");}
    else      {printf("not perfect number");}

getch();
return 0;

}
