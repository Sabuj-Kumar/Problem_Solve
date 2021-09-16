#include<bits/stdc++.h>
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
#define sc scanf("%d",&n)
#define sl scanf("%lld",&n)
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

int main(){

    file();

    int n,cnt = 0,up_down = 0;

    cin >> n;

    string s;

    cin >> s;

    for(int i = 0; i < s.size(); i++){

        if(s[ i ] == 'D') up_down--;
        else up_down++;

        if(up_down == 0 and s[ i ] == 'U') cnt++;
    }

    cout << cnt << endl;

    return 0;
}

