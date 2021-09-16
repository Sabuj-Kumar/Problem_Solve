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
#define sl( n ) scnaf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define in freopen("in.txt","r",stdin )
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int main(){

   // file();

    int a,sum1 = 0,sum2 = 0,n,m;

    cin >> n >> m;

    for(int i = 0; i < n; i++) {

        cin >> a;
        sum1 += a;
    }
    for(int i = 0; i < m; i++) {

        cin >> a;
        sum2 += a;
    }

    if(sum1 < sum2) swap(sum1,sum2);

    cout << abs(sum1 - sum2) << endl;

    return 0;
}
