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

// Link problem: https://codeforces.com/gym/106840/problem/B

#include <bits/stdc++.h> 
using namespace std;



void solve() {
	long long n, m, r, c; cin >> n >> m >> r >> c;
	string typeS, typeF; cin >> typeS >> typeF;

	vector<long long> s(n * m), f(n * m);
	for (long long i = 0; i < n * m; i++) {
		cin >> s[i];
	}
	long long len = r * c;
	long long R = n / r, C = m / c; 

	vector<vector<long long>> matrix(n, vector<long long>(m));
	if (typeS == "ND") {
		for (long long i = 0; i < n * m; i++) {
			matrix[i / m][i % m] = s[i];
		} 
	} else {
		long long IR, IC, ir, ic;
		for (long long i = 0; i < n * m; i++) {
			long long block = i / len;
			long long id = i % len;
			if (typeS[0] == 'N') {
				IC = block / R;
				IR = block % R;
			} else {
				IR = block / C;
				IC = block % C;
			}

			if (typeS[1] == 'N') {
				ic = id / r;
				ir = id % r;
			} else {
				ir = id / c;
				ic = id % c;
			}

			matrix[r * IR + ir][c * IC + ic] = s[i];
		}	
	}

	if (typeF == "ND") {
		for (long long i = 0; i < n; i++) for (long long j = 0; j < m; j++) 
			f[i * m + j] = matrix[i][j];
	} else {
		long long IR, IC, ir, ic;
		for (long long i = 0; i < n * m; i++) {
			long long block = i / len;
			long long id = i % len;
			if (typeF[0] == 'N') {
				IC = block / R;
				IR = block % R;
			} else {
				IR = block / C;
				IC = block % C;
			}

			if (typeF[1] == 'N') {
				ic = id / r;
				ir = id % r;
			} else {
				ir = id / c;
				ic = id % c;
			}

			f[i] = matrix[r * IR + ir][c * IC + ic];
		}
	}
	for (long long i = 0; i < f.size(); i++) {
		cout << f[i] << ' '; 
	}
	cout << "\n";
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
