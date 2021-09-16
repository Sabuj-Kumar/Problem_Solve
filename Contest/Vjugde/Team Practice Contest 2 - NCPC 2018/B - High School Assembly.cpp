#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;

    cin >> test;

    for(int t = 1; t <= test; t++)
    {
        int count_ = 0,N;

        cin >> N;

        int input[ N ];

        for(int i = 0; i < N; i++)
            cin >> input[ i ];

        for(int i = 0; i < N; i++)
        {
            if(input[ i ] == count_+1)
                count_++;
        }
        cout <<"Case "<< t <<": " << N-count_ << endl;
    }
    return 0;
}
