#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    string a,b;

    cin >> a;
    cin >> b;

    int size_a,i,j;
    int size_b,count = 0,sum = 0;

    size_a = a.length();
    size_b = b.length();

    ///cout << size_a << " " << size_b << endl;
    if(size_a >= size_b)
    {
        j = size_b-1;

        for(i = size_a-1; i >= 0; i--)
        {
            if(a[ i ] != b[ j ])
                break;

            count++;
            j--;
        }
    }
    if(size_a < size_b)
    {
        j = size_a-1;

        for(i = size_b-1; i >= 0; i--)
        {
            if(b[ i ] != a[ j ])
                break;

            count++;
            j--;
        }
    }

    sum = (size_a - count) + (size_b - count);

    cout << sum << endl;

    return 0;
}
