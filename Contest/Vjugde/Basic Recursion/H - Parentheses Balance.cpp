#include<bits/stdc++.h>

using namespace std;

stack < char > stak;

void parenthesis(string input,int i)
{
    if(i == input.size()) return;

    if(!stak.empty() && input[ i ] == ')' && stak.top() == '(') stak.pop();

    else if(!stak.empty() && input[ i ] == ']' && stak.top() == '[') stak.pop();

    else stak.push(input[ i ]);

    parenthesis(input,i+1);
}
int main()
{
    int test;

    cin >> test;

    getchar();

    while(test--)
    {
        string parenthesis_valance;

        getline(cin,parenthesis_valance);

        parenthesis(parenthesis_valance,0);

        if(stak.empty()) cout << "Yes\n";

        else cout << "No\n";

        while(!stak.empty()) stak.pop();
    }

    return 0;
}
