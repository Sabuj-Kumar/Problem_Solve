/**
    **UNIVERSITY OF ASIA PACIFIC**

        *SABUJ KUMAR TAROFDAR*

        Adjacency Matrix Graph
**/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int node,edge;

    freopen("input.txt","r",stdin);

    cout << "enter the node number :\n";
    cin >> node;
    cout << "enter the edge number :\n";
    cin >> edge;

    cout << "enter the nodes and cost :\n";

    int n1,n2,cost;
    int a[ node+1 ][ node+1 ];

    for(int i = 1; i <= node; i++)
        for(int j = 1; j <= node; j++)
           a[ i ][ j ] = 0;

    for(int i = 0; i < edge; i++)
    {
        cin >> n1 >> n2 >> cost;

        a[ n1 ][ n2 ] = cost;
        a[ n2 ][ n1 ] = cost;
    }

    for(int i = 1; i <= node; i++)
    {
        for(int j = 1; j <=  node; j++)
        {
            if(a[ i ][ j ] != 0)
                cout << "node1 = " << i << " node2 =  " << j << " cost = " << a[ i ][ j ] << endl;
        }
    }
    return 0;
}
