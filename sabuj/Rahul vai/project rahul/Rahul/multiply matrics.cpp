#include<stdio.h>
#include<conio.h>
int main()
{
    int x1,x2,x3,y1,y2,y3,z1,z2,z3,a1,a2,a3,b1,b2,b3,c1,c2,c3;
    int d,e,f,g,h,i,j,k,l;
    printf("Enter two 3*3 matrics = \n");
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",&x1,&x2,&x3,&y1,&y2,&y3,&z1,&z2,&z3,&a1,&a2,&a3,&b1,&b2,&b3,&c1,&c2,&c3);
    d=(x1*a1)+(x2*b1)+(x3*c1);
    e=(x1*a2)+(x2*b2)+(x3*c2);
    f=(x1*a3)+(x2*b3)+(x3*c3);
    g=(y1*a1)+(y2*b1)+(y3*c1);
    h=(y1*a2)+(y2*b2)+(y3*c2);
    i=(y1*a3)+(y2*b3)+(y3*c3);
    j=(z1*a1)+(z2*b1)+(z3*c1);
    k=(z1*a2)+(z2*b2)+(z3*c2);
    l=(z1*a3)+(z2*b3)+(z3*c3);
    printf("%d\t%d\t%d\n%d\t%d\t%d\n%d\t%d\t%d",d,e,f,g,h,i,j,k,l);
    getch();
    return 0;
}
