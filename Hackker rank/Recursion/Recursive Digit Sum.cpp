#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair<ll,ll >
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

ll add(ll n){

    ll sum = 0;

    while(n){

        sum += n % 10;
        n /= 10;
    }

    return sum;
}
ll super(ll val){

    ll sum = val;

    while(sum > 9) sum = add(sum);

    return sum;
}
int main(){

    file();

    string s;
    ll k;
    ll sum = 0;

    cin >> s >> k;

    for(int i = 0; i < s.size(); i++) sum += s[ i ] - 48;

    sum *= k;

    cout << super(sum) << endl;

    return 0;
}
