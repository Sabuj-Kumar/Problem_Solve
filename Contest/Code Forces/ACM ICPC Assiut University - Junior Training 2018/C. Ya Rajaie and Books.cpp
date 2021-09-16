#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;

    scanf("%d",&test);

    while(test--)
    {
        long long input;

        cin >> input;

        if(input % 5 == 0) cout << input/5 << endl;

        else cout << (input/5) + 1 << endl;
    }
    return 0;
}
