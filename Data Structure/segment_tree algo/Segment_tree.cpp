#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000+7;
int tree[4*MAX];

int a[MAX];     // initial array

void build(int node, int l, int r) {
    if(l == r) {
        // leaf node
        tree[node] = a[l];
        return ;
    }

    int lc = (node*2);      // left child's index
    int rc = (node*2 + 1);  // right child's index
    int mid = (l + r) / 2;

    build(lc, l, mid);
    build(rc, mid+1, r);

    tree[node] = tree[lc] + tree[rc];
}

void update(int node, int l, int r, int pos, int val) {
    if(pos < l or pos > r) return ;
    if(l == r) {
        tree[node] = val;
        return ;
    }

    int lc = (node*2);      // left child's index
    int rc = (node*2 + 1);  // right child's index
    int mid = (l + r) / 2;

    update(lc, l, mid, pos, val);
    update(rc, mid+1, r, pos, val);

    tree[node] = tree[lc] + tree[rc];
}

int query(int node, int l, int r, int x, int y) {
    if(y < l or x > r) return 0;
    if(l >= x and r <= y) return tree[node];

    int lc = (node*2);      // left child's index
    int rc = (node*2 + 1);  // right child's index
    int mid = (l + r) / 2;

    int q1 = query(lc, l, mid, x, y);
    int q2 = query(rc, mid+1, r, x, y);
    return q1 + q2;
}

int main(){


    return 0;
}
