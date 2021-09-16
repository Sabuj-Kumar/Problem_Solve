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
#define in freopen("in.txt","r",stdin);
#define ex 1e-6

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

int T;
int CF[ 15 ];

db cal(db m){

    db ans = CF[ 0 ];

    for(int i = 1; i <= T; i++) ans += db(CF[ i ] / pow(1.0 + m,i));

    return ans;
}
int main(){

    file();

    while(sc( T ) and T){

        for(int i = 0; i <= T; i++) CF[ i ] = I();

        db low = -1,high = 1e6;

        while(high - low > ex){

            db mid = (low + high) / 2;

            if(cal( mid ) >= 0) low = mid;

            else high = mid;
        }

       cout << fixed << setprecision(2);
       cout << low << endl;
    }

    return 0;
}
