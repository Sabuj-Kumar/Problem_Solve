#include<bits/stdc++.h>
#define pi acos(-1)

using namespace std;

int main(){

    //freopen("in.txt","r",stdin);

    int t;

    cin >> t;

    while( t-- ){

        int n;

        cin >> n;
        vector< int > v;

        for(int i = 0; i < n; i++) {

            int a;
            cin >> a;
            v.push_back( a );
        }

        sort(v.begin(),v.end());

        bool flag = false;

        for(int i = 1; i < n; i++){

            if(v[ i ] - v[ i - 1 ] > 1){

                flag = true;
                break;
            }
        }

        if(flag) cout <<"NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
