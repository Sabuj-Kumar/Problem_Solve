#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll a[ 3000 ][ 3000 ];
ll b[ 3000 ][ 3000 ];

ll way_of_grid(int i,int j){

    if(b[ i ][ j ] || i < 1 || j < 1) return 0;

    if(i == 1 && j == 1) return 1;

    if(a[ i ][ j ] != -1) return a[ i ][ j ];

    return a[ i ][ j ] = way_of_grid(i-1,j) + way_of_grid(i,j-1);
}
int main(){

    //freopen("input.txt","r",stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;

    cin >> test;

    while(test--){

        int m,n;

        cin >> m >> n;
        cin.ignore();

        int o = m;

        memset(a,-1,sizeof a);
        memset(b,0,sizeof b);

        while(o--){

            int p,f = -1;
            string s;

            getline(cin,s);

            stringstream cn(s);

            while(cn >> p){

                if(f == -1) { f = p; continue; }

                b[ f ][ p ] = 1;
            }
        }

        ll  way = way_of_grid(m,n);

        if(test - 1 >= 0)cout << way << "\n\n";

        else cout << way << "\n";
    }

    return 0;
}

