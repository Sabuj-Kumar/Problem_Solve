#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test,n,i;

    scanf("%d",&test);

    while(test--)
    {
        char letter1,letter2;
        map<char,char> mp;
        string input,a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        for(i = 0; i < a.size(); i++)
            mp[ a[ i ] ] = a[ i ];

        cin >> input;

        cin >> n;

        while(n--)
        {
            cin >> letter1 >> letter2;

            mp[ letter2 ] = letter1;

            for(i = 0; i < input.size(); i++)
            {
                if(input[ i ] >= 'A' && input[ i ] <= 'Z')
                {
                    if( mp[ input[ i ] ] != input[ i ] )
                        input[ i ] = mp[ input[ i ] ];
                }
            }
            mp[ letter2 ] = letter2;
        }

        cout << input << endl;

        mp.clear();
    }

    return 0;
}
