#include<stdio.h>
int main()
{
    double a,b,c,d,e;
    scanf("%lf %lf %lf %lf ", &a, &b, &c, &d);
    e = (a*2 + b*3 + c*4 + d*1)/10;
    printf("Media: %.1lf\n", e);

    if(e>=7.0){

        printf("Aluno aprovado.\n");
    }
    else if(e<5.0){
        printf("Aluno reprovado.\n");
    }
    else if(e >= 5.0 && e <= 6.9){
        double f;
        scanf("%lf", &f);
        printf("Aluno em exame\n");
        printf("Nota do exame: %.1lf\n", f);
        printf("Aluno aprovado.\n");
        e = (e+f)/2;
        printf("Media final: %.1lf\n", e);
    }
    return 0;
}
