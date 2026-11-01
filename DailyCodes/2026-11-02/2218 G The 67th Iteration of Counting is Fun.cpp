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

// Link problem: https://codeforces.com/contest/2218/problem/G

#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
const ll M = 676767677;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--) {
    	ll n, m; cin >> n >> m;
    	vector<ll> b(n);
    	vector<ll> cnt(m);
    	for (int i = 0; i < n; i++) {
    		cin >> b[i];
    		cnt[b[i]]++;
    	}

    	vector<ll> p(m);
    	p[0] = cnt[0];
    	for (int i = 1; i < m; i++) {
    		p[i] = (p[i-1] + cnt[i]) % M;
    	}

    	ll ans = 1;
    	// if (n == 1) {
    	// 	cout << 1 << "\n";
    	// 	continue;
    	// } 
    	for (int i = 0; i < n; i++) {
    		if (b[i] == 0) continue;
    		ll mt = m;
    		if (i-1 >= 0) mt = min(mt, b[i-1]);
    		if (i+1 < n) mt = min(mt, b[i+1]);

    		if (b[i] == mt + 1) {
    			ans = (ans * p[b[i] - 1]) % M; 
    		} else if (b[i] > mt + 1) {
    			ans = (ans * cnt[b[i] - 1]) % M;
    		} else {
    			ans = 0; 
    			break;
    		}
    	}
    	cout << ans << "\n";
    }
    return 0; 
}
