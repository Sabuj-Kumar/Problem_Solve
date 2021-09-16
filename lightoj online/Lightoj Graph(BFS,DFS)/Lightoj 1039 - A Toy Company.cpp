#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define f first
#define s second
#define p_b push_back
#define p_f push_front
#define lop(v,n) for(int i = v; i < n; i++)
#define Case( n ) for(int  cs = 1; cs <= t; cs++)
#define Lop(i,v,n,j) for(int i = v; i < n;  i += j)
#define in freopen("in.txt","r",stdin);
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

struct data{

    int x,y,z;

    data(){}
    data(int x,int y,int z){ this->x = x,this-> y = y,this-> z = z; }

//    bool operator < (const data &a) const {
//
//        return z > a.z;
//    }
};

const int sz = 1e6;
const int inf = 1e9;
const ll mx = 1e18;
const ll inf_ = -1e18;

int X[ ] = {1,-1,0,0,0,0};
int Y[ ] = {0,0,1,-1,0,0};
int Z[ ] = {0,0,0,0,1,-1};
int X_[ ] = {0,0,1,-1,1,-1,1,-1};
int Y_[ ] = {1,-1,0,0,-1,1,1,-1};
int vis[ 27 ][ 27 ][ 27 ];
int level[ 27 ][ 27 ][ 27 ];

int sc() { int n; scanf("%d",&n); return n; }

int bfs(string s,string d){

    queue< data > qu;

    qu.push(data(s[ 0 ]-'a',s[ 1 ]-'a',s[ 2 ]-'a'));

    level[ s[ 0 ] - 'a' ][ s[ 1 ] - 'a' ][ s[ 2 ] - 'a' ] = 0;

    while( !qu.empty() ){

        data p = qu.front();

        qu.pop();

        lop(0,6){

            int a = (p.x + X[ i ]) % 26;
            int b = (p.y + Y[ i ]) % 26;
            int c = (p.z + Z[ i ]) % 26;

            if(a < 0) a += 26;
            if(b < 0) b += 26;
            if(c < 0) c += 26;

            if(p.x == d[ 0 ]-'a' && p.y == d[ 1 ]-'a' && p.z == d[ 2 ]-'a')
                return level[ p.x ][ p.y ][ p.z ];

            if(vis[ a ][ b ][ c ] == -1){

                qu.push(data(a,b,c));

                level[ a ][ b ][ c ] = level[ p.x ][ p.y ][ p.z ] + 1;

                vis[ a ][ b ][ c ] = 0;
            }
        }
    }

    return -1;
}
int main(){

    //op
    file();

    int t = sc();

    Case( t ){

        string str,des,s1,s2,s3;
        int n;
        cin >> str >> des;
        n = sc();

        memset(vis,-1,sizeof vis);
        memset(level,-1,sizeof level);

        while(n--){

            cin >> s1 >> s2 >> s3;

            int sz1 = s1.size(),sz2 = s2.size(),sz3 = s3.size();

            Lop(i,0,sz1,1)
                Lop(j,0,sz2,1)
                    Lop(k,0,sz3,1)
                      vis[ s1[ i ] - 'a' ][ s2[ j ] - 'a' ][ s3[ k ] - 'a' ] = 0;
        }

        printf("Case %d: ",cs);

        if(vis[ str[ 0 ] - 'a' ][ str[ 1 ] - 'a' ][ str[ 2 ] - 'a' ] == 0){

            printf("-1\n");
            continue;
        }

        int ans = bfs(str,des);

        printf("%d\n",ans);
    }

    return 0;
}
