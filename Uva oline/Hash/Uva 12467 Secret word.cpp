#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair< ll,ll >
#define pb push_back
#define pf push_front
#define ft first
#define sd second
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

const int N = 2e6 + 10;
const ll P = 107;
const ll invp = 678791932;
const ll M = 787900005797;

ull Hash2[ N ],Hash1[ N ],pw[ N ];
string s;
int ln;

void pre() {

    pw[ 0 ] = 1;

    for(int i = 1; i < N; i++) pw[ i ] = (P * pw[ i - 1 ]);
}

void HASH(){

    Hash1[ 0 ] = Hash2[ ln ] = 0;

    for(int i = 0; i < ln; i++)
        Hash1[ i ] = (Hash1[ i - 1 ] * P + s[ i ]);

    for(int i = ln - 1; i >= 0; i--)
        Hash2[ i ] = (Hash2[ i + 1 ] * P + s[ i ]);

//    for(int i = 0; i < ln; i++){
//
//        cout << "Hash1 = " << Hash1[ i ] << endl;
//        cout << "Hash2 = " << Hash2[ i ] << endl;
//    }
}

ull Hash_Val(int l,int r){

    ull res = (Hash2[ l ] - Hash2[ r + l ] * pw[ r ]);

    return res;
}

bool check(ull val,int n){

    for(int i = 0; (i + n) <= ln; i++){

        if(Hash_Val(i,n) == val) return true;
    }

    return false;
}
int main(){

    pre();

    file();

    int n;

    cin >> n;

    while(n--){

        ull mx = 0;

        cin >> s;

        ln = s.size();

        HASH();

        int l = 0,r = ln;

        while(l <= r){

            ull mid = (l + r) / 2;

            if(check(Hash1[ mid ],mid + 1)){

                l = mid + 1;

                mx = max(mx,mid);
            }
            else r = mid - 1;
        }

        for(int i = mx; i >= 0; i--) cout << s[ i ];
        cout << endl;
    }
    return 0;
}
