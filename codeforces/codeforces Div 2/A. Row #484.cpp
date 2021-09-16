#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
//    while(1)
//    {
    int i,n,flag = 0 ,flag1 = 0;

    scanf("%d",&n);

    char a[n];
    string b;

    scanf("%s",a);

    b = a;

    if(b[0] == '1')
      flag = 1;


    if(flag == 1)
    {
        for(i = 0; i < b.size(); i++)
        {
            if(i % 2 == 0)
            {
                if(b[i] != '1')
                {
                    flag1 = 1;
                    break;
                }
            }
            else
            {
                if(b[i] != '0')
                {
                    flag1 = 1;
                    break;
                }
            }
       }
    }
    else
    {
        for(i = 0; i < b.size(); i++)
        {
            if(i % 2 == 0)
            {
                if(b[i] != '0')
                {
                    flag1 = 1;
                    break;
                }
            }
            else
            {
                if(b[i] != '1')
                {
                    flag1 = 1;
                    break;
                }
            }
       }
    }

    if(flag1 == 1)
        printf("no\n");

    else
        printf("yes\n");
    //}

    return 0;
}
