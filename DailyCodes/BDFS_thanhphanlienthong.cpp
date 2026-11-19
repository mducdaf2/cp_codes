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

// Link problem: https://lequydon.ntucoder.net/Problem/Details/4601

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
    vector<int> adj[n+1];
    vector<int> visited(n+1, false);

    for (int i = 0; i < m; i++) {
    	int u, v; cin >> u >> v; 
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

   	int ans = 0;


    for (int i = 1; i <= n; i++) {
    	if (visited[i]) continue; 
    	queue<int> q; q.push(i);
    	visited[i] = true;
    	ans++;
    	while (!q.empty()) {
    		int node = q.front(); q.pop();

    		for (int j : adj[node]) {
    			if (visited[j]) continue;
    			q.push(j); visited[j] = true;
    		}
    	}
    }
    cout << ans << endl;
    return 0; 
}
