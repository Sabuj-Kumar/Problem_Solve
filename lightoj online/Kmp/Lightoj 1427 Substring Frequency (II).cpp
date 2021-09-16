#include<bits/stdc++.h>
#define ll long long
#define ull unsinged long long
#define dob double
#define pi acos(-1)
#define pii pair<int,int>
#define pll pair< ll,ll >
#define f first
#define s second
#define lop(i,v,n,j) for(int i = v; i < n; i += j)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define in freopen("in.txt","r",stdin)
#define optimizer ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

struct data{

    int x,y,cost;

    data(){}

    data(int x_,int y_,int cost_) { x = x_,y = y_,cost = cost_; }

    bool operator < ( const data &a ){
        return cost > a.cost;
    }
};

const int mx = 1e6 + 10;

vector< int > temp_array(string p){

    vector< int > temp(p.size()+1);

    int i = 0,index = -1;

    temp[ i ] = -1;

    while(i < p.size()){

        if(index >= 0 && p[ i ] != p[ index ]) index = temp[ index ];

        i++,index++;

        temp[ i ] = index;
    }
    return temp;
}

int KMP(string s,string p){

    int count_ = 0,i = 0,index = 0;

    vector < int > temp = temp_array( p );

    while(i < s.size()){

        while(index >= 0 && s[ i ] != p[ index ]) index = temp[ index ];

        i++,index++;

        if(index == p.size()) index = temp[ index ],count_++;
    }

    return count_;
}
int main(){

    //optimizer;

    file();

    int test;

    scanf("%d",&test);

    Case( test ){

        int q;

        scanf("%d",&q);

        char s[ mx ],p[ mx ];

        scanf("%s",s);

        printf("Case %d:\n",cs);

		unordered_map<string,int> mp;

        while(q--){

            scanf("%s",p);

            if(strlen(p) > strlen(s)) {

                printf("0\n");

                continue;
            }

            if(mp[ p ] == 0) mp[ p ] = KMP(s,p);

            printf("%d\n",mp[ p ]);
        }
    }
    return 0;
}
