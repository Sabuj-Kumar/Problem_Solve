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

vector< ll > v;
ll n,m,ans;

ll LCM(ll a,ll b){

    return (a * b) / __gcd(a,b);
}

void Exclution_Inclution(int idx,ll lcm,int num){

    if(idx == m){

        if( !num ) return;

        if(num & 1) ans += (n / lcm);
        else ans -= (n / lcm);

        return;
    }

    Exclution_Inclution(idx + 1,lcm,num);
    Exclution_Inclution(idx + 1,LCM(lcm,v[ idx ]),num+1);

}
int main(){

    file();

    while(cin >> n >> m){

        v.clear();

        for(int i = 0; i < m; i++){

            ll a;

            cin >> a;

            v.pb( a );
        }

        ans = 0;

        Exclution_Inclution(0,1,0);

        cout << n - abs(ans) << endl;
    }

    return 0;
}
