#include<bits/stdc++.h>
#define mx 2000010

using namespace std;

int prime[ mx ];
int notprime[ mx ];

void seive(){

    int n = sqrt( mx + 1 );

    prime[ 1 ] = 1;

    for(int i = 4; i < mx; i += 2) prime[ i ] = 1;

    for(int i = 3; i <= n; i += 2)
        if(!prime[ i ])
            for(int j = i + i; j < mx; j += i) prime[ j ] = 1;

    for(int i = 1; i < mx; i++)
        if(prime[ i ])
            for(int j = i; j < mx; j += i) notprime[ j ]++;
}
int main(){

    //freopen("input.txt","r",stdin);

    seive();

    int test;

    scanf("%d",&test);

    while(test--){

        int n;

        scanf("%d",&n);

        printf("%d\n",notprime[ n ]);
    }
}
