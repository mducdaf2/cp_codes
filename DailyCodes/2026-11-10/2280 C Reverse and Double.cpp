/*
     _        __   ____  
  __| | __ _ / _| |___ \ 
 / _` |/ _` | |_    __) |
| (_| | (_| |  _|  / __/ 
 \__,_|\__,_|_|   |_____|
 
- Author: Mai Duc
- Codeforces: daf_2
- GitHub: mducdaf2
*/

// Link problem: https://codeforces.com/contest/2280/problem/C
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a, d, pre, suf;

int eval(int l, int r, int inner) {
    int res = 2 * inner;
    if (l > 0) {
        res = max(res, pre[l - 1]);
        res = max(res, abs(a[l - 1] - 2 * a[r]));
    }
    if (r < n - 1) {
        res = max(res, suf[r + 1]);
        res = max(res, abs(2 * a[l] - a[r + 1]));
    }
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc;
    while (tc--) {
        cin >> n;
        a.assign(n, 0);
        for (auto &x : a) cin >> x;

        d.assign(n - 1, 0);
        for (int i = 0; i < n - 1; i++) d[i] = abs(a[i] - a[i + 1]);

        pre.assign(n + 1, 0);
        suf.assign(n + 2, 0);
        for (int i = 0; i < n - 1; i++) pre[i + 1] = max(pre[i], d[i]);
        for (int i = n - 2; i >= 0; i--) suf[i] = max(suf[i + 1], d[i]);

        int M = pre[n - 1];
        vector<int> es;
        for (int i = 0; i < n - 1; i++) if (d[i] == M) es.push_back(i);

        int ans = M;
        if (es.size() == 2) {
            int l = es[0] + 1, r = es[1];
            int inner = 0;
            for (int i = l; i < r; i++) inner = max(inner, d[i]);
            ans = min(ans, eval(l, r, inner));
        } else if (es.size() == 1) {
            int e = es[0];
            int inner = 0;
            for (int l = e; l >= 0; l--) {
                if (l < e) inner = max(inner, d[l]);
                ans = min(ans, eval(l, e, inner));
            }
            inner = 0;
            int l = e + 1;
            for (int r = l; r < n; r++) {
                if (r > l) inner = max(inner, d[r - 1]);
                ans = min(ans, eval(l, r, inner));
            }
        }
        cout << ans << "\n";
    }
    return 0;
}