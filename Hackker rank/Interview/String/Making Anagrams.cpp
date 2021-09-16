#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ul unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair<ll,ll>
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

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

int main(){

    file();

    string s,p,s1 = "",p1 = "";

    cin >> s;
    cin >> p;

    //cout << s << " " << p << endl;

    int lens = s.size();
    int lenp = p.size();

    //cout << lens << " " << lenp << endl;

    unordered_map< char,int > mp,mp1;

    for(int i = 0; i < lens; i++) { if(!mp[ s[ i ] ]) s1 += s[ i ]; mp[ s[ i ] ]++; }
    for(int i = 0; i < lenp; i++) { if(!mp1[ p[ i ] ]) p1 += p[ i ]; mp1[ p[ i ] ]++; }

    int cnt = 0;

    //cout << s1 << " " << p1 << endl;

    for(int i = 0; i < s1.size(); i++){

        if(mp[ s1[ i ] ] and mp1[ s1[ i ] ]) cnt += abs(mp[ s1[ i ] ] - mp1[ s1[ i ] ]);

        if(mp[ s1[ i ] ] and mp1[ s1[ i ] ] == 0) cnt += mp[ s1[ i ] ];
    }

    //cout << "ok " << endl;

    for(int i = 0; i < p1.size(); i++) if(mp1[ p1[ i ] ] and mp[ p1[ i ] ] == 0) cnt += mp1[ p1[ i ] ];

    cout << cnt << endl;

    return 0;
}
