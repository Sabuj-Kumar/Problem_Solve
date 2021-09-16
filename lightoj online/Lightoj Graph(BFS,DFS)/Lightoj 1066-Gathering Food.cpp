#include<bits/stdc++.h>
#define mx 12

using namespace std;

int X[ ] = {0,0,-1,1};
int Y[ ] = {-1,1,0,0};
int in;
char s[ mx ][ mx ];
char last_char;
char ch[ ] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

struct grid{

    int x,y,time;
};

bool check(int x,int y,int n){

    if(x >= 0 && x < n && y >= 0 && y < n) return true;

    else return false;
}

int bfs(grid node,int n){

    bool vis[ mx ][ mx ];

    if(last_char == ch[ in ]) return node.time;

    memset(vis,false,sizeof vis);

    queue< grid > q;

    q.push( node );

    while( !q.empty() ){

        node = q.front();

        q.pop();

        for(int i = 0; i < 4; i++){

            int x = node.x + X[ i ];
            int y = node.y + Y[ i ];
            int time = node.time;

            if(!check(x,y,n)) continue;

            if(s[ x ][ y ] == ch[ in + 1 ]){

                in++;

                return bfs({x,y,time + 1},n);
            }
            if(!vis[ x ][ y ] && ( s[ x ][ y ] == '.' || (s[ x ][ y ] >= 'A' && s[ x ][ y ] <= 'Z' && s[ x ][ y ] <= ch[ in ]))){

                q.push({x,y,time+1});

                vis[ x ][ y ] = true;
            }
        }
    }

    return -1;
}

int main(){

    //freopen("input.txt","r",stdin);

    int test;

    scanf("%d",&test);

    for(int cs = 1; cs <= test; cs++){

        int n,x,y;

        in = 0;

        scanf("%d",&n);

        last_char = 'A';

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                scanf(" %c",&s[ i ][ j ]);

                if(s[ i ][ j ] >= 'A' && s[ i ][ j ] <= 'Z'){

                    if(s[ i ][ j ] == 'A') x = i,y = j;

                    last_char = max(last_char,s[ i ][ j ]);
                }
            }

        grid node = {x,y,0};

        int ans = bfs(node,n);

        if(ans >= 0) cout << "Case " << cs << ": " << ans << endl;

        else cout << "Case " << cs << ": " << "Impossible" << endl;
    }

    return 0;
}

