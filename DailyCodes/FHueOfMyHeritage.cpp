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

// Link problem: https://pc2pnwonline.icpc-vcss.org/problems/F-Einszweidrei-1/F-Einszweidrei-1.pdf

#include <bits/stdc++.h> 
using namespace std;

const int M = 998244353;

long long power(long long a, long long b) {
	long long res = 1; 
	while (b > 0) {
		if (b % 2 == 1) res = (res * a) % M;
		a = a * a % M;
		b >>= 1;
	}
	return res;
}

void solve() {
	int n; cin >> n; 
	// vector<int> p(n-1);
	vector<vector<int>> adj(n+1);
	for (int i = 2; i <= n; i++) {
		// cin >> p[i];
		int x; cin >> x;
		adj[x].push_back(i);
		adj[i].push_back(x);
	}

	// vector<int> layer = {1};
	queue<int> s;
	s.push(1);
	vector<int> check(n+1, -1);
	check[1] = 1;
	int m = 1;
	while (!s.empty()) {
		int node = s.front(); s.pop();
		int l = check[node];
		m = max(m, l);

		for (int j : adj[node]) {
			if (check[j] == -1) {
				check[j] = l+1;
				s.push(j);
			}
		}
	}
	vector<int> layer(m + 1, 0);
	for (int i = 1; i <= n; i++) {
		layer[check[i]]++;
	}

	// for (int i : layer) cout << i << " ";
	long long ans = 0;
	vector<long long> v(m);
	for (int i = 0; i < m; i++) {
		long long cnt = layer[i+1];
		long long b = (1LL * i * M - 2 * i) % (M - 1);
		// cout << b << " ";
		b = power(2, b);

		long long fail = (1 - b + M) % M;
		// cout << fail << " ";
		long long succes = (1 - power(fail, cnt) + M) % M;
		ans = (ans + succes) % M;
		v[i] = succes;
	}
	// ans = (v[0] - v[1] + M) % M;
	// for (int i = 1; i < m; i++) {
	// 	ans = (ans + (v[i-1] - v[i] + M) % M * i % M) % M;
	// 	if (i == m-1) {
	// 		ans = (ans + v[i] * m % M) % M;
	// 	}
	// }

	// long long c = 0;
	// for (int i = 1; i < m; i++) c = (c + v[i-1] - v[i] + M) % M;
	// 	c = (c + v[m-1]) % M;
		cout << c << endl;
	cout << ans << endl;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--) {
    	solve();
    }
    return 0; 
}
