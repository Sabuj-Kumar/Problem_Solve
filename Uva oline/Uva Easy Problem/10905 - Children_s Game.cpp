#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    while(scanf("%d",&n) && n != 0)
    {
        vector<int> vec;

        int input,i = 0;

        while(n--)
        {
            scanf("%d",&input);
            vec.push_back(input);
        }
        for(i = vec.size()-1; i >= 0; i--)
            cout<<vec[i];

        printf("\n");
    }
    return 0;
}
