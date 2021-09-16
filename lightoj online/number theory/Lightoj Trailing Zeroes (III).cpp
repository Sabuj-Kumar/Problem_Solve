#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int >
#define pll pair< ll,ll >
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define in freopen("in.txt","r",stdin)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

ll zeros(ll val){

    ll div = 5,cnt = 0;

    while((val/div) >= 1){

        cnt += val/div;
        div *= 5;
    }
    return cnt;
}
ll B_S(ll q){

    ll zero = 0,l = 0,r = 1e11,mid = 0;

    while(l <= r){

        mid = (l + r)/2;
        mid -= mid%5;

        zero = zeros( mid );

        if(zero > q)r = mid - 5;
        else if(zero < q) l = mid + 5;
        else break;
    }

    if(zero == q) return mid;
    return -1;
}

int main(){

    file();

    int t = I();

    Case( t ){

        ll q = I();

        ll ans = B_S( q );

        printf("Case %d: ",cs);
        if(ans == -1) puts("impossible");
        else printf("%lld\n",ans);
    }
    return 0;
}
