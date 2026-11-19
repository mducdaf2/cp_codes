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

// Link problem: https://qoj.ac/contest/4538/problem/22831

#include <bits/stdc++.h> 
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;  
    vector<vector<int>> adj(n+1, vector<int>());
    for (int i = 0; i < m; i++) {
    	int u, v; cin >> u >> v; 
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    vector<bool> check(n+1, false);
    vector<bool> color(n+1, 0);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
    	if (check[i]) continue;
		stack<int> s; 
	    s.push(i);
	    check[i] = true;
	    color[i] = true;
		long long cnt0 = 0, cnt1 = 0;
		bool is_bipair = true;
	    while (!s.empty()) {
	    	int node = s.top(); s.pop(); 
	    	bool c = color[node];
	    	if (c) cnt1++;
	    	else cnt0++; 
	    	for (int j : adj[node]) {
	    		if (!check[j]) {
	    			color[j] = !c; 
	    			check[j] = true;
	    			s.push(j);
	    		} else {
	    			if (color[j] == c) is_bipair = false;
	    		}
	    	}
	    }
	    if (is_bipair) ans = ans + cnt0 * cnt0 + cnt1 * cnt1;
	    else ans = ans + (cnt0 + cnt1) * (cnt0 + cnt1);
    }

    cout << ans << endl;
    return 0; 
}
