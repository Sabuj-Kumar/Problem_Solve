#include<bits/stdc++.h>
#define mx 10000

using namespace std;

vector< int > g[ 100 ];

int dist[ mx ];

void bfs(int src)
{
    for(int i = 0;i < mx; i++) dist[ i ] = 1e9;

    queue< int > q;

    q.push( src );

    dist[ src ] = 0;

    while(!q.empty())
    {
        int parent = q.front();

        cout << parent << endl;

        q.pop();

        for(auto x : g[ parent ])
        {
            if(dist[ x ] == 1e9)
            {
                dist[ x ] = dist[ parent ] + 1;
                q.push( x );
            }
        }
    }
}
int visited[ mx ];

void dfs(int src)
{
    if(visited[ src ]) return;

    visited[ src ] = 1;

    cout << src << endl;

    for(auto x : g[ src ])
    {
        dfs( x );
    }
}
int main()
{
    freopen("input.txt","r",stdin);

    int n,m;

    cin >> n >> m;

    for(int i = 0;i < m; i++)
    {
        int a,b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    bfs(1);
    for(int i =1;i<=7;i++)cout<<dist[i]<<" ";
}
