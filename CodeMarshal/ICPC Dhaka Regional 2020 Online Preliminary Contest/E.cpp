#include<bits/stdc++.h>

using namespace std;

int main(){

    freopen("in.txt","r",stdin);

    int t;

    cin >> t;

    for(int cs = 1; cs <= t; cs++){

        int sum = 0,n,swap_ = 0,mx = -150000;

        cin >> n;

        pair< int,int > a[ n ];

        for(int i = 0; i < n; i++) {

            cin >> a[ i ].first;

            mx = max(mx,a[ i ].first);

            if(a[ i ].first > 0) sum += a[ i ].first;

            a[ i ].second = i;
        }

        if(mx <= 0){

            cout << "Case " << cs << ": " << sum << " " << swap_ << endl;

            continue;
        }

        bool vis[ n + 1 ] = {false};

        for(int i = 0; i < n; i++){

            if(vis[ i ] or a[ i ].second == i) continue;

            int cnt = 0,j = i;

            while(!vis[ j ]){

                vis[ j ] = 1;

                j = a[ j ].second;

                cnt++;
            }

            if(cnt > 0) swap_ += (cnt - 1);
        }

        cout << "Case " << cs << ": " << sum << " " << swap_ << endl;
    }

    return 0;
}
