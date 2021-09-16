#include<stdio.h>
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int main()
{
    int n,input;
    bool flag = true;

    cin>> n;

    deque<int> a;
    deque<int> :: iterator it;

    for(int i = 0; i < n; i++)
    {
        cin>> input;

        a.push_back( input );
    }
    sort(a.begin(),a.end());

//    for(it = a.begin(); it != a.end(); it++)
//        cout<< *it << " ";

    while(a.size() > 1)
    {
        if( flag == true)
        {
          a.pop_back();
          flag = false;
        }
        else
        {
            a.pop_front();
            flag = true;
        }
    }
    cout<< a[0] << endl;

    return 0;
}
