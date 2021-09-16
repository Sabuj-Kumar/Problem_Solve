#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair<ll,ll >
#define ft first
#define sd second
#define pb push_back
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

const int N = 1e5 + 10;
int digit[ 5 ],vis[ N ];
bool prime[ N ];

void seive(){

    int srt = sqrt( N );

    prime[ 1 ] = true;
    prime[ 0 ] = true;

    for(int i = 4; i < N; i += 2) prime[ i ] = true;

    for(int i = 3; i <= srt; i += 2)
        if(!prime[ i ])
            for(int j = i * i; j < N; j += i)
                prime[ j ] = true;
}

void num_to_array(int num){

    int i = 3;

    while(i >= 0){

        digit[ i ] = (num % 10);
        num /= 10;
        i--;
    }
}

int array_to_num(int a[]){

    int i = 0,temp = 0;

    while(i < 4){

        temp = temp * 10 + digit[ i ];

        i++;
    }

    return temp;
}
int BFS(int start,int des){

    memset(vis,-1,sizeof vis);

    queue< int > q;

    q.push( start );

    vis[ start ] = 0;

    while(!q.empty()){

        int num = q.front();

        if(num == des) return vis[ des ];

        q.pop();

        for(int i = 3; i >= 0; i--){

            num_to_array(num);

            for(int j = 0; j <= 9; j++){

                digit[ i ] = j;

                int temp = array_to_num(digit);

                if(!prime[ temp ] and vis[ temp ] == -1 and temp > 1000){

                    vis[ temp ] = vis[ num ] + 1;
                    q.push(temp);
                }
            }
        }
    }

    return -1;
}
int main(){

    seive();

    file();

    int n,a,b;

    cin >> n;

    while(n--){

        cin >> a >> b;

        int ans = BFS(a,b);

        if(ans != -1) cout << ans << endl;
        else cout << "Impossible" << endl;
    }

    return 0;
}
