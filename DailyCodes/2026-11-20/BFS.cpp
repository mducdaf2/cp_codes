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

// Link problem: https://lqdoj.edu.vn/problem/bfs

#include <bits/stdc++.h> 
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, s; cin >> n >> m >> s; 
    vector<int> adj[n+1];
    vector<bool> vistited(n+1, false);
    vector<int> dist(n+1, 0);

    for (int i =  0; i < m; i++) {
    	int u, v; cin >> u >> v; 
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    queue<int> q; q.push(s);
    vistited[s] = true; 
    dist[s] = 0;
    while (!q.empty()) {
    	int node = q.front(); q.pop();

    	int d = dist[node];
    	for (int j : adj[node]) {
    		if (!vistited[j]) {
    			dist[j] = d+1;
    			vistited[j] = true;
    			q.push(j);
    		}
    	}
    }

    vector<pair<int, int>> P; 
    for (int i = 1; i <= n; i++) {
    	if (!vistited[i]) continue;
    	P.push_back({dist[i], i});
    }

    sort(P.begin(), P.end());
    for (int i = 0; i < P.size(); i++) {
    	cout << P[i].second << " " << P[i].first << (i != n-1 ? "\n" : "");
    }
    return 0; 
}
