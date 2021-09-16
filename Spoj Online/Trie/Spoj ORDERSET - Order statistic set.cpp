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
#define lop(i,v,b) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

struct node;
extern node *EMPTY;

struct node{

    int sum;
    node *lf,*rt;

    node() : node(0,this,this) {}
    node(int val,node *lf = EMPTY,node *rt = EMPTY) : sum( val ),lf( lf ),rt( rt ) {}
};

node *EMPTY = new node();
node *root = EMPTY;

void Insert(node *&temp,int val,int num,int l = -1e9,int r = 1e9){

    if(val < l or val > r) return;

    if(temp == EMPTY) temp = new node(0);

    if(l == r) { temp -> sum = num; return; }

    int mid = l + (r - l) / 2;

    Insert(temp -> lf,val,num,l,mid);
    Insert(temp -> rt,val,num,mid + 1,r);
    temp -> sum = temp -> lf -> sum + temp -> rt -> sum;
}

int count_(node *temp,int val,int l = -1e9,int r = 1e9){

    if(val < l) return 0;
    if(val >= r) return temp -> sum;

    int mid = l + (r - l) / 2;

    return count_(temp -> lf,val,l,mid) + count_(temp -> rt,val,mid + 1,r);
}

int K_th(node *temp,int k,int l = -1e9,int r = 1e9){

    if(l == r) return l;

    int mid = l + (r - l) / 2;

    if(temp -> lf -> sum > k) return K_th(temp -> lf,k,l,mid);
    return  K_th(temp -> rt,k - temp -> lf -> sum,mid + 1,r);
}

int I() { int n; scanf("%d",&n); return n; }

int main(){

    file();

    int n = I();

    while( n-- ){

        string s;
        int val;

        cin >> s >> val;

        if(s == "I") Insert(root,val,1);
        else if(s == "D") Insert(root,val,0);
        else if(s == "C") printf("%d\n",count_(root,val-1));
        else {

            if(root -> sum < val) puts("invalid");
            else printf("%d\n",K_th(root,val-1));
        }
    }
    return 0;
}

