#include<stdio.h>
#include<bits/stdc++.h>
#include<math.h>
#include<stdlib.h>

using namespace std;

int main()
{
    int test,i;

    scanf("%d",&test);

    for(i = 1; i <= test; i++)
    {
        int Ax,Ay,Bx,By,Cx,Cy,Dx,Dy;

        int Ar1,Ar2,Ar3,Ar4,Area;

        scanf("%d %d",&Ax,&Ay);
        scanf("%d %d",&Bx,&By);
        scanf("%d %d",&Cx,&Cy);

        Dx = (Ax + Cx) - Bx;
        Dy = (Ay + Cy) - By;

        Ar1 = Bx - Ax;
        Ar2 = By - Ay;
        Ar3 = Cx - Ax;
        Ar4 = Cy - Ay;

        Area = abs((Ar1 * Ar4) - (Ar2 * Ar3));

        printf("Case %d: %d %d %d\n",i,Dx,Dy,Area);
    }
    return 0;
}
