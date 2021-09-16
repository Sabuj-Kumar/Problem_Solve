#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int main()
{
    int test;

    cin >> test;
    getchar();

    while(test--)
    {
        stack< char > stk;
        string input;

        getline(cin,input);

        for(int i = 0; i < input.size(); i++)
        {
            if(!stk.empty() && input[ i ] == ')' && stk.top() == '(')
                stk.pop();

            else if(!stk.empty() && input[ i ] == ']' && stk.top() == '[')
                stk.pop();

            else
                stk.push(input[ i ]);
        }

        if(stk.empty())
            cout <<"Yes\n";

        else
            cout <<"No\n";
    }
    return 0;
}
