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
#define Case( n )for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

const ll inf = 1e9;
ll b,s,c,cnt,nb,ns,nc,pb,ps,pc;
ll p;
string ss;

ll call(ll x){

   if(x > 0) return x;
   return 0;
}
int main(){

    file();

    cin >> ss;

    if(ss.size() == 0) return 0;

    b = s = c = 0;
    for(auto ch : ss) ch == 'B' ? b++ : ch == 'S' ? s++ : c++;

    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> p;

    ll l = 0,r = 1e13;

    while(l + 1 < r){

        ll mid = (r + l) / 2;

        ll temp = call((b * mid - nb) * pb) + call((s * mid - ns) * ps) + call((c * mid - nc) * pc);

        if(temp > p) r = mid;
        else l = mid;
    }

    cout << l << endl;

    return 0;
}


