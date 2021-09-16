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

int main(){

    file();

    int n;

    cin >> n;

    Case( n ){

        ll num;

        cin >> num;

        vector< int > v;

        while(num){

            v.pb(num%2);

            num /= 2;
        }

        v.pb( 0 );

        reverse(v.begin(),v.end());

        next_permutation(v.begin(),v.end());

        ll ans = 0;

        int pw = v.size() - 1;

        for(int i = 0; i < v.size(); i++){

            if(v[ i ] != 0) ans += pow(2,pw);

            pw--;
        }

        cout << "Case " << cs << ": " << ans << endl;
    }

    return 0;
}
