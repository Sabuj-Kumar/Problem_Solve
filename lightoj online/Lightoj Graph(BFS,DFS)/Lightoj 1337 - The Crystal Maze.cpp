#include<bits/stdc++.h>

using namespace std;

int M,N,count_;
int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};
bool vis[ 505 ][ 505 ];
int cost[ 505 ][ 505 ];
char s[ 505 ][ 505 ];

void DFS(int m,int n){

    if(s[ m ][ n ] == 'C') count_++;

    vis[ m ][ n ] = true;

    for(int i = 0; i < 4; i++){

        int x = m + X[ i ];
        int y = n + Y[ i ];

        if(x >= 0 && x < M && y >= 0 && y < N && !vis[ x ][ y ] && s[ x ][ y ] != '#')
            DFS(x,y);
    }
}

void DFSdp(int m,int n){

    cost[ m ][ n ] = count_;

    for(int i = 0; i < 4; i++){

        int x = m + X[ i ];
        int y = n + Y[ i ];

        if(x >= 0 && x < M && y >= 0 && y < N && cost[ x ][ y ] == -1 && s[ x ][ y ] != '#')
            DFSdp(x,y);
    }
}

int main(){

    //freopen("input.txt","r",stdin);

    int test;

    scanf("%d",&test);

    for(int t = 1; t <= test; t++){

        memset(vis,false,sizeof vis);
        memset(cost,-1,sizeof cost);

        int Q,a,b;

        scanf("%d %d %d",&M,&N,&Q);

        for(int i = 0;  i < M; i++)
            scanf("%s",s[ i ]);

        for(int i = 0; i < M; i++){

            for(int j = 0; j < N; j++){

                count_ = 0;

                if(s[ i ][ j ] != '#' && !vis[ i ][ j ]) {

                    DFS(i,j);

                    DFSdp(i,j);
                }
            }
        }

        printf("Case %d:\n",t);

        while(Q--){

            scanf("%d %d",&a,&b);

            printf("%d\n",cost[a - 1][ b - 1]);
        }
    }

    return 0;
}
