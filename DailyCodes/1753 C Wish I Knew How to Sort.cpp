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

// Link problem: https://codeforces.com/problemset/problem/1753/C?utm_source=chatgpt.com

#include <bits/stdc++.h> 
using namespace std;

const int M = 998244353;
const int N = 2e5; 
typedef long long ll;  



ll power(ll a, ll b) {
	ll res = 1; 
	while (b > 0) {
		if (b & 1) res = res * a % M; 
		a = a * a % M; 
		b /= 2; 
	}
	return res; 
}

// ll fact[N+1], invfact[N+1];  

void solve() {
	int n; cin >> n; 
	vector<int> a(n); 
	for (int i = 0; i < n; i++) cin >> a[i]; 

	ll g = 0; 
	for (int i = 0; i < n; i++) g += a[i] == 0 ? 1 : 0; 
	ll t = 0;
	for (int i = 0; i < g; i++) t += a[i] == 0 ? 1 : 0;

	vector<int> dp(g+1, 0);
	for (int k = g-1; k >= 0; k--) {
		ll p = ((2 * (g - k) * (g - k) % M) * power(n, M-2)) % M * power(n-1, M-2) % M;
		p %= M; 
		dp[k] = ((1 + dp[k+1] * p % M) * power(p, M-2)) % M; 
	}

	cout << dp[t] << "\n";
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // fact[0] = 1;  
    // for (int i = 1; i <= N; i++) {
    // 	fact[i] = fact[i-1] * i % M; 
    // }

    // invfact[N] = power(fact[N], M-2); 
    // for (int i = N; i > 0; i--) {
    // 	invfact[i-1] = invfact[i] * i % M;
    // }

    int tc; cin >> tc; while (tc--) {
    	solve(); 
    }
    return 0; 
}
