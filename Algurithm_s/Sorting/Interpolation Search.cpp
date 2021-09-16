#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

/**
bool Interpolation_Search(int a[],int key,int low,int high)
{
    int mid = low + (( key - a[ low ]) * (high - low)) / (a[ high ] - a[ low ]);

    if(a[ mid ] ==  key)
        return true;

    if(low >= high)
        return false;

    if(a[ mid ] > key)
        return Interpolation_Search(a,key,low,mid-1);

    else
        return Interpolation_Search(a,key,mid+1,high);
}
**/
int main()
{
    int n;

    cin >> n;

    int a[ n ],key,start = 0, end = n-1;

    for(int i = 0; i < n; i++)
        cin >> a[ i ];

    sort(a,a+n);

    cin >> key;

    bool flag = false;

    while(start <= end)
    {
        int mid = start + (( key - a[ start ]) * (end - start)) / (a[ end ] - a[ start ]);

        if (key == a[ mid ])
        {
            flag = true;

            break;
        }
        if(a[ mid ] < key)
            start = mid + 1;

        else
            end = mid - 1;
    }

    if (flag == true)
        cout << "Found\n";

    else
        cout << "Not Found\n";

    return 0;
}
