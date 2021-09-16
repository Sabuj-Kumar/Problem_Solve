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
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; scanf("%d",&n); return n; }
ll Il() { ll n; scanf("%I64d",&n); return n; }

string s;

int divide_and_conqure(int l,int r,char ch){

    if(l == r) return ch != s[ l ];

    int mid = (l + r) / 2;

    int x = divide_and_conqure(l,mid,ch+1);
    int y = divide_and_conqure(mid + 1,r,ch+1);
    int cnt[ 2 ] = {0,0};

    for(int i = l; i <= r; i++) cnt[ i <= mid ] += (ch != s[ i ]);

    return min(x + cnt[ 0 ],y + cnt[ 1 ]);
}
int main(){

    file();

    int t = I();

    while( t-- ){

        int n = I();

        cin >> s;

        int ans = divide_and_conqure(0,n-1,'a');

        cout << ans << endl;
    }
    return 0;
}
