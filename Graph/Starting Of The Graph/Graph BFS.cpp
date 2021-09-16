#include<bits/stdc++.h>

using namespace std;

vector< int > v[ 1000 ];
vector< int > v1;
vector< int > parent[ 1000 ];
queue< int > q;

long long level[ 1000 ];

int BFS(int root)
{
    int x,p;

    for(int i = 0; i < 1000; i++) level[ i ] = 1e9;

    level[ root ] = 0;

    q.push( root );

    while(!q.empty())
    {
        p = q.front();

        v1.push_back( p );

        q.pop();

        for(auto x : v[ p ])
        {
            if(level[ x ] == 1e9)
            {
                q.push( x );
                level[ x ] = level[ p ] + 1;
                parent[ x ].push_back(p);
            }
        }
    }
}

int main()
{
    int node,edge,n1,n2;
    int root = 0;

    freopen("input.txt","r",stdin);

    cout << "Enter The Rang Of Node : ";
    cin >> node;
    cout << "\nEnter The Rang Of Edge : ";
    cin >> edge;

    cout << "\nEnter The Nodes :  ";

    for(int i = 1; i <= edge; i++)
    {
        cin >> n1 >> n2;

        if(i == 1) root = n1;

        v[ n1 ].push_back( n2 );
        v[ n2 ].push_back( n1 );
    }

    BFS( root );

    for(int i = 0; i < v1.size(); i++)
       cout << "\nParent : " << v1[ i ]  << " Level : " << level[ v1[ i ] ];

    return 0;
}
