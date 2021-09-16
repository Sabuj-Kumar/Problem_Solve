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

    #ifndef OLINE_JUDGE
    in;
    #endif // OLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

string s;

bool check(char x){

    int row = (s[ 0 ] == x and s[ 0 ] == s[ 1 ] and s[ 1 ] == s[ 2 ])+
              (s[ 3 ] == x and s[ 3 ] == s[ 4 ] and s[ 4 ] == s[ 5 ])+
              (s[ 6 ] == x and s[ 6 ] == s[ 7 ] and s[ 7 ] == s[ 8 ]);
    int col = (s[ 0 ] == x and s[ 0 ] == s[ 3 ] and s[ 3 ] == s[ 6 ])+
              (s[ 1 ] == x and s[ 1 ] == s[ 4 ] and s[ 4 ] == s[ 7 ])+
              (s[ 2 ] == x and s[ 2 ] == s[ 5 ] and s[ 5 ] == s[ 8 ]);
    int dia = (s[ 0 ] == x and s[ 0 ] == s[ 4 ] and s[ 4 ] == s[ 8 ])+
              (s[ 2 ] == x and s[ 2 ] == s[ 4 ] and s[ 4 ] == s[ 6 ]);

    return row or col or dia;
}
int main(){

    //file();

    while(cin >> s){

        if(s == "end") break;

        int x = count(s.begin(),s.end(),'X');
        int o = count(s.begin(),s.end(),'O');

        bool flag = (x == o or x - o == 1);

        int win_x = check('X');
        int win_o = check('O');

        if(win_x and win_o) flag = false;
        if(!win_x and !win_o and (x + o) != 9) flag = false;
        if(win_x and (x - o) != 1) flag = false;
        if(win_o and (x != o)) flag = false;

        cout << (flag ? "valid" : "invalid") << endl;
    }
    return 0;
}
