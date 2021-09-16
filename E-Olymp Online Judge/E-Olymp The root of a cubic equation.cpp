#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

db lim = 1e-7;

db a,b,c,d;

db okay(db x ){

   return (a * (x * x * x) ) + (b * (x * x)) + (c * x) + d;
}
db Binary_Search(){

    db l = -1e19,r = 1e19,mid = 0;

    while(r - l > lim){

        mid = l + (r - l) / 2.0;

        if(okay( mid ) < 0) l = mid;
        else r = mid;
    }
    return r;
}
int main(){

    file();

    cin >> a >> b >> c >> d;

    if(a < 0) a = -a,b = -b,c = -c,d = -d;

    cout << setprecision(6) << fixed;
    cout << Binary_Search() << endl;

    return 0;
}

