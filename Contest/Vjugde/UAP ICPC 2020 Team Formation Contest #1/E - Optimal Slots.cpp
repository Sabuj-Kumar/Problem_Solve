#include<bits/stdc++.h>

using namespace std;

int val,n;
vector< int > p,a;
vector< vector< int > > dp;

int knapsack(int i,int sum){

    if(i >= n) return 0;

    if(dp[ i ][ sum ] != -1) return dp[ i ][ sum ];

    int v1 = 0,v2 = 0;

    v1 = knapsack(i + 1,sum);

    if(sum >= a[ i ]) v2 = a[ i ] + knapsack(i + 1,sum - a[ i ]);

    return dp[ i ][ sum ] = max(v1,v2);
}

void path(int i,int sum){

    if(i >= n) return;

    int v = sum - a[ i ];

    if(v >= 0){

        if(knapsack(i + 1,v) == v){

            p.push_back( i );

            sum = v;
        }
    }
    path(i + 1,sum);
}

int main(){

   //freopen("in.txt","r",stdin);

    while(cin >> val and val){

        cin >> n;
        p.clear();
        a.clear();

        dp = vector< vector< int > > (n + 10,vector< int > (val + 10,-1));

        for(int i = 0; i < n; i++) {

            int in;

            cin >> in;

            a.push_back(in);
        }

//        for(int i = 0; i < n; i++) cout << a[ i ] << " ";
//
//        cout << endl << endl;

        int ans = knapsack(0,val);
        path(0,ans);

        bool flag = false;

        for(auto x : p) cout << a[ x ] << " ";
        cout << ans << endl;
    }

    return 0;
}
