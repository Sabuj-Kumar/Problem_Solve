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

int main(){

    file();

    cin >> ss;

    for(auto ch : ss) ch == 'B' ? b++ : ch == 'S' ? s++ : c++;

    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> p;

    ll mn,q1 = inf,q2 = inf,q3 = inf;

    if(b != 0) q1 = nb / b;
    if(s != 0) q2 = ns / s;
    if(c != 0) q3 = nc / c;

    mn = min(q1,min(q2,q3));

    cnt += mn;

    nb -= mn * b;
    ns -= mn * s;
    nc -= mn * c;

    bool flag = 1;

    while((nb and b) or (ns and s ) or (nc and c)){

        ll x;

        if(nb < b){

            x = (b - nb) * pb;

            if(x > p){

                flag = 0;
                cout << cnt << endl;
                break;
            }

            p -= x;
            nb = b;
        }
        if(ns < s){

            x = (s - ns) * ps;

            if(x > p){

                flag = 0;
                cout << cnt << endl;
                break;
            }

            p -= x;
            ns = s;
        }
        if(nc < c){

            x = (c - nc) * pc;

            if(x > p){

                flag = 0;
                cout << cnt << endl;
                break;
            }

            p -= x;
            nc = c;
        }

        nb -= b;
        ns -= s;
        nc -= c;
        cnt++;
    }

    if(flag){

        ll al = (b * pb + s * ps + c * pc);

        cnt += (p / al);

        cout << cnt << endl;
    }

    return 0;
}

