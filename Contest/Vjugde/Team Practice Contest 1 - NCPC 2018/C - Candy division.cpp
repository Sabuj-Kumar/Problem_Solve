#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;

    cin >> test;

    while(test--)
    {
        long long input,store;

        cin >> input;

        if(input % 3 == 0)
        {
            store = input/3;

            cout << store << " " << store << " " << store << endl;
        }
        else if(input % 4 == 0)
            cout << input/2 << "  "<< input/4<< " "<< input/4 << endl;

        else
            cout << "IMPOSSIBLE\n";
    }
    return 0;
}
