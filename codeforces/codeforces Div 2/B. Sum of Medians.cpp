#include<bits/stdc++.h>
#define pi acos(-1)

using namespace std;

int main(){

    //freopen("input.txt","r",stdin);
    int t;

    cin >> t;

    while(t--){

        int n,k;

        cin >> n >> k;

        int sz = n * k;

        int a[ sz + 2 ];

        for(int i = 0; i < sz; i++) cin >> a[ i ];

        int div = n/2;
        long long sum = 0;

        while(k > 0){

            sum += a[ sz - (div + 1) ];

            sz = sz - (div + 1) ;

            k--;
        }

        cout << sum << endl;
    }
    return 0;
}
