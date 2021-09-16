#include<bits/stdc++.h>
#define pb push_back
#define p push

using namespace std;

vector < int > v[100];
vector < int > v1;
queue < int > q;
map < int,int > in;
map < int,int > out;
map < int,int > visit;

int main()
{
    freopen("input.txt","r",stdin);

    int node,edge,i,j,root_node = 0,nd;

    cin >> node >> edge;

    for(i = 1; i <= edge; i++)
    {
        int n1,n2;

        cin >> n1 >> n2;

        v[ n1 ].push_back( n2 );

        if(i == 1) root_node = n1;
    }

    for(i = 1; i <= node; i++)
    {
        cout << i << ": ";

        for(j = 0; j < v[ i ].size(); j++)
            cout << v[ i ][ j ] << " ";

        cout << endl;
    }

    q.push(root_node);

    cout << "parent :  ";

    while(!q.empty())
    {
        int x = q.front();

        cout << x << " ";

        q.pop();

        v1.push_back( x );

        for(auto i : v[ x ])
        {
            if(visit[ i ] == 0) q.push(i);

            out[ x ]++;
            in[ i ]++;
            visit[ i ] = 1;
        }
        visit[ x ] = 1;
    }

    cout << endl;

    for(int i = 0; i < v1.size(); i++)
       cout << v1[ i ] <<" : In Degree : " << in[ v1[ i ] ] << "  Out Degree : " << out[ v1[ i ] ] << endl;

    return 0;
}
