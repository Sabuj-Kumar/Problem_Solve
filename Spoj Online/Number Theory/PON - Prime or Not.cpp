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

using u64 = uint64_t;
using u128 = __uint128_t;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

u64 power(u64 a,u64 p,u64 mod){

    u64 res = 1;

    a %= mod;

    while(p){

        if(p & 1) res = (u128)res * a % mod;

        a = (u128)a * a % mod;

        p /= 2;
    }

    return res;
}

bool composite(u64 a,u64 d,u64 n,u64 r){

    u64 x = power(a,d,n);

    if(x == 1 or x == n - 1) return false;

    for(int i = 1; i < r; i++){

        x = (u128)x * x % n;

        if(x == n - 1) return false;
    }

    return true;
}

bool miller_robin(u64 n){

    if(n < 4) return n == 2 or n == 3;
    if(n % 2 == 0) return false;

    u64 r = 0;

    u64 d = n-1;

    while((d & 1) == 0){

        d /= 2;
        r++;
    }

    for (ull a : {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71}) {

        if (n == a) return true;

        if (composite(a, d, n, r)) return false;
    }
    return true;
}
int main(){

    op;
    file();

    int t;

    cin >> t;

    while(t--){

        u64 n;

        cin >> n;

        if(miller_robin(n)) cout << "YES" << endl;

        else cout << "NO" << endl;
    }
    return 0;
}
