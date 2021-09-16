#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long

using namespace std;

int main(){

    //freopen("in.txt","r",stdin);

    int t;

    cin >> t;

    while( t-- ){

        ll n,v,ans = 0;
        ll a_mn = INT_MAX,b_mn = INT_MAX;

        cin >> n;
        vector< ll > a,b;

        for(int i = 0; i < n; i++) {

            cin >> v;
            a.push_back( v );

            if(a_mn > v) a_mn = v;
        }

        for(int i = 0; i < n; i++) {

            cin >> v;
            b.push_back( v );

            if(b_mn > v) b_mn = v;
        }

        for(int i = 0; i < n; i++){

            int div1 = a[ i ] - a_mn;
            int div2 = b[ i ] - b_mn;

            ans += max(div1,div2);
        }

        cout << ans << endl;
    }
    return 0;
}

