#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> vec;

    int N,i,count_ = 0;

    cin >> N;

    int x[ N ];

    for(i = 0; i < N; i++)
        cin >> x[ i ];

    for(i = 0; i < N; i++)
    {
        if(x[ i ] > x[ i+1 ])
        {
            count_++;
            vec.push_back(x[ i ]);
        }
        else if(x[ i ] == x[ i+1 ])
        {
            count_++;
            vec.push_back(x[ i ]);
        }
        if(i == N-1 && (x[ i ] < x[ i+1 ]) )
        {
            count_++;
            vec.push_back(x[ i ]);
        }
    }
    cout << count_ << "\n";

    for(i = 0; i < vec.size(); i++)
    {
        cout << vec[ i ];

        if(i < vec.size()-1)
            cout << " ";
    }

    vec.clear();

    return 0;
}
