#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define x first
#define y second

struct data {
    int x, y, val;
    data() { }
    data(int _x, int _y, int _v) { x=_x, y=_y, val=_v; }
    bool operator < (const data &p) const { return val > p.val; }
};

const int inf = 0x3f3f3f3f;
const int N = 107;
int a[N][N], d[N][N];
int r, c;

inline bool inside(int x, int y) {
    return x >= 0 and x < r and y >= 0 and y < c and a[x][y] != -1;
}

int fx[] = { 1, 0, -1, 0 };
int fy[] = { 0, 1, 0, -1 };

int dijkstra(pii src, pii des) {
    memset(d, inf, sizeof d);

    priority_queue< data > pq;
    pq.push(data(src.x, src.y, a[src.x][src.y]));
    d[src.x][src.y] = a[src.x][src.y];

    while(!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        if(top.val > d[top.x][top.y]) continue;

        for(int i=0; i<4; ++i) {
            int x = top.x + fx[i];
            int y = top.y + fy[i];
            if(inside(x, y) and d[x][y] > a[x][y] + d[top.x][top.y]) {
                d[x][y] = a[x][y] + d[top.x][top.y];
                pq.push(data(x, y, d[x][y]));
            }
        }
    }

    return d[des.x][des.y];
}

/*

int func(src, des) {
    make all dist inf

    take a priority queue
    insert source with starting value (0)

    while queue not empty
        pop u

        check if current value still holds

        for all the adjacent nodes v
            check if v can be relaxed
                enqueue v
                update distance
        end for
    end while

    return
*/

int main() {
    // int r, c;
    cin >> r >> c;
    for(int i=0; i<r; ++i) for(int j=0; j<c; ++j) cin >> a[i][j];

    cout << "Mini : " << dijkstra(pii(0, 0), pii(r-1, c-1)) << "\n";

    return 0;
}
