#include<bits/stdc++.h>

using namespace std;

vector < int > v[ 1000 ];
int visited[ 1000 ];

void DFS(int s)
{
    if(visited[ s ]) return;

    visited[ s ] = 1;

    cout << s << " ";

    for(auto x : v[ s ]) DFS( x );
}
int main()
{
    ///freopen("input.txt","r",stdin);

    int node,edge,s;

    cin >> node >> edge;

    for(int i = 0; i < edge; i++)
    {
        int x,y;

        cin >> x >> y;

        if(i == 0) s = x;

        v[ x ].push_back( y );
        v[ y ].push_back( x );
    }

    DFS(s);

    cout << endl;

    return 0;
}
