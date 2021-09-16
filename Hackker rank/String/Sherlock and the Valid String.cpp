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

    string s;

    cin >> s;

    int a[ 26 ] = {0};

    for(int i = 0; i < s.size(); i++) a[ s[ i ] - 'a' ]++;

    int mn = INT_MAX;
    int mx = INT_MIN;

    for(int i = 0; i < 26; i++){

        if(mn > a[ i ] and a[ i ] != 0) mn = a[ i ];
        if(mx < a[ i ]) mx = a[ i ];
    }

    for(int i = 0; i < 26; i++){

        if(a[ i ] != 0 and a[ i ] != mx and a[ i ] != mn){

            cout << "NO" << endl;

            return 0;
        }
    }
    if(mn == mx) cout << "YES" << endl;

    else{

        int fre_mn = 0;
        int fre_mx = 0;

        for(int i = 0; i < 26; i++){

            if(mn == a[ i ]) fre_mn++;
            if(mx == a[ i ]) fre_mx++;
        }

        if(mx - mn != 1){

            if(mn == 1 and fre_mn == 1) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else{

            cout << mn << " " << mx << " "<< fre_mn << " "<< fre_mx << "  hum" << endl;
            if(fre_mn == 1 or fre_mx == 1) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }

    return 0;
}
