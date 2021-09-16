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

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

int n,m;
int cap[ 1015 ];

bool okay(int x){

    int new_ = 0,cnt = 1;

    for(int i = 0; i < n; i++){

        if(cap[ i ] > x) return false;

        if(new_ + cap[ i ] <= x) new_ += cap[ i ];
        else new_ = cap[ i ],cnt++;

        if(cnt > m) return false;
    }

    return true;
}
int main(){

    file();

    while(scanf("%d %d",&n,&m) == 2){

        for(int i = 0; i < n; i++) cap[ i ] = I();

        int low = 1,high = 1e9,mid;

        while(low < high){

            mid = (low + high) / 2;
            if(okay( mid )) high = mid;
            else low = mid + 1;
        }
        printf("%d\n",high);
    }
    return 0;
}

