#include<bits/stdc++.h>
using namespace std;

int I() { int n; scanf("%d",&n); return n; }

int main(){

    int n = I();

    while( n-- ){

        int a = I(),b =  I();

        if(!(a % b)) cout << 0 << endl;
        else if( a < b ) cout <<  b - a << endl;
        else cout << b - (a % b)  << endl;
    }

    return 0;
}
