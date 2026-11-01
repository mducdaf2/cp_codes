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

// Link problem: https://codeforces.com/contest/2185/problem/E

#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
const int K = 2e5;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--) {
    	int n, m, k; cin >> n >> m >> k;
    	vector<ll> a(n), b(m);
    	for (int i = 0; i < n; i++) cin >> a[i];
    	for (int i = 0; i < m; i++) cin >> b[i];

    	string s; cin >> s;
    	vector<ll> p(k+1, 0);
    	// p[0] = s[0] == 'R' ? 1 : -1;
    	for (int i = 1; i <= k; i++) {
    		p[i] = p[i-1] + (s[i-1] == 'R'? 1 : -1);
    	}
    	// for (int i : p) cout << i << " ";

    	sort(b.begin(), b.end());

    	map<int, vector<int>> ps; 

    	for (int i = 0; i < n; i++) {
    		if (a[i] > b[0]) {
    			int t = a[i] - *(lower_bound(b.begin(), b.end(), a[i]) - 1); 
    			ps[-t].push_back(i);
    			// cout << t;
    		}

    		if (a[i] < b[m-1]) {
    			int t = *lower_bound(b.begin(), b.end(), a[i]) - a[i];
    			ps[t].push_back(i);
    			// cout << t;
    		}
    	}


    	vector<bool> check(n+1, false); 
    	int ans = n;
    	for (int i = 1; i <= k; i++) {
    		// cout << p[i] << " - ";
    		for (int x : ps[p[i]]) {
    			// cout << "here";
    			if (check[x]) continue; 
    			check[x] = true; 
    			ans--;
    		}
    		ps[p[i]].clear();


    		cout << ans << " ";
    	}
    	cout << "\n";
    }
    return 0; 
}
