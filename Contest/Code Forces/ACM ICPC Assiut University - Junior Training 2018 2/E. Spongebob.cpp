#include<bits/stdc++.h>

using namespace std;

int main()
{
    string a,b;

    cin >> a;
    cin >> b;

    int len_a = a.length();
    int len_b = b.length();
    int sum = 0;

    sum = (a[ len_a-1] - 48) + (b[ len_b - 1] - 48);

    cout << sum <<endl;

    return 0;
}
