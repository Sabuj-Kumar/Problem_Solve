#include<bits/stdc++.h>
#define mx 2000010

using namespace std;

int prime[ mx ];
int notprime[ mx ];

void seive(){

    memset(notprime,-1,sizeof notprime);

    for(int i = 2; i <= mx; i++)
        if(!prime[ i ])
            for(int j = i + i; j < mx; j += i){

                prime[ j ]++;

                int x = j,c = 1;

                while( x % i == 0 ){

                    x /= i;

                    c++;
                }
                notprime[ j ] *= c;
            }
}
int main(){

    //freopen("input.txt","r",stdin);

    seive();

    int test;

    scanf("%d",&test);

    while( test-- ){

        int input;

        scanf("%d",&input);

        //cout <<prime[ input ] << endl;

        printf("%d\n",(notprime[ input ]+prime[ input ]) * -1 );
    }
    return 0;
}
