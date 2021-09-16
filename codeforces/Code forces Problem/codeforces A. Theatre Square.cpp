#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

    ll m,n,a;

    scanf("%lld %lld %lld",&m,&n,&a);

    ll result = ((m + a - 1) / a) * ((n + a - 1) / a);

    printf("%lld\n",result);

    return 0;
}
