#include<bits/stdc++.h>

using namespace std;

const int N = 100000 + 5;
vector<int> g[N];
int par[N], lev[N];
int sp[N][20];      // sparse table. i's 2^j th parent in sp[i][j]
int n;

void dfs(int u, int pr, int lv) {
    par[u] = pr;
    lev[u] = lv;
    for(int i=0; i<(int) g[u].size(); ++i) {
        int v = g[u][i];
        if(v != pr) dfs(v, u, lv+1);
    }
}

void lca_init() {
    dfs(1, -1, 0);
    memset(sp, -1, sizeof sp);
    for(int i=1; i<=n; ++i) sp[i][0] = par[i];

    for(int j=1; (1<<j) < n; ++j) {
        for(int i=1; i<=n; ++i) {
            if(sp[i][j-1] != -1) sp[i][j] = sp[sp[i][j-1]][j-1];
        }
    }
}

int lca(int u, int v) {
    if(lev[u] < lev[v]) swap(u, v);

    int logn = 0;
    while((1 << (1+logn)) <= n) ++logn;
    for(int i=logn; i>=0; --i) {
        if(lev[u] - (1<<i) >= lev[v]) u = sp[u][i];
    }
    if(u == v) return u;

    for(int i=logn; i>=0; --i) {
        if(sp[u][i] != -1 and sp[u][i] != sp[v][i]) {
            u = sp[u][i];
            v = sp[v][i];
        }
    }
    return par[u];
}

int main(){

    return 0;
}
