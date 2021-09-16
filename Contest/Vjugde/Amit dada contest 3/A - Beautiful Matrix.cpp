#include<bits/stdc++.h>

using namespace std;

int main(){

    int a[ 6 ][ 6 ];

    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            scanf("%d",&a[ i ][ j ]);

    int f = 0,m = 0,n = 0;

    for(int i = 0; i < 5; i++){

        for(int j = 0; j < 5; j++){

            if(a[ i ][ j ] == 1){

                m = i;
                n = j;
                f = 1;
                break;
            }
        }
        if(f) break;
    }

    int p = abs(2 - m) + abs( 2 - n);

    printf("%d\n",p);

    return 0;
}
