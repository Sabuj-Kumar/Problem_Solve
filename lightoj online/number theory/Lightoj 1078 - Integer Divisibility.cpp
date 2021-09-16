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


int main(){

    file();

    int t = I();

    Case( t ){

       ll n = Il();
       ll digit = Il();
       int cnt = 1;

       cout <<"Case " << cs << ": ";

       if(n == 1) cout << n <<  endl;

       else {

            ll x = digit;

            while( x % n != 0 ){

                x %= n;
                x = (x * 10) + digit;
                cnt++;
            }
            cout << cnt << endl;
       }
    }
    return 0;
}

