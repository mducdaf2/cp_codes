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

// Link problem: https://codeforces.com/contest/2185/problem/C

#include <bits/stdc++.h> 
using namespace std;

int mex(vector<int> &U) {
	if (U[0] > 0) return 0;
	for (int i = 1; i < U.size(); i++) {
		if (U[i] - U[i-1] >= 2) {
			return U[i-1] + 1; 
		}
	}
	return U.back() + 1;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--) {
    	int n; cin >> n; 
    	vector<int> a(n);
    	int m = 1e9+1;
    	for (int i = 0; i < n; i++) {
    		cin >> a[i];
    		m = min(m, a[i]);
    	}

    	for (int i = 0; i < n; i++) {
    		a[i] -= m;
    	}

    	sort(a.begin(), a.end());
    	// cout << mex(a) << "\n";
    	int ans = 1; 
    	int i = 0; 
    	while (i < n-1) {
    		int j = i + 1; 
    		while (j < n && a[j] - a[j-1] <= 1) {
    			j++;
    		}
    		ans = max(ans, a[j-1] - a[i] + 1);
    		i = j;
    	}
    	cout << ans << "\n";
    }
    return 0; 
}
