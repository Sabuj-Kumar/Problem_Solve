#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

    //freopen("in.txt","r",stdin);

    int test;

    cin >> test;

    while( test-- ){

        ll d,g,b;

        cin >> d >> g >> b;

        ll dif = abs(g - b);

        if(dif == 0) {

            if(d <= g) cout << d << endl;
            else {



            }
        }
        else if(dif > 0) cout << (dif * d) / 2 << endl;
    }

    return 0;

}
