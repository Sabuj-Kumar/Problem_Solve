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

int main(){

    file();

    int n;

    cin >> n;

    while(n--){

        int c1,c2,c3;
        int a1,a2,a3,a4,a5;

        cin >> c1 >> c2 >> c3;
        cin >> a1 >> a2 >> a3 >> a4 >> a5;

        if(c1 >= a1){

            c1 -= a1;
            a1 = 0;
        }
        else if(c1 < a1){

            a1 -= c1;

            c1 = 0;
        }

        if(c1 >= a4){

            c1 -= a4;
            a4 = 0;
        }
        else if(c1 < a4){

            a4 -= c1;

            c1 = 0;
        }

        if(c2 >= a2){

            c2 -= a2;

            a2 = 0;
        }
        else if(c2 < a2){

            a2 -= c2;

            c1 = 0;
        }

        if(c2 >= a5){

            c2 -= a5;
            a5 = 0;
        }
        else if(c2 < a5){

            a5 -= c2;

            c2 = 0;
        }

        if(a1 + a2 != 0) cout << "NO" << endl;
        else if(a3 + a4 + a5 <= c3) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
