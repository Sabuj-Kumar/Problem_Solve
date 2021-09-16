#include<bits/stdc++.h>

using namespace std;

int main(){

    string s;

    getline(cin,s);

    if(s[ 0 ] != ' '){

        if(s[ 0 ] >=  'a' && s[ 0 ] <= 'z') s[ 0 ] -= 32;
    }

    for(int i = 0; i < s.size(); i++){

        if(s[ i ] == ' ' && i < s.size()-1){

            if(s[ i + 1 ] >=  'a' && s[ i + 1 ] <= 'z') s[ i + 1 ] -= 32;
        }
    }

    cout << s << endl;

    return 0;
}
