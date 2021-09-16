#include<bits/stdc++.h>
#define ll long long

using namespace std;

int sc() { int n; scanf("%d",&n); return n; }
void pf(int ans) { printf("%d\n",ans); }

int main(){

    int test = sc();

    while(test--){

        int x = -1,n = sc();
        vector< int >  a;
        for(int i = 0; i < n; i++) {

            x = sc();
            a.push_back( x );
        }

        sort(a.begin(),a.end(),greater<int>());

        for(int i = 0; i < a.size(); i++){

            if(a[ i ] < i + 1){

                x = i;
                break;
            }
        }
        if(x == -1) pf( n );
        else pf( x );
    }
    return 0;
}
