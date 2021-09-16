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
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

int Kadane_Algo(const vector< int > &temp){

    int sz = temp.size();

    int sum = 1;
    int mx = -99999999;

    for(int i = 0; i < sz; i++){

        sum = 1;

        for(int j = i; j < sz; j++) {

            sum *= temp[ j ];

            if(sum > mx) mx = sum;
        }
    }

    return mx;
}

int main(){

    file();

    vector< int > v;
    int n;

    while( cin>> n ){

        if(n == -999999) continue;

        if(n != -999999) v.pb( n );

        while(cin >> n and n != -999999){

            v.pb( n );
        }

        int ans = Kadane_Algo( v );

        cout << ans << endl;

        v.clear();
    }

    return 0;
}


