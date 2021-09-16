#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int group;

    while(scanf("%d",&group) && group != 0)
    {
        string input;

        cin >> input;

        string input1[group];

        int length = input.size()/group,k = 0,i,j;

        for(i = 0; i < group; i++)
        {
            for(j = 0; j < length; j++)
            {
                input1[i][j] = input[k];

                k++;
            }
        }
        for(int i = 0; i < group; i++)
          for(int j = length-1; j >= 0; j--)
            cout << input1[i][j];

        cout << endl;
    }
    return 0;
}
