#include<bits/stdc++.h>

using namespace std;

int main(){

    //freopen("in.txt","r",stdin);

    int t;

    cin >> t;

    while(t--){

        int n,k;

        cin >> n >> k;

        int a[ n + 5 ];
        bool flag = true;

        for(int i = 1; i <= n; i++){

            if(i == 1) a[ i ] = i;

            else if(k > 0 and i + 1 <= n){

                a[ i ] = i + 1;
                a[ i + 1 ] = i;
                i++;
                k--;
            }
            else a[ i ] = i;

        }

        if(k) cout << -1 << endl;
        else{

            for(int i = 1; i <= n; i++) cout << a[ i ] << " ";
            cout << endl;
        }
    }

    return 0;
}
