#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int >


using namespace std;


int gcd(int a,int b){

    if( !b ) return a;
    return gcd(b,a%b);
}
int I() { int n; scanf("%d",&n); return n; }


int main(){

    int t = I();

    while( t-- ){

        int a = I(),b = I();

        if( !(a % b) ) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
