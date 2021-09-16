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
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

int n,mx,up,down,lt,rt;
vector< vector< int > > v;

struct node{

    int mxx = -1;
    int u = -1;
    int d = -1;
};

node Kadane_Algo(const vector< int > &temp){

    int sz = temp.size();

    int sum = 0;
    int mxx = -1,start = -1,u = -1,d = -1;

    for(int i = 0; i < sz; i++){

        sum += temp[ i ];

        if(sum < 0){

            sum = 0;

            start = i + 1;
        }

        if(sum > mx){

            u = start;
            d = i;
            mxx = sum;
        }
    }

    node ans;

    ans.mxx = mxx;
    ans.u = u;
    ans.d = d;

    return ans;
}
int Maximum_Sum(){

    lt = 0;
    rt = 0;
    mx = -1;

    vector< int > temp(n);

    for(int col = 0; col < n; col++){

        for(int i = 0; i < n; i++) temp[ i ] = 0;

        for(int col2 = col; col2 < n; col2++){

            for(int i = 0; i < n; i++) temp[ i ] += v[ i ][ col2 ];

            node kadane = Kadane_Algo( temp );

            if(mx < kadane.mxx){

                mx = kadane.mxx;
                up = kadane.u;
                down = kadane.d;
                lt = col;
                rt = col2;
            }
        }
    }
    return mx;
}
int main(){

    file();

    cin >> n;

    vector< vector< int > > a(n,vector< int > (n,0));

    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
    cin >> a[ i ][ j ];

//    for(int i = 0; i < n; i++){
//
//        for(int j = 0; j < n; j++) cout << a[ i ][ j ] << " ";
//
//        cout << endl;
//    }
//
//    cout << endl;

    v = a;

    int ans = Maximum_Sum();

    //cout << "left " << lt << " right " << rt << " up " << up << " down " << down << endl;

    cout << ans << endl;

    return 0;
}

