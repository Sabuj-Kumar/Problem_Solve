#include<stdio.h>
int main()
{
    double N1,N2,N3,N4,e;
    printf("Enter The Values :  ");
    scanf("%lf %lf %lf %lf",&N1,&N2,&N3,&N4);
    e=(N1+N2+N3+N4)/4;
    printf("Media: %.1lf\n",e);
    if(e>=7.0)
    {
        printf("Aluno aprovado.");

    }
   else if(e<=5.0)
    {
        printf("Aluno reprovado.");
    }
   else if(e>=5.0 && e<=6.9)
    {
        printf("Aluno em exame.");
    }


}
