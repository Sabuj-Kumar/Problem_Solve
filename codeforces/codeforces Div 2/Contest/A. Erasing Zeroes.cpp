#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;

    scanf("%d",&n);

    while( n-- ){

        string s;
        cin >> s;

        int c = 0,l = -1,r = -1;

        for(int i = 0; i < s.size(); i++){

            if(l == -1 and s[ i ] == '1') l = i;
            else if(s[ i ] == '1') r = i;
        }

        for(int i = l; i <= r; i++) if(s[ i ] == '0') c++;


        cout << c << endl;
    }

    return 0;
}
