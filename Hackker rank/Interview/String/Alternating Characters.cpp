#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ul unsigned long long
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
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

int main(){

    file();

    int n;
    string s;

    cin >> n;

    while(n--){

        cin >> s;

        int cnt = 0;

        for(int i = 0; i < s.size(); i++) {

           int j = i;

            while(s[ i ] == s[ j + 1 ] and j + 1 < s.size()){

                j++;
                cnt++;
            }

            i = j;
        }

        cout << cnt << endl;

    }

    return 0;
}
