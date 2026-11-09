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

// Link problem: https://codeforces.com/contest/1267/problem/G

#include <bits/stdc++.h> 
using namespace std;

typedef long double ld;  


int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x; cin >> n >> x;  
    vector<int> c(n);  
    int S = 0; 
    for (int i = 0; i < n; i++) {
    	cin >> c[i]; 
    	S += c[i];
    }

    vector<ld> C(n+1);
    C[0] = 1; 
    for (int k = 1; k <= n; k++) {
    	C[k] = C[k-1] / (ld)k * (n - k + 1);
    } 

	vector<vector<ld>> dp(n + 1, vector<ld>(S + 1, 0));
    dp[0][0] = 1;  
 
    for (int i = 0; i < n; i++) {
    	for (int k = n; k >= 1; k--) {
    		for (int s = S; s >= c[i]; s--) {
    			dp[k][s] += dp[k-1][s - c[i]];
    		}
    	}
    }

    ld ans = 0;
    for (int k = 0; k < n; k++) {
    	int b = n - k;  

    	ld ranCost = ((ld)n / b + 1) * x / 2; 
    	for (int s = 0; s <= S; s++) {
    		if (dp[k][s] == 0) continue;
    		ld directCost = (ld)(S - s) / b;

    		ld cost = min(ranCost, directCost);
    		ans += dp[k][s] / C[k] * cost;
    	}
    }

    cout << fixed << setprecision(9) << ans << "\n";

    return 0; 
}
