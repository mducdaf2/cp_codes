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

// Link problem: https://codeforces.com/problemset/problem/877/D

#include <bits/stdc++.h> 
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k; cin >> n >> m >> k;
    vector<string> grid(n+1);
    for (int i = 1; i <= n; i++) {
    	cin >> grid[i];
    }

    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2; 
    y1--; y2--;
    if (grid[x1][y1] == '#' || grid[x2][y2] == '#') {
    	cout << -1 << endl; 
    	return 0;
    }
    int dx[] = {-1, 1, 0, 0}; 
    int dy[] = {0, 0, -1, 1}; 

    queue<pair<int, int>> q; q.push({x1, y1}); 
    vector<vector<bool>> visited(n+1, vector<bool>(m, false));
    visited[x1][y1] = true;  

    vector<vector<int>> dist(n+1, vector<int>(m, 0));

    while (!q.empty()) {
    	auto [cx, cy] = q.front(); q.pop();
    	int di = dist[cx][cy];
		if (cx == x2 && cy == y2) {
			cout << dist[cx][cy] << endl;
			return 0;
		}
    	for (int d = 0; d < 4; d++) {
    		for (int step = 1; step <= k; step++) {
    			int nx = cx + dx[d] * step;
    			int ny = cy + dy[d] * step;

    			if (nx < 1 || nx > n || ny < 0 || ny > m-1) break;
    			if (grid[nx][ny] == '#') break;

    			if (visited[nx][ny]) {
    				if (dist[nx][ny] < di + 1) break;
    				continue;
    				// dist[nx][ny] = di+1;
    			}

    			visited[nx][ny] = true;
    			q.push({nx, ny});
    			dist[nx][ny] = di + 1;
    		}
    	}
    }
    cout << -1 << endl;
    return 0; 
}
