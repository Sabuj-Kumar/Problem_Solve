#include<stdio.h>
#include<iostream>

#define sf scanf
#define pf printf

using namespace std;

int main()
{
    int test,i;

    sf("%d",&test);

    for(i = 1; i <= test; i++)
    {
        int j = 0,n = 0,a[60] = {0},h_count = 0,l_count = 0;

        sf("%d",&n);

        for(j = 0; j < n; j++)
           sf("%d",&a[j]);

        for(j = 1; j < n; j++)
        {
            if(a[j-1] < a[j])
                h_count++;

            else if(a[j-1] > a[j])
                l_count++;

        }
        pf("Case %d: %d %d\n",i,h_count,l_count);
    }
    return 0;
}
