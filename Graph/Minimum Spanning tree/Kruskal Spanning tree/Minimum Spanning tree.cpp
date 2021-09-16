#include<bits/stdc++.h>

using namespace std;

int parent[ 10010 ];
pair < long long , pair< int, int > > p[ 100010 ];
int node,edge;

void set_(){

    for(int i = 1; i <= node; i++) parent[ i ] = i;
}

int parent_find(int n){

    return parent[ n ] == n ? n : parent[ n ] = parent_find( parent[ n ] );
}

void union_(int x,int y){

    x = parent_find( x );
    y = parent_find( y );

    parent[ y ] = x;
}

int spanning_tree(){

    int cost = 0;

    for(int i = 0; i < edge; i++){

        int x = p[ i ].second.first;
        int y = p[ i ].second.second;
        int weight = p[ i ].first;

        //cout << x << " " << y << " " << weight << endl;

        if(parent_find( x ) != parent_find( y )){

            cost += weight;

            union_(x , y);
        }
    }

    return cost;
}
int main(){

    //freopen("input.txt","r",stdin);

    int x,y;
    long long weight;

    scanf("%d %d",&node,&edge);

    set_();

    for(int i = 0; i < edge; i++){

        scanf("%d %d %lld",&x,&y,&weight);

        p[ i ] = {weight,{x,y}};
    }

    sort(p,p+edge);

//    for(int i = 0; i < edge; i++){
//
//        cout << p[ i ].first << " " << p[ i ].second.first << " " << p[ i ].second.second << endl;
//    }
    cout << spanning_tree() << endl;

    return 0;
}
