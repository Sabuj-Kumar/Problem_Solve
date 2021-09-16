#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define db double
#define sc( n ) scanf("%d",&n)
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }

int main(){

    file();

    int t = I();

    while(t--){

        int n = I();
        int cnt[ 27 ] = {0};
        map< char,int > mp;
        vector< char > v;
        bool f1 = false;

        for(int i = 0; i < n; i++){

            string s;

            cin >> s;

            for(int j = 0; j < s.size(); j++){

                if(mp[ s[ j ] ] == 0) v.push_back(s[ j ]);

                mp[ s[ j ] ]++;
            }
        }

        for(int i = 0; i < v.size(); i++)
            if(mp[ v[ i ] ] % n != 0) { f1 = 1; break; }


        if(f1) cout << "NO" << endl;
        else cout << "YES" << endl;

    }
    return 0;
}
