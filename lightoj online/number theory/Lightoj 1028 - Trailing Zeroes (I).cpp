#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pf push_front
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

const ll N = 1000006;

bool p[ N ];
vector< ll > v;

void sieve(){

    for(int i = 4; i <= N; i += 2) p[ i ] = true;

    for(int i = 3; i * i <= N; i += 2)
        if(!p[ i ])
            for(int j = i * i; j <= N; j += 2*i)
               p[ j ] = true;

    for(ll i = 2; i <= N; i++) if(!p[ i ]) v.pb( i );
}

ll NOD(ll num){

    ll cnt = 1;

    for(int i = 0; i < v.size() and v[ i ] * v[  i ] <= num; i++){

        int k = 1;

        while(!(num % v[ i ])) num /= v[ i ],k++;

        cnt *= k ;
    }

    if(num > 1) cnt *= 2;

    return cnt;

}
int main(){

    sieve();

    file();

    int n;

    scanf("%d",&n);

    Case( n ){

        ll num;
        scanf("%lld",&num);

        cout << "Case " << cs << ": " << NOD( num ) - 1<< endl;
    }
    return 0;
}
