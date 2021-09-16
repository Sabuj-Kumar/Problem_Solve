#include<bits/stdc++.h>
#include<math.h>

using namespace std;

int main()
{
    long double input;

    while(cin >> input)
    {
        long double output;

        output = pow(2,input) - input;

        cout << output << endl;
    }

    return 0;
}
