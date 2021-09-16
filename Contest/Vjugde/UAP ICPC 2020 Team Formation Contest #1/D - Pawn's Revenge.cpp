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
#define sl( n ) scnaf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define in freopen("in.txt","r",stdin )
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

const int N = 1005;
char s[ N ][ N ];
int n;

int X[ ] = {0,0,1,-1,1,-1,1,-1};
int Y[ ] = {1,-1,0,0,1,-1,-1,1};

bool check_King(int i,int j){

    for(int o = 0; o < 8; o++){

        int xx = i + X[ o ];
        int yy = j + Y[ o ];

        if(s[ xx ][ yy ] == 'K') return true;
    }
    return false;
}

bool check_Pawn(int i,int j){

    if(s[ i + 1 ][ j - 1 ] == 'P' or s[ i + 1 ][ j + 1 ] == 'P') return true;

    return false;
}

bool check(int i,int j){

    return i >= 1 and i <= n and j >= 1 and j <= n;
}
int main(){

    file();

    bool flag = true;

    cin >> n;

    //cout << n << endl;

    for(int i = 1; i <= n; i++) scanf("%s",s[ i ] + 1);

//    for(int i = 1; i <= n; i++){
//
//        for(int j = 1; j <= n; j++)
//            printf("%c",s[ i ][ j ]);
//        cout << endl;
//    }
//    cout << endl;

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= n; j++){

            if(s[ i ][ j ] == '*' and !check_King(i,j) and !check_Pawn(i,j)){

                if(check(i + 1,j + 1) and s[ i + 1 ][ j + 1 ] == '-') {

                    //cout<<"OK1"<< endl;
                    s[ i + 1 ][ j + 1 ] = 'P';
                }
                else if(check(i + 1,j - 1) and s[ i + 1 ][ j - 1 ] == '-') {

                    //cout << "Ok2" << endl;
                    s[ i + 1 ][ j - 1 ] = 'P';
                }
                else {

                    flag = false;
                    break;
                }
            }
        }

        if(!flag) break;
    }

//    for(int i = 1; i <= n; i++){
//
//        for(int j = 1; j <= n; j++) printf("%c",s[ i ][ j ]);
//        cout << endl;
//    }
//    cout << endl;

    int ans = 0;

    if(!flag) cout << -1 << endl;
    else{

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(s[ i ][ j ] == 'P') ans++;

        cout << ans << endl;
    }

    return 0;
}


