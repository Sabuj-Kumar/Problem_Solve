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
    in
    #endif // ONLINE_JUDGE
}

int X[ ] = {2,2,1,1,-2,-2,-1,-1};
int Y[ ] = {1,-1,2,-2,1,-1,2,-2};

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const int n = 5;
int need;

vector< string > v;
vector< string > grid;

bool check(){

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(grid[ i ][ j ] != v[ i ][ j ]) return false;

    return true;
}
void back_track(int x,int y,int cnt){

    if(cnt >= 11) return;

    if(check()){

        need = min(need,cnt);
        return;
    }

    for(int i = 0; i < 8; i++){

        int xx = x + X[ i ];
        int yy = y + Y[ i ];

        if(xx >= 0 and xx < n and yy >= 0 and yy < n){

            swap(grid[ xx ][ yy ],grid[ x ][ y ]);

            back_track(xx,yy,cnt+1);

            swap(grid[ xx ][ yy ],grid[ x ][ y ]);
        }
    }
    return;
}
int main(){

    file();

    v.pb("11111");
    v.pb("01111");
    v.pb("00 11");
    v.pb("00001");
    v.pb("00000");

    int t;

    cin >> t;
    cin.ignore();

    while(t--){

        int x,y;
        bool f = false;

        grid.clear();

        for(int i = 0; i < n; i++) {

               string s;

                getline(cin,s);

                grid.pb( s );
        }

        for(int i = 0; i < n; i++){

            for(int j = 0; j < n; j++)
                if(grid[ i ][ j ] == ' '){

                    x = i;
                    y = j;
                    f = true;
                    break;
                }
            if( f ) break;
        }

        need = 11;

        back_track(x,y,0);

        if(need >= 11) cout << "Unsolvable in less than 11 move(s)." << endl;
        else cout << "Solvable in " << need << " move(s)." << endl;
    }

    return 0;
}
