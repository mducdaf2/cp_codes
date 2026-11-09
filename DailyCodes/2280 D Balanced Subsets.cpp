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

// Link problem: https://codeforces.com/contest/2280/problem/D

#include <bits/stdc++.h> 
using namespace std;

const int MOD = 998244353;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--) {
    	        int n;
        cin >> n;
        int M = 3 * n;
        vector<char> in(M + 1, 0);
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            in[a] = 1;
        }

        long long dp[8][3], nd[8][3];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1; 

        for (int v = M; v >= 1; v--) {
            memset(nd, 0, sizeof(nd));
            for (int mask = 0; mask < 8; mask++) {
                for (int u = 0; u < 3; u++) {
                    long long cur = dp[mask][u];
                    if (!cur) continue;

                    int nm = (mask << 1) & 7;
                    nd[nm][u] = (nd[nm][u] + cur) % MOD;

                    if (in[v]) {
                        int nu = u;
                        if (__builtin_popcount(mask) != 2) nu++; 
                        if (nu <= 2) {
                            int nm2 = ((mask << 1) | 1) & 7;
                            nd[nm2][nu] = (nd[nm2][nu] + cur) % MOD;
                        }
                    }
                }
            }
            memcpy(dp, nd, sizeof(dp));
        }

        long long ans = 0;
        for (int mask = 0; mask < 8; mask++)
            for (int u = 0; u < 3; u++)
                ans = (ans + dp[mask][u]) % MOD;

        ans = (ans - 1 + MOD) % MOD;
        cout << ans << "\n";
    }
    return 0; 
}
