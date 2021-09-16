/**
     "UNIVERSITY OF ASIA PACIFIC"

        SABUJ KUMAR TAROFDAR

        UVA 10004 BICOLORING.

        .(GRAPH).
**/

#include<bits/stdc++.h>

using namespace std;

vector < int > v[ 210 ];
queue < int > q;
int parent[ 210 ];

int BFS(int s)
{
    int x,p;

    memset(parent,-1,sizeof(parent));

    q.push( s );

    parent[ s ] = 0;

    while(!q.empty())
    {
        p = q.front();

        q.pop();

        for(auto x : v[ p ])
        {
            if(parent[ x ] == -1)
            {
                q.push( x );

                if(parent[ p ] == 0) parent[ x ] = 1;

                else parent[ x ] = 0;
            }
            else if(parent[ p ] == parent[ x ]) return 0;
        }
    }
    return 1;
}
int main()
{
    ///freopen("input.txt","r",stdin);

    int node,edge;

    while(1)
    {
        scanf("%d",&node);

        if(node == 0) break;

        scanf("%d",&edge);

        int n1,n2,s;

        for(int i = 1; i <= edge; i++)
        {
            scanf("%d %d",&n1,&n2);

            if(i == 1) s = n1;

            v[ n1 ].push_back( n2 );
        }
        if(BFS( s )) printf("BICOLORABLE.\n");

        else printf("NOT BICOLORABLE.\n");

        for(int i = 0; i < 210; i++) v[ i ].clear();
    }
    return 0;
}
