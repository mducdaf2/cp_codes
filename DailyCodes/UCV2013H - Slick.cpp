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

// Link problem: https://www.spoj.com/problems/UCV2013H/

#include <bits/stdc++.h> 
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

void solve(int n, int m) {
	vector<vector<int>> matrix(n + 1, vector<int>(m + 1));
    vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));
	map<int, int> ans;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> matrix[i][j];
		}
	}

	int total = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (visited[i][j] || matrix[i][j] == 0) continue;
			queue<pair<int, int>> q;
			q.push({i, j});
			visited[i][j] = true;
			int cnt = 0;
			while (!q.empty()) {
				auto [cx, cy] = q.front(); q.pop();
				cnt++;
				for (int k = 0; k < 4; k++) {
					int nx = cx + dx[k];
                    int ny = cy + dy[k];
                    if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                    if (visited[nx][ny] || matrix[nx][ny] == 0) continue;
					visited[nx][ny] = true;
					q.push({nx, ny});
				}
			}
			ans[cnt]++;
			total ++;
		}
	}

	cout << total << '\n';
 	for (auto [k, v] : ans) {
		cout << k << " " << v << '\n';
	}
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (true) {
    	int n, m; cin >> n >> m;
    	if (n == 0 && m == 0) return 0;
    	solve(n, m);
    }
    return 0; 
}
