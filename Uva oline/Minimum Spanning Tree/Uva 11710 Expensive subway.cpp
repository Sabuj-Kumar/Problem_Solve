#include<bits/stdc++.h>
#define mx 1000050

using namespace std;

struct node {

    int x,y,cost;

    bool operator < (const node& a) const{

        return cost > a.cost;
    }
};

priority_queue< node > q;
int parent[ mx ];
int ran[ mx ];
int count_;

void set_(int n){

    for(int i = 0; i <= n; i++) parent[ i ] = i,ran[ i ] = 1;
}

int find_parent(int n){

    return parent[ n ] == n ? n : parent[ n ] = find_parent( parent[ n ] );
}

void set_parent(int x,int y){

    if(ran[ x ] > ran[ y ]) {

        parent[ y ] = x;

        ran[ x ] += ran[ y ];
    }
    else {

        parent[ x ] = y;

        ran[ y ] += ran[ x ];
    }
}

int mst(int n,int m){

    int cost = 0;

    count_ = n - 1;

    while(m--){

        node a = q.top();

        q.pop();

        int p1 = find_parent( a.x );
        int p2 = find_parent( a.y );

        if(p1 != p2){

            cost += a.cost;

            set_parent(p1,p2);

            count_--;
        }
        if(count_ == 0) break;
    }

    return cost;
}
int main(){

  //freopen("input.txt","r",stdin);

    int n,m;

    while(cin >> n >> m){

        if(n == 0) break;

        string s,s1;
        int cost;

        map< string,int > mp;

        for(int i = 0; i < n; i++){

            cin >> s;

            mp[ s ] = i+1;
        }

        for(int i = 0; i < m; i++){

            cin >> s >> s1 >> cost;

            q.push({ mp[ s ],mp[ s1 ],cost });
        }

        cin >> s;

        set_( n );

        int result = mst( n,m );

        if(count_== 0) cout << result << endl;

        else cout << "Impossible" << endl;

        while(!q.empty()) q.pop();
    }

    return 0;
}
