#include<stdio.h>
#include<math.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test,i;

    scanf("%d",&test);

    for(i = 1; i <= test; i++)
    {
        double a,b,c,d,area;
        double n,m,s,t,h;

        scanf("%lf %lf",&a,&b);
        scanf("%lf %lf",&c,&d);

        if(c > a)
         swap(a,c);

        n = (a - c);
        s = (b + d + n)/2;
        t = sqrt(s*((s - n)*(s - b)*(s - d)));
        h = (t * 2) / n;
        area = ((a + c) * h) / 2;

        printf("Case %d: %lf\n",i,area);
    }
    return 0;
}
