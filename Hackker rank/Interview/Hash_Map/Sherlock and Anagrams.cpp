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
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

bool check(string s,string p){

    if(s.size() != p.size()) return false;

    int a[ 26 ] = {0},b[ 26 ] = {0};

    for(int i = 0; i < s.size(); i++) a[ s[ i ] - 'a' ]++;
    for(int i = 0; i < p.size(); i++) b[ p[ i ] - 'a' ]++;

    for(int i = 0; i < 26; i++)
        if(a[ i  ] != b[ i ]) return false;

    return true;
}
int main(){

    file();

    int t;

    cin >> t;

    while(t--){

        string s,s1,s2;
        int ans = 0;

        cin >> s;

        for(int ln = 1; ln < s.size(); ln++){

            for(int i = 0; i < s.size() - ln; i++){

                s1 = s.substr(i,ln);

                for(int j = i + 1; j < s.size() - ln + 1; j++){

                    s2 = s.substr(j,ln);

                    if(check(s1,s2)) ans++;
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}
