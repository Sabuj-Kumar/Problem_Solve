#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define lop(i,v,n,j) for(int i = v; i < n; i += j)
#define lop_(i,v,n,j) for(int i = n-1; i >= 0; i -= j)
#define f first
#define s second
#define in freopen("in.txt","r",stdin);
#define op ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

const ll p1 = 1e3 + 9;
const ll p2 = 1e3 + 13;
const ll mod = 1e9 + 7;

int sc() { int n; scanf("%d",&n); return n; }
string str() { string s; cin >> s; return s; }

ll hash_first(string s){

    ll ret = 0, mul = 1,n = s.size();
    lop(i,0,n,1){

        ret = (ret + mul * s[ i ]) % mod;
        mul = ( mul * p1 ) % mod;
    }
    return ret;
}
ll hash_second(string s){

    ll ret = 0, mul = 1,n = s.size();
    lop(i,0,n,1){

        ret = (ret + mul * s[ i ]) % mod;
        mul = ( mul * p2 ) % mod;
    }
    return ret;
}
int main(){

    //file();
    //op
    int n = sc(),m;
    vector< pll > v;
    lop(i,0,n,1){

        string s = str();
        ll hs = hash_first( s );
        ll hsh = hash_second( s );
        v.push_back({hs,hsh});
    }
    sort(v.begin(),v.end());
    m = sc();
    lop(i,0,m,1){

        string s = str();
        ll hs = hash_first( s );
        ll hsh = hash_second( s );
        if(binary_search(v.begin(),v.end(),make_pair(hs,hsh))) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
