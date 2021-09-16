#include<bits/stdc++.h>
#define mx 1001

using namespace std;

int a[ mx ];
bool p[ mx ];

void phi(){

    for(int i = 1; i < mx; i++) a[ i ] = i;

    for(int i = 2; i <= mx; i++)
        if(a[ i ] == i){

            a[ i ] = i-1;
            for(int j = i + i; j <= mx; j += i)
               a[ j ] = (a[ j ] / i) * (i-1);
        }
}
int main(){

    phi();

    int ts;

    scanf("%d",&ts);

    while(ts--){

        int n;

        scanf("%d",&n);

        printf("%d\n",a[ n ]);
    }
    return 0;
}
