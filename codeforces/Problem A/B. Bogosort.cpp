#include<bits/stdc++.h>

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif // ONLINE_JUDGE
}
int I() { int n; scanf("%d",&n); return n; }

int main(){

    int t = I();

    while( t-- ){

        int n = I();
        int a[ n + 5 ];
        for(int i = 0; i < n; i++) scanf("%d",&a[ i ]);

        sort(a,a+n,greater<int>());

        for(int i = 0; i < n; i++){

            cout << a[ i ];
            if(i < n - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
