#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int >
#define pll pair< ll,ll >
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%d",&n)
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

int main(){

    file();

    int n;

    cin >> n;

    while(n--){

        string s;

        cin >> s;
        int sz = s.size();

        if(s[ sz - 1 ] == 'a' or s[ sz - 1 ] == 'o' or s[ sz - 1 ] == 'u') s += 's';
        else if(s[ sz - 1 ] == 'l' or s[ sz - 1 ] == 'r' or s[ sz - 1 ] == 'v') s += "es";
        else if(s[ sz - 1 ] == 'w' or s[ sz - 1 ] == 't') s += "as";
        else if(s[ sz - 1 ] == 'i' or s[ sz - 1 ] == 'y') {

            if(s[ sz - 1 ] == 'i') s += "os";
            else {

                s[ sz - 1 ] = 'i';
                s += "os";
            }
        }
        else if(s[ sz - 1 ] == 'n' or (s[ sz - 1 ] == 'e' and s[ sz - 2 ] == 'n')){

            if(s[ sz - 1 ] == 'n') {

                s[ sz - 1 ] = 'a';
                s += "nes";
            }
            else {

                s[ sz - 1 ] = 'n';
                s[ sz - 2 ] = 'a';
                s += "es";
            }
        }
        else s += "us";

        cout << s << endl;
    }
    return 0;
}
