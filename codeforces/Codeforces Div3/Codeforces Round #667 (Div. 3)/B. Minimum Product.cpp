#include<bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("in.txt","r",stdin);
    int t,i = 1;

    cin >> t;

    while(t--){

        long long a,b,x,y,n,c,ans;
        cin >> a >> b >> x >> y >> n;
        long long aa = a,bb = b,xx = x,yy = y,nn = n;

        c = min(n,a - x);

        a -= c;
        n -= c;

        c = min(n,b - y);
        b -= c;

        ans = a * b;

        c = min(nn,bb - yy);
        bb -= c;
        nn -= c;

        c = min(nn,aa - xx);
        aa -= c;

        ans = min(aa * bb,ans);

        cout << ans << endl;
    }

    return 0;
}
