#include<bits/stdc++.h>

using namespace std;

int main(){

    //freopen("input.txt","r",stdin);

    ios_base::sync_with_stdio( 0 );
    cin.tie(NULL);
    cout.tie(NULL);

    int test;

    cin >> test;

    for(int cs = 1; cs <= test; cs++){

        int n,up = 0,low = 0;

        cin >> n;

        cout << "Case " << cs << ": ";

        int a[ n + 5 ];

        for(int i = 0; i < n; i++) cin >> a[ i ];

        if(n == 1) {

            cout << "0 0" << endl;

            continue;
        }

        for(int i = 1; i < n; i++){

            if(a[ i ] > a[ i - 1 ]) up++;

            else if(a[ i ] < a[ i - 1 ]) low++;
        }

        cout << up << " " << low << endl;
    }
    return 0;
}
