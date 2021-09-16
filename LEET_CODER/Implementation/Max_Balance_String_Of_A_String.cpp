#include<bits/stdc++.h>

using namespace std;

int main(){

    //freopen("in.txt","r",stdin);

    //int n;

    //scanf("%d",&n);

    //while(n--){
        string s;

        cin >> s;
        //scanf("%s",s2);

        int cnt = 0,ans = 0;

        for(int i = 0; i < s.size(); i++){

            if(s[ i ] == 'R') cnt++;
            else cnt--;

            if(cnt == 0) ans++;
        }

        cout << ans << endl;
    //}

    return 0;
}
