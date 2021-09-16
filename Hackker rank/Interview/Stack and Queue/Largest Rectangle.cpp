#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

int Histogram_Area(vector< int > &v){

    stack< int > st;
    int i,area = -1,ar = 0,sz = v.size();

    for(i = 0; i < sz;){

        if(st.empty() or v[ i ] >= v[ st.top() ]) st.push( i++ );
        else {

            int top = st.top();

            st.pop();

            if(st.empty()) ar = v[ top ] * i;
            else ar = v[ top ] * (i - st.top() - 1);

            area = max(area,ar);
        }
    }

    while(!st.empty()){

        int top = st.top();

        st.pop();

        if(st.empty()) ar = v[ top ] * i;
        else ar = v[ top ] * (i - st.top() - 1);

        area = max(area,ar);
    }
    return area;
}
int main(){

    //file();

    int n;

    cin >> n;

    vector< int > v( n );

    for(int i = 0; i < n; i++) cin >> v[ i ];

    cout << Histogram_Area( v ) << endl;

    return 0;
}
