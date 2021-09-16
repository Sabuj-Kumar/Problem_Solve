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
#define op ios_base::sync_with_stdio(0);cout.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

int convert(int n){

    n *= 2;

    int sum = 0;

    while(n){

        sum += (n % 10);
        n /= 10;
    }
    return sum;
}
int main(){

    file();

    int n;

    cin >> n;
    cin.ignore();

    while(n--){

        string s,ch;

        getline(cin,s);

        for(int i = 0; i < s.size(); i++){

            if(s[ i ] == ' ') continue;

            ch += s[ i ];
        }

        int sum1 = 0,sum2 = 0;

        for(int i = 0; i < ch.size(); i += 2) sum1 += convert(ch[ i ] - '0');

        for(int i = 1; i < ch.size(); i += 2) sum2 += ch[ i ] - '0';

        sum1 += sum2;

        int mod = sum1 % 10;

        if(!mod) cout << "Valid" << endl;
        else cout << "Invalid" << endl;
    }
    return 0;
}
