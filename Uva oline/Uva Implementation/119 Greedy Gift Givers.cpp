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
#define sl( n ) scanf(("%lld",&n)
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

int main(){

    file();

    int n;
    bool flag = false;

    while(cin >> n){

        if(flag) cout << endl;
        flag = true;

        unordered_map< string,int > devit,credit;
        vector< string > v;

        for(int i = 0; i < n; i++){

            string s;

            cin >> s;

            v.pb( s );

            devit[ s ] = 0;
            credit[ s ] = 0;
        }

//        for(int i = 0; i < v.size(); i++) cout << v[ i ] << " ";
//
//        cout << endl;

        for(int i = 0; i < n; i++){

            string me,friend_;
            int money,given,add;

            cin >> me >> money;

            devit[ me ] = money;

            cin >> given;

            if(given>0) add = money / given;

            credit[ me ] += money - (given * add);

            for(int j = 0; j < given; j++){

                cin >> friend_;

                credit[ friend_ ] += add;
            }
        }

        for(int i = 0; i < n; i++){

            cout << v[ i ] << " ";

            cout << credit[ v[ i ] ] - devit[ v[ i ] ] << endl;
        }
    }
    return 0;
}
