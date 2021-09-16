#include<bits/stdc++.h>

using namespace std;

int main(){

    //freopen("in.txt","r",stdin);

    int test;

    for(cin >> test; test--;){

        long long a,b,mod,x = 0;

        cin >> a >> b;

        if(a == b) {

            cout << 0 << endl;
            continue;
        }
        int dif = abs(a - b);
        if(dif >= 5){ x += dif / 5,dif %= 5; }
        if(dif >= 2){ x += dif / 2,dif %= 2; }
        if(dif) x++;
        cout << x << endl;
    }
    return 0;
}
