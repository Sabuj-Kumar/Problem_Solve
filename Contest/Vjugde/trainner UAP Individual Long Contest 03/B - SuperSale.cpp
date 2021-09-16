#include<bits/stdc++.h>

using namespace std;

int n;
int person;
int wight[ 1010 ],price[ 1010 ];
int dp[ 1010 ][ 31 ];

int amount(int i,int w){

    if(i == n) return 0;

    if(dp[ i ][ w ] != -1) return dp[ i ][ w ];

    if(w < wight[ i ]) return dp[ i ][ w ] = amount(i+1,w);

    else return  dp[ i ][ w ] = max(amount(i+1,w),amount(i+1,w-wight[ i ]) + price[ i ]);
}
int main(){

    //freopen("input.txt","r",stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;

    cin >> test;

    while(test--){

        cin >> n;
        memset(dp,-1,sizeof dp);

        for(int i = 0; i < n; i++)
            cin >> price[ i ] >> wight[ i ];

        int m,sum = 0;

        cin >> m;

        for(int i = 0; i < m; i++){

             cin >> person;

             sum += amount(0,person);
        }
        cout << sum << endl;
    }
    return 0;
}
