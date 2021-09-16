#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;

    scanf("%d",&t);

    while(t--){

        int a,b;
        scanf("%d %d",&a,&b);

        int dif = abs(a-b);

        int ans = dif / 10;

        if(dif % 10 != 0) ans++;

        cout << ans << endl;
    }
    return 0;
}
