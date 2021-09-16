#include<bits/stdc++.h>
const double pi = 3.141592653;

using namespace std;

bool pm[ 100005 ];

void sieve(){

    int sqr = sqrt(100005);

    for(int i = 4; i < 100005; i += 2) pm[ i ] = true;

    for(int i = 3; i <= sqr; i += 2)
        if(pm[ i ] == false)
            for(int j = i * i; j < 100005; j += i)
                pm[ j ] = true;

}

int GCD(int a,int b){

    if(b == 0) return a;
    return GCD(b,a%b);
}
int main(){

   //freopen("in.txt","r",stdin);
    //sieve();



    return 0;
}
