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

// Link problem: https://oj.vnoi.info/problem/vmunch

#include <bits/stdc++.h> 
using namespace std;

const int dx[4] = {-1, 1, 0, 0}; 
const int dy[4] = {0, 0, -1, 1}; 

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int R, C; cin >> R >> C; 
	vector<string> matrix(R+1, "");

	pair<int, int> s1, s2;
	for (int i = 1; i <= R; i++) {
		cin >> matrix[i];
		for (int j = 0; j < C; j++) {
			if (matrix[i][j] == 'B') {
				s1.first = i; 
				s1.second = j;
			}
			if (matrix[i][j] == 'C') {
				s2.first = i; 
				s2.second = j;
			}
		}
	}

	queue<pair<int, int>> q;
	vector<vector<bool>> visited(R+1, vector<bool>(C, false)); 
	vector<vector<int>> dist(R+1, vector<int>(C, 0)); 
	
	q.push(s1);
	visited[s1.first][s1.second] = true; 

	while (!q.empty()) {
		auto [cx, cy] = q.front(); q.pop();

		int d = dist[cx][cy];
		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx < 1 || nx > R || ny < 0 || ny > C-1) continue;
			if (visited[nx][ny] || matrix[nx][ny] == '*') continue;
			visited[nx][ny] = true; 
			q.push({nx, ny});  
			dist[nx][ny] = d+1;
		}
	}

	cout << dist[s2.first][s2.second] << endl;
    return 0; 
}
