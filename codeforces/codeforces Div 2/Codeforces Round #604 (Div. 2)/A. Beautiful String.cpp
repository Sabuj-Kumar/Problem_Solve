#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int ,int >
#define pll pair< ll,ll >
#define f first
#define s second
#define p_b push_back
#define p_f push_front
#define lop(v,n) for(int i = v; i < n; i++)
#define Lop(i,v,n,j) for(int i = v; i < n; i += j)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

struct data{

    int x,y,cost;
    data(){}
    data(int x,int y) { this-> x = x,this-> y = y; }
    data(int x,int y,int cost) { this-> x = x,this -> y = y,this-> cost = cost; }

//    bool operator < (const data &a) const{
//
//        return cost > a.cost;
//    }
};

const int sz = 1e6;
const int inf = 1e9;
const ll mx = 1e18;
const ll mx_ = -1e18;

int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};
int X_[ ] = {0,0,1,-1,1,-1,1,-1};
int Y_[ ] = {1,-1,0,0,-1,1,1,-1};
int Hx[ ] = {1,1,2,2,-1,-1,-2,-2};
int Hy[ ] = {2,-2,1,-1,2,-2,1,-1};

int sc() { int n; cin >> n; return n; }

int main(){

    op
    file();

    int t = sc();

    while( t-- ){

        bool flag = false;
        char a,b;
        string s;
        cin >> s;
        int c = 0,siz = s.length();

        lop(0,siz) {

            if(s[ i ] == s[ i + 1 ] and s[ i ] >= 'a' and s[ i ] <= 'z' and s[ i+1 ] >= 'a' and s[ i+1 ] <= 'z') {

                flag = 1;
                break;
            }
            if(s[ i ] == '?') c++;
        }

        if( flag ) {

            cout << -1 << endl;

            continue;
        }
        if( c == siz ){

            Lop(i,0,c,3){

                s[ i ] = 'a';
                s[ i + 1 ] = 'b';
                s[ i + 2 ] = 'c';
            }
        }
        else lop(0,siz-1){

            if(i == 0 and s[ i ] == '?'){

                if(s[ i + 1 ] == 'a' || s[ i + 1 ] == '?') s[ i ] = 'b';
                else if(s[ i + 1 ] == 'b') s[ i ] = 'a';
                else if(s[ i + 1 ] == 'c') s[ i ] = 'a';
                continue;
            }
            if(s[ i ] == '?'){

               a = s[ i - 1 ];
               b = s[ i + 1 ];

               if(a == 'a' and b == 'c' || a == 'a' and b == 'a' || a == 'c' and b == 'a') s[ i ] = 'b';
               else if(a == 'b' and b == 'c' || a == 'b' and b == 'b' || a == 'c' and b == 'c' || a == 'c' and b == 'b') s[ i ] = 'a';
               else if(a == 'a' and b == 'b' || a == 'b' and b == 'a')s[ i ] = 'c';

               if(b == '?'){

                    if(a == 'a') s[ i ] = 'b';
                    else if(a == 'b') s[ i ] = 'a';
                    else if(a == 'c') s[ i ] = 'a';
               }
            }
        }

        if(s[ siz - 1 ] == '?'){

            if(s[ siz - 2 ] == 'a') s[ siz - 1 ] = 'b';
            if(s[ siz - 2 ] == 'b') s[ siz - 1 ] = 'a';
            if(s[ siz - 2 ] == 'c') s[ siz - 1 ] = 'a';
        }

        cout << s << endl;
    }

    return 0;
}
