#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;

    scanf("%d",&test);

    while(test--)
    {
        string n;
        bool flag = true;

        cin >> n;

        for(int i = 0; i < n.size(); i++)
        {
            if(n[ i ] == 'D')
            {
                flag =  false;

                break;
            }
        }
        if(flag == true)
            printf("Possible\n");
        else
            printf("You shall not pass!\n");
    }
    return 0;
}
