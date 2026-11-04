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

// Link problem: https://codeforces.com/problemset/problem/1265/E?utm_source=chatgpt.com

#include <bits/stdc++.h> 
using namespace std;

typedef long long ll; 
const int M = 998244353;

ll power(ll a, ll b) {
	ll res = 1; 
	while (b) {
		if (b & 1) res = res * a % M; 
		a = a * a % M; 
		b >>= 1; 
	}
	return res; 
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = power(100, M-2); 

	int n; cin >> n;  
	vector<ll> p(n); 
	for (int i = 0; i < n; i++) {
		cin >> p[i];	 
		p[i] = p[i] * t % M; 
	}

	ll suf = 1; 
	ll E1 = 0;
	for (int i = n-1; i >= 0; i--) {
		suf = suf * p[i] % M;
		E1 = (E1 + power(suf, M - 2)) % M; 
	}
	// E1 = E1 + power(suf, M-2) % M; 
	// ll res = 1 + (1 - p[n-1] + M) * E1 % M; 
	// res %= M; 
	cout << E1 << "\n";
 
    return 0; 
}
