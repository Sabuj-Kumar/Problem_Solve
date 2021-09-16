#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define in freopen("in.txt","r",stdin);
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

bool flag;

vector< string > vertical(vector< string > mat,string &word,int x,int y){

    int sz = word.size();

    for(int i = 0; i < sz; i++){

        if(mat[ x + i ][ y ] == '-' or mat[ x + i ][ y ] == word[ i ])
            mat[ x + i ][  y ] = word[ i ];

        else{

            mat[ 0 ][ 0 ] = '@';
            return mat;
        }
    }

    return mat;
}

vector< string > horizontal(vector< string > mat,string &word,int x,int y){

    int sz = word.size();

    for(int i = 0; i < sz; i++){

        if(mat[ x ][ y + i ] == '-' or mat[ x ][ y + i ] == word[ i ])
            mat[ x ][ y + i ] = word[ i ];

        else{

            mat[ 0 ][ 0 ] = '@';
            return mat;
        }
    }

    return mat;
}
void Crossword_Puzzle(vector< string > &grid,vector< string > word,int idx,int n){

    if(flag) return ;

    if(idx < word.size()){

        int sz = n - word[ idx ].size();

        string ss = word[ idx ];

        for(int i = 0; i <= sz; i++){ /// vertical

            for(int j = 0; j < n; j++){

                if(flag) return ;

                vector< string > temp = vertical(grid,ss,i,j);

                if(temp[ 0 ][ 0 ] != '@'){

                    Crossword_Puzzle(temp,word,idx+1,n);
                }
            }
        }

        for(int i = 0; i < n; i++){ /// horizontal

            for(int j = 0; j <= sz; j++){

                if(flag) return ;

                vector< string > temp = horizontal(grid,ss,i,j);

                if(temp[ 0 ][ 0 ] != '@'){

                    Crossword_Puzzle(temp,word,idx+1,n);
                }
            }
        }
    }
    else{

        flag = true;

        for(int i = 0; i < n; i++) cout << grid[ i ] << endl;

        return;
    }
}
int main(){

    file();

    vector< string > s(10),word;
    string ch,ss;

    for(int i = 0; i < 10; i++)
    cin >> s[ i ];

    cin >> ch;
    int j = 0;
    ss = "";

    for(int i = 0; i < ch.size(); i++){

        if(ch[ i ] != ';') ss += ch[ i ];
        else {

           word.pb( ss );
           ss = "";
        }
        if(i == ch.size()-1) word.pb( ss );
    }

    flag = false;

    Crossword_Puzzle(s,word,0,10);

    return 0;
}
