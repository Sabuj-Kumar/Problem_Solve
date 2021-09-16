#include<stdio.h>
#include<iostream>
#include<math.h>

#define sf scanf
#define pf printf

using namespace std;

int main()
{
    int test,i;

    sf("%d",&test);

    for(i = 1; i <= test; i++ )
    {
        long long input = 0,root = 0;
        long long swap = 0,check = 0,dif = 0;

        sf("%lld",&input);

        root = sqrt(input);
        check = root * root;
        dif = input - check;

        if(dif == 0)
        {
            if(input % 2 == 0)
              pf("Case %d: %lld 1\n",i,root);

            else
              pf("Case %d: 1 %lld\n",i,root);
        }
        else if( dif != 0)
        {
            if( dif > root )
            {
                if(dif % root == 0)
                {
                    dif /= root;
                    root++;
                }
                else
                {
                    root++;
                }
            }
            else
                root++;
        }
        if(dif != 0)
        {
            if(input % 2 == 0)
                pf("Case %d: %lld %lld\n",i,dif,root);

            else
               pf("Case %d: %lld %lld\n",i,root,dif);
        }
    }
    return 0;
}
