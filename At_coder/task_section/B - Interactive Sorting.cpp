#include<bits/stdc++.h>
#define pi acos(-1)

using namespace std;

int main(){

    int n,q,ck = 0;
    string s;

    cin >> n >> q;

    for(int i = 0; i < n; i++) s += 'A' + i;

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n-1; j++){

            cout << "? " << s[ j ] << s[ j + 1 ] << endl;

            fflush(stdout);

            string ans;

            cin >> ans;

            if(ans == ">") swap(s[ j ],s[ j + 1 ]);

            ck++;

            if(ck == q) break;
        }
        if(ck == q) break;
    }


    cout << "!" << s << endl;
    fflush(stdout);

    return 0;
}
