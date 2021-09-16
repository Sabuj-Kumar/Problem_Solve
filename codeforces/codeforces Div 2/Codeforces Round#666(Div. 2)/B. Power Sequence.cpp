#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N = 0,n;

    cin >> n;
    ll a[ n + 5 ];

    for(int i = 0; i < n; i++) cin >> a[ i ];

    sort(a,a+n);

    if(n == 3) N = 1e6;
    else N = (int)1e6 / 3;

    ll ans = (ll)1e16;

    for(int i = 1; i <= N; i++){

        ll x = 1;
        ll cnt = 0;

        for(int j = 0; j < n; j++){

            cnt += abs(a[ j ] - x);

            if(cnt > ans) break;

            x *= i;
        }

        if(ans > cnt) ans = cnt;
    }

    cout << ans << endl;

    return 0;
}
