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

// Link problem: https://codeforces.com/problemset/problem/2036/D

#include <bits/stdc++.h> 
using namespace std;

int n, m; 
vector<string> matrix;

pair<int, int> move(int x, int y, int layer) {
	if (x == layer) {
		if (y == m - layer + 1) {
			return {x + 1, y};
		} else return {x, y + 1};
	} else if (x == n - layer + 1) {
		if (y == layer) {
			return {x - 1, y}; 
		} else return {x, y - 1}; 
	} else {
		if (y == layer) {
			if (x == layer) return {x, y + 1}; 
			else return {x-1, y}; 
		} else if (y == m - layer + 1) {
			if (x == n - layer + 1) return {x, y - 1}; 
			return {x + 1, y}; 
		} else return {-1, -1};
	}
}

bool valid(vector<int> &v) {
	vector<int> c = {'1', '5', '4', '3'}; 
	for (int i = 0; i < 4; i++) {
		int x = v[2*i];
		int y = v[2*i+1]; 
		if (matrix[x-1][y-1] != c[i]) return false; 
	}
	return true; 
}

bool check(int x, int y) {
	int layer = min({x, n - x + 1, y, m - y + 1});
	vector<int> v(8); 
	v[0] = x; v[1] = y;  
	for (int i = 1; i <= 3; i++) {
		auto p = move(x, y, layer);
		x = p.first; y = p.second;
		v[2 * i] = x; 
		v[2 * i + 1] = y; 
	}
	return valid(v);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--) {
    	cin >> n >> m; 
    	vector<pair<int, int>> p; 
    	matrix.resize(n);
    	for (int i = 0; i < n; i++) {
    		cin >> matrix[i];
    		for (int j = 0; j < m; j++) {
    			if (matrix[i][j] == '1') p.push_back({i+1, j+1});
    		}
    	}

    	int ans = 0; 
    	for (int i = 0; i < p.size(); i++) {
    		auto [x, y] = p[i];
    		ans += check(x, y) ? 1 : 0;
    	}
    	cout << ans << endl;
    }
    return 0; 
}
