#include<bits/stdc++.h>

using namespace std;

int main(){

   // freopen("in.txt","r",stdin);

    int n,cnt = 0;

    cin >> n;

    int a[ n ];

    for(int i = 0; i < n; i++) cin >> a[ i ];

    for(int i = 0; i < n; i++){

        if(i + 2 < n and a[ i + 2 ] == 0) cnt++,i++;
        else cnt++;
    }

    cout << cnt - 1 << endl;

    return 0;
}
