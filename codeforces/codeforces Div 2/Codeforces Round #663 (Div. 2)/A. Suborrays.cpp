#include<bits/stdc++.h>
#define ll long long

using namespace std;

int I() { int n; scanf("%d",&n); return n; }

int main(){

    //freopen("in.txt","r",stdin);

    int t = I();

    while( t-- ){

        int n = I();
        int a[ n + 5 ];

        for(int i = 1; i <= n; i++) {

            if(i > 1) cout << " ";
            cout << i;
        }
        cout << endl;
    }
    return 0;
}
