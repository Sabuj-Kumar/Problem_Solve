#include<bits/stdc++.h>
#define ll long long

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif // ONLINE_JUDGE
}

int main(){

    file();

    int t;

    scanf("%d",&t);

    while(t--){

        int n;

        cin >> n;

        vector< ll > v;

        for(int i = 0; i < n; i++){

            int a;

            cin >> a;

            v.push_back( a );
        }

        ll sum = INT_MIN;

        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
              for(int k = j+1; k < n; k++)
                 for(int l = k + 1; l < n; l++)
                    for(int m = l + 1; m < n; m++){

                       int s = (v[ i ] * v[ j ] * v[ k ] * v[ l ] * v[ m ]);

                       sum = max(sum,s);
                    }
        cout << sum << endl;
    }
    return 0;
}
