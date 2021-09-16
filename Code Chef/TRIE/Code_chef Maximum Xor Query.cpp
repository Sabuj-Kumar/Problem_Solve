#include<bits/stdc++.h>
#define ll long long
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

struct node{

    vector< ll > v;
    node *next[ 2 ];

    node(){

        v.clear();
        for(int i = 0; i < 2; i++) next[ i ] = nullptr;
    }
};

node *root = new node();

void Insert(ll n,ll idx){

    node *temp = root;

    for(ll i = 20; i >= 0; i--){

        ll x = (n >> i) & 1;

        if(temp -> next[ x ] == nullptr) temp -> next[ x ] = new node();

        temp = temp -> next[ x ];
        temp -> v.push_back( idx );
    }
}

ll Search(ll x,ll l,ll r){

    ll ans = 0;
    node *temp = root;
    node *cur = nullptr;

    for(int i = 20; i >= 0; i--){

        ll n = (x >> i) & 1;

        bool flag = false;

        if(temp -> next[ n ^ 1 ] != nullptr){

            cur = temp -> next[ n ^ 1 ];
            int pos = lower_bound(cur -> v.begin(),cur -> v.end(),l) - cur -> v.begin();

            if(cur -> v[ pos ] >= l and cur -> v[ pos ] <= r){

                flag = true;
                ans = (ans << 1) + 1;
                temp = cur;
            }
        }
        if(temp -> next[ n ] != nullptr and !flag){

            temp = temp -> next[ n ];
            ans <<=  1;
        }
    }
    return ans;
}

int main(){

    file();

    ll i,q,l,r,x;
    ll n;

    scanf("%lld",&n);

    ll a[ n + 5 ];

    for(i = 1; i <= n; i++) {

        scanf("%lld",&a[ i ]);

        Insert(a[ i ],i);
    }

    scanf("%lld",&q);

    while( q-- ){

        scanf("%lld %lld %lld",&l,&r,&x);

        ll ans = Search(x,l,r);

        printf("%lld\n",ans);
    }

    return 0;
}
