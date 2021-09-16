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

ll p = 1007;

ll HASH(string &ss){

    ll val = 0;

    for(int i = 0; i < ss.size(); i++) val = val * p + ss[ i ];

    return val;
}
int main(){

    file();

    string s;

    map<ll,bool> mp;
    map< ll,string > out;

    while(getline(cin,s)){

        if(s.size() == 0) break;

        bool ok = true;

        string ss,pt;

        for(int i = 0; i < s.size(); i++){

            if(s[ i ] == ' ') {

                ok = false;
                continue;
            }

            if(ok) pt += s[ i ];
            else ss += s[ i ];
        }

        ll val = HASH(ss);

        mp[ val ] = true;
        out[ val ] = pt;
    }

    while(cin >> s){

        ll val = HASH(s);

        if(mp[ val ]) cout << out[ val ] << endl;
        else cout << "eh" << endl;
    }

    return 0;
}
