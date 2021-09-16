#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair< ll,ll >
#define pb push_back
#define pf push_front
#define f first
#define s second
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

vector< int > v,ans,dp,path;
int sz;

int LIS(){

    dp[ 0 ] = INT_MIN;
    path[ 0 ] = sz;

    for(int i = 1; i < sz; i++) ans[ i ] = 0,dp[ i ] = INT_MAX,path[ i ] = sz;

    int lis = 0;

    for(int i = 0; i < sz; i++){

        int low = 0,high = lis;

        while(low <= high){

            int mid = (low + high) / 2;

            if(dp[ mid ] < v[ i ]) low = mid + 1;
            else high = mid - 1;
        }

        dp[ low ] = v[ i ];
        path[ i ] = low;
        lis = max(low,lis);
    }
    return lis;
}

void lis_path(){

    int i,j;

    for(j = 1,i = 0; j < sz; j++) if(path[ j ] > path[ i ]) i = j;

    int top = path[ i ] - 1;

    ans[ top ] = v[ i ];

    for(j = i - 1; j >= 0; j--){

        if(v[ j ] < v[ i ] and path[ j ] == path[ i ] - 1){

            i = j;
            top--;
            ans[ top ] = v[ i ];
        }
    }
}
int main(){

    file();

    int n;

    while( cin >> n ) v.pb( n );

    sz = v.size();

    dp.assign(sz,0);
    path.assign(sz,0);
    ans.assign(sz,0);

    int lis = LIS();

    printf("%d\n-\n",lis);

    lis_path();

    for(int i = 0; i < lis; i++) printf("%d\n",ans[ i ]);

    return 0;
}
