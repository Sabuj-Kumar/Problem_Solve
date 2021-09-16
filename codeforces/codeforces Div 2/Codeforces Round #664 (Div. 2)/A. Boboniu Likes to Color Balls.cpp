#include<bits/stdc++.h>
#define ll long long
#define in freopen("in.txt","r",stdin)

using namespace std;

int I() { int n; scanf("%d",&n); return n; }

int main(){

    //in;

    int t = I();

    while(t--){

        int ans = 0,a[ 5 ];

        for(int i = 0; i < 4; i++) a[ i ] = I();

        for(int i = 0; i < 4; i++) if(a[ i ] & 1) ans++;

        if(ans <= 1) { cout << "Yes" << endl; continue; }

        if(a[ 0 ] && a[ 1 ] && a[ 2 ]){

            ans = 0;

            for(int i = 0; i < 3; i++) a[ i ]--;
            a[ 3 ]++;

            for(int i = 0; i < 4; i++) if(a[ i ] & 1) ans++;

            if(ans <= 1) cout << "Yes";
            else cout << "No";

        }
        else cout << "No";
        cout << endl;
    }
    return 0;
}
