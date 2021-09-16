#include<bits/stdc++.h>

using namespace std;

int I() { int n; scanf("%d",&n); return n; }

int main(){

    int t = I();

    while( t-- ){

        int n = I();

        string s,s1,s2;

        cin >> s;
        bool f = 1;

        for(int i = 0; i < n; i++){

            if(i == 0){

                s1 += '1';
                s2 += '1';
            }
            else {

                if(s[ i ] == '0') s1 += '0',s2 += '0';
                else if(s[ i ] == '1' and f) f = 0,s1 += '1',s2 += '0';
                else if(s[ i ] == '1' and !f) s1 += '0',s2 += '1';
                else if(s[ i ] == '2' and f) s1 += '1',s2 += '1';
                else if(s[ i ] == '2' and !f) s1 += '0',s2 += '2';
            }
        }
        cout << s1 << endl << s2 << endl;
    }
    return 0;
}
