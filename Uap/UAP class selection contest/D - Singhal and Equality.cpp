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
#define sl( n ) scanf("%d",&n)
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
int main(){

    file();

    int t;

    cin >> t;

    while(t--){

        string s;

        cin >> s;

        int n = s.size(),ans = INT_MAX;

        map< char,int > mp;

        vector< int > v;

        for(int i = 0; i < n; i++) mp[ s[ i ] ]++;

        for(auto x : mp) v.pb(x.sd);

        sort(v.rbegin(),v.rend());

       // cout << "len " << n << endl;

//        for(int i = 0; i < v.size(); i++) cout << v[ i ] << " ";
//        cout << endl;

        for(int i = 1; i < 27; i++){

            if(n % i != 0) continue;

            int ln = n,cnt = 0;

            for(auto x : v){

                ln -= min(x,n/i);

                cnt++;

                if(cnt == i) break;
            }

            //cout << "I " << i<< " check len" << ln << endl;

            ans = min(ans,ln);
        }

        cout << ans << endl;
    }
    return 0;
}
