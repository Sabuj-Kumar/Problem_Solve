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

int find_2_5(int n,int x){

    int cnt = 0;

    while(n > 0) cnt += n / x,n /= x;

    return cnt;
}

int find_2_5_again(int n,int x){

    int cnt = 0;

    while(n % x == 0) cnt++,n /= x;

    return cnt;
}
int main(){

    file();

    int t;

    cin >> t;

    Case( t ){

        int n,r,p,q;
        int two_up = 0,five_up = 0,two_down = 0,five_down = 0;

        cin >> n >> r >> p >> q;

        two_up = find_2_5( n,2 );
        five_up = find_2_5( n,5 );

        two_down = find_2_5( r,2 );
        five_down = find_2_5( r,5 );

        two_down += find_2_5( n-r,2 );
        five_down += find_2_5( n-r,5 );

        two_up += find_2_5_again( p,2 ) * q;
        five_up += find_2_5_again( p,5 ) * q;

        int two_dif = two_up - two_down;
        int five_dif = five_up - five_down;

        cout << "Case " << cs << ": "<< min(two_dif,five_dif) << endl;
    }
    return 0;
}
