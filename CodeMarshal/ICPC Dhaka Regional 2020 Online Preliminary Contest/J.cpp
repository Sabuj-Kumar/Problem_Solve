#include<bits/stdc++.h>
using namespace std;
void solve() {
    long long n, ans = 0, cnt = 0, _max = INT_MIN;
    cin >> n;
    vector<long long> vi(n);
    for (int i = 0; i < n; ++i) {
        cin >> vi[i];
        if (vi[i] > 0) {
            ans += vi[i];
        } else {
            cnt++;
        }
        _max = max(_max, vi[i]);
    }
    if (cnt == n) {
        cout << _max << " " << 0 << '\n';
        return;
    }
    long long int chunk = 0, pos_chunk = 0;
    long long int cf = 0;
    if (vi[0] >= 0) pos_chunk++;
    else chunk++;
    for (int i = 1; i < n; ++i) {
        if (vi[i] < 0 and vi[i - 1] >= 0) chunk++;
        else if (vi[i] >= 0 and vi[i -1] < 0) pos_chunk++;
    }
    if (pos_chunk == 1) cout << ans << " " << 0 << '\n';
    else if (chunk == 1) {
        if (vi[0] < 0 or vi[n - 1] < 0) {
            cout << ans << " " << 0 << '\n';
        } else {
            cout << ans << " " << 1 << '\n';
        }
    }
    else if (chunk == 2) {
        if (vi[0] < 0 or vi[n - 1] < 0) {
            cout << ans << " " << 1 << '\n';
        } else {
            cout << ans << " " << 2 << '\n';
        }
    }
    else {
        if (vi[0] < 0 or vi[n - 1] < 0) chunk--;
        cout << ans << " " << chunk << '\n';

    }
    return;
}
int main() {

    freopen("in.txt","r",stdin);

//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        cout << "Case " << cas << ": ";
        solve();
    }
    return 0;
}
