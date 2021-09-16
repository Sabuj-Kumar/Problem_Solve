#include<bits/stdc++.h>

using namespace std;

int s(){ int n; scanf("%d",&n); return n; }

int main(){

    int n = s(),q = s();

    vector< int > ar( n );

    int len = sqrt( n ) + 1;

    vector< int > br( len );

    for(int i = 0; i < n; i++){

        ar[ i ] = s();

        br[ i / len ] += ar[ i ];
    }

    while( q-- ){

        int l,r;

        int sum = 0;

        for(int i = l; i <= r;){

            if(i % len == 0 && i + len - 1 <= r){

                sum += br[ i / len ];

                i += len;
            }
            else {

                sum += ar[ i ];

                ++i;
            }
        }

        printf("%d\n",sum);
    }



    return 0;
}
