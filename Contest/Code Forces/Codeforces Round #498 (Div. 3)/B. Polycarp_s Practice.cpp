#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,i,p = 1,k,j = 0,max_ = 0,profit = 0,x = 0;
    int output1  = 2000000,sum = 0,sum1 = 0,count_ = 0,out_sum = 0;

    cin >> n >> m;

    int a[ n ],b[ n ];

    for(i = 0; i < n; i++)
        cin >> a[ i ];

    for(i = 0; i < m; i++)
    {
        sum += a[ i ];

        if(a[ i ] > max_)
            max_ = a[ i ];
    }

    b[ 0 ] = m;

    cout << "\nsum = " << sum << "\nmax = " << max_ << endl;
    out_sum += max_;
    max_ = 0;

    for(j = i; j < n; j++)
    {
        if(j == n-1)
            break;

        for(k = j; k <= m+j+1; k++)
        {
            sum1 += a[ k ];
            cout << a[ k ] << " ";

            count_++;
            if(max_ < a[ k ])
                max_ = a[ k ];

            if(sum1 >= sum)
            {
                break;
            }
        }
        if(count_ <= m)
        {
            out_sum += max_;

            if(sum < sum1)
              j = k-1;
            else
              j = k;

            cout << "\nsum1 = " << sum1 << "\nmax = " << max_ << "\ncount = "<< count_<<endl;
            max_ = 0;
            b[ p ] = count_;
            p++;
            count_ = 0;
            sum1 = 0;
        }
    }
    cout << out_sum << "\n";

    for(i = 0; i < p; i++)
    {
        cout << b[ i ];

        if(i < (p-1) )
            cout << " ";
    }

    return 0;
}
