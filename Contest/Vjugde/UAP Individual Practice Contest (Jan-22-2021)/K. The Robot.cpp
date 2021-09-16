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

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

void move_(int &x,int &y,char rmv){

    if(rmv == 'L') x--;
    else if(rmv == 'R') x++;
    else if(rmv == 'D') y--;
    else y++;
}
int main(){

    file();

    int n;

    cin >> n;

    while(n--){

        string s;
        bool flag = true;

        cin >> s;

        int sz = s.size();

        for(int i = 0; i < sz; i++){

            int x = 0,y = 0;

            for(int j = 0; j <= i; j++) move_(x,y,s[ j ]);

            int u = x,v = y;

            x = y = 0;

            for(int j = 0; j < sz; j++){

                int x1 = x,y1 = y;

                move_(x1,y1,s[ j ]);

                if(x1 != u or y1 != v){

                    x = x1;
                    y = y1;
                }
            }

            if(x == 0 and y == 0) {

                cout << u << " " << v << endl;
                flag = false;

                break;
            }
        }

        if(flag) cout << 0 << " " << 0 << endl;
    }

    return 0;
}
