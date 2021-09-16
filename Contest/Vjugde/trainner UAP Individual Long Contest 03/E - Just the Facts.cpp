#include<bits/stdc++.h>

using namespace std;

map<int,int > mp;

void digit(){

    long long  p = 1;

    for(int i = 1; i <= 10000; i++){

        int m = 0;

        p *= i;

        if(p < 9) { mp[ i ] = p; continue; }

        else {

            while( !(p % 10)) p /= 10;

            p %= 100000;
        }

        mp[ i ] = p % 10;
    }
}
int main(){

    digit();

    //freopen("input.txt","r",stdin);

    int in;

    while(cin >> in){

        int m = in;
        int x = 0;
        int p = 5;

        while(m > 0) {

            m /= 10;

            x++;
        }

        while(p - x) {

            cout << " ";

            p--;
        }
        cout << in << " -> " << mp[ in ] << endl;
    }
    return 0;
}
