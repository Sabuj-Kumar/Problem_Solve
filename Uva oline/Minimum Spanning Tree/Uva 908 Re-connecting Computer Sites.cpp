#include<bits/stdc++.h>
#define mx 1000010

using namespace std;

struct node{

    int x;
    int y;
    int cost;

    bool operator < (const node& a) const{

        return cost > a.cost;
    }
};

int n;
priority_queue< node > q,q1;
pair< node,int > pr;
int p[ mx ];

void set_(){

    for(int i = 1; i <= n; i++) p[ i ] = i;
}

int find_parent(int m){

    return p[ m ] == m ? m : p[ m ] = find_parent( p[ m ] );
}

void set_parent(int x,int y){

    if(x < y) p[ y ] = x;

    else p[ x ] = y;
}

long long mst(priority_queue< node > p,int e){

    int c = 0;

    for(int i = 0; i < e; i++){

        node a = p.top();

        p.pop();

        int p1 = find_parent(a.x);
        int p2 = find_parent(a.y);

        //cout <<"parent " << p1 << " " << p2 << endl;

        if(p1 != p2){

            //cout << a.x << " " << a.y << " " << a.cost << endl;

            c += a.cost;

            set_parent(a.x,a.y);
        }
    }

    return c;
}

int main(){

    freopen("input.txt","r",stdin);

    long long k,m;

    int f = 0;

    while(cin >> n){

        if(f) cout << "\n";

        f = 1;

        map< node,int > mp;

        int x,y,z,result = 0,e = 0;

        for(int i = 1; i < n; i++){

            cin >> x >> y >> z;

            result += z;
        }

        cin >> k;

        e += k;

        while(k--){

            cin >> x >> y >> z;

            q.push({x,y,z});
        }

        cin >> m;

        e += m;

        while(m--){

            cin >> x >> y >> z;

            q.push({x,y,z});
        }

        set_();

        int result1 = mst( q , e );

        cout << result << "\n" << result1 << endl;
    }

    return 0;
}
