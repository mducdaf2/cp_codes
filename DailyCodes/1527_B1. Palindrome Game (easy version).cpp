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

// Link problem: https://codeforces.com/problemset/problem/1527/B1

#include <bits/stdc++.h> 
using namespace std;

void solve() {
	int n; cin >> n;  
	string s; cin >> s; 
	int c0 = 0; 
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') c0++;
	}
	bool res;
	if (s[n/2] == '0' && n % 2 == 1) {
		c0--; 
		if (c0 == 0) {
			cout << "BOB\n";
		} else {
			cout << "ALICE\n";
		}
		return ; 
	}

	cout << "BOB\n";
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
