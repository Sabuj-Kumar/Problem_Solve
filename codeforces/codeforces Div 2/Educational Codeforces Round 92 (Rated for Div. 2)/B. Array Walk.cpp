#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;
const int inf = 2e9;
int arr[ N ];
int n,k,z;
int dp[ N ][ 6 ][ 2 ];

int DP(int idx,int mov,int lft,bool flg){

    if(lft > z) return -inf;
    if(mov == k) return arr[ idx ];
    if(dp[ mov ][ lft ][ flg ] != -1) return dp[ mov ][ lft ][ flg ];

    int ans = -inf;

    ans = DP(idx + 1,mov + 1,lft,false) + arr[ idx ];

    if(idx > 1 and flg == false) ans = max(ans,DP(idx - 1,mov + 1,lft + 1,true) + arr[ idx ]);

    return dp[ mov ][ lft ][ flg ] = ans;
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("in.txt","r",stdin);

    int t;
    cin >> t;

    while(t--){

        cin >> n >> k >> z;

        for(int i = 0; i <= k; i++)
        for(int j = 0; j <= z; j++)
        for(int p = 0; p < 2; p++)
        dp[ i ][ j ][ p ] = -1;

        for(int i = 1; i <= n; i++) cin >> arr[ i ];

        cout << DP(1,0,0,0) << endl;
    }

    return 0;
}
