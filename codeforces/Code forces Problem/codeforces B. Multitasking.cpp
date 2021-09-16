#include<bits/stdc++.h>
#define pb push_back

using namespace std;

vector< int > v[ 1010 ];
vector< pair< int,int > > pa;
map<pair<int,int>,int > mp;

int assen(int n,int m){

    for(int i = 0; i < m; i++){

        for(int j = i + 1; j < m; j++){

            for(int k = 0; k < n; k++){

                if(v[ k ][ i ] > v[ k ][ j ]){

                    swap(v[ k ][ i ],v[ k ][ j ]);

                    if( mp[{i,j}] == 0 ) mp[{i,j}] = 1,pa.pb({i,j});
                }
            }
        }
    }
}

int decen(int n,int m){

    for(int i = 0; i < m; i++){

        for(int j = i + 1; j < m; j++){

            for(int k = 0; k < n; k++){

                if(v[ k ][ i ] < v[ k ][ j ]){

                    swap(v[ k ][ i ],v[ k ][ j ]);

                    if( mp[{i,j}] == 0 ) mp[{i,j}] = 1,pa.pb({i,j});
                }
            }
        }
    }
}
int main(){

    int n,m,k,in;

    scanf("%d %d %d",&n,&m,&k);

    for(int i = 0; i < n; i++){

        for(int j = 0; j < m; j++){

            scanf("%d",&in);

            v[ i ].pb( in );
        }
    }

    mp.clear();
    pa.clear();

    if( k ) decen(n,m);

    else assen(n,m);

//    for(int i = 0; i < n; i++) {
//
//        for(int j = 0; j < m; j++)
//            cout << v[ i ][ j ] << " ";
//
//        cout << endl;
//    }

    cout << pa.size() << endl;

    for(int i = 0; i < pa.size(); i++) cout << pa[ i ].first+1 << " " << pa[ i ].second+1 << endl;

    return 0;
}
