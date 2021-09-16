/**
    **UNIVERSITY OF ASIA PACIFIC**

     SABUJ KUMAR TAROFDAR

     GRAPH ADJECENCY LIST PRACTICE.......
**/

#include<bits/stdc++.h>

using namespace std;

vector < int > v[ 100 ];
map< int,pair< int,int > > mp;
map< int,pair< int,int > >:: iterator it;

int main()
{
    freopen("input.txt","r",stdin);

    int node,edge;

    cin >> node >> edge;

    int n1,n2,i,j;
    int root_node;
    bool flag = true;

    for(i = 1; i <= edge; i++)
    {
        cin >> n1 >> n2;

        if(flag == true)
        {
            root_node = n1;
            flag = false;
        }
        mp[ i ] = make_pair(n1,n2);

        v[ n1 ].push_back( n2 );
        v[ n2 ].push_back( n1 );
    }

    for(it = mp.begin(); it != mp.end(); it++)
        cout <<  it->second.first << " " << it->second.second << endl;


    return 0;
}
