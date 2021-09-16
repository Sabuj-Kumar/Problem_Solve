#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

int main(){

    file();

    int T;
    scanf("%d",&T);

    for(int t = 1; t <= T; t++){

        int n;

        scanf("%d",&n);

        int trace = 0,row = 0,collume = 0;
        int a[ n + 10 ][ n + 10 ],m1[ n + 10 ],m2[ n + 10 ];
        bool f1 = 1,f2 = 1;

        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){

            scanf("%d",&a[ i ][ j ]);
            if(i == j) trace += a[ i ][ j ];
        }

        for(int i = 1; i <= n; i++){

            for(int k = 1; k <= n; k++){

                m1[ k ] = 0;
                m2[ k ] = 0;
            }

            f1 = 1,f2 = 1;

            for(int j = 1; j <= n; j++){

                int x = a[ i ][ j ];
                int y = a[ j ][ i ];

                if(m1[ x ] == 0 && f1) m1[ x ] = 1;
                else if( f1 ) { row++,f1 = 0; }

                if(m2[ y ] == 0 && f2) m2[ y ] = 1;
                else if( f2 ) { collume++,f2 = 0; }

                if(i < j && !f1 && !f2) break;
            }
        }
        printf("Case #%d: %d %d %d\n",t,trace,row,collume);
    }
    return 0;
}
