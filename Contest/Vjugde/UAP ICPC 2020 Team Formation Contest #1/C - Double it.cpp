#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;

    cin >> n;

    string s = "";

    while(n > 0){

        if(n & 1){

            n -= 1;
            s += 'A';
        }
        else {

            n -= 2;
            s += 'B';
        }
        n /= 2;
    }

    reverse(s.begin(),s.end());

    cout << s << endl;

    return 0;
}


