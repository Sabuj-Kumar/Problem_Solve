#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}
int I() { int n; scanf("%d",&n); return n; }

int main(){

    file();

    int t = I();

    while( t-- ){

        map< int,bool > mp;
        vector< int > out;

        mp.clear();

        int n = I();

        for(int i = 1; i <= 2 * n; i++){

            int v = I();

            if(!mp[ v ]){

                mp[ v ] = true;
                out.push_back( v );
            }
        }

        for(int i = 0; i < out.size(); i++) cout << out[ i ] << " ";
        cout << endl;
    }
    return 0;
}
