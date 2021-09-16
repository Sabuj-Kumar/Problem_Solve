#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll a[ 110 ][ 110 ];
ll b[ 110 ][ 110 ];

ll way_of_grid(int i,int j){

    if(b[ i ][ j ] || i < 0 || j < 0 ) return 0;

    if(i == 0 && j == 0 ) return 1;

    if(a[ i ][ j ] != -1) return a[ i ][ j ];

    return a[ i ][ j ] = way_of_grid(i-1,j) + way_of_grid(i,j-1);
}
int main(){

    //freopen("input.txt","r",stdin);

    int m,n;

    while(cin >> m >> n && m && n){

        memset(b,0,sizeof b);
        memset(a,-1,sizeof a);
        int x;

        cin >> x;

        while(x--){

            int s,d;

            cin >> s >> d;

            b[ s ][ d ] = 1;
        }

        ll way = way_of_grid(m,n);

        if(way == 0) printf("There is no path.");

        else if(way == 1) printf("There is one path from Little Red Riding Hood's house to her grandmother's house.");

        else printf("There are %lld paths from Little Red Riding Hood's house to her grandmother's house.",way);

        cout << endl;
    }

    return 0;
}
