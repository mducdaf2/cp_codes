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

// Link problem: https://codeforces.com/problemset/problem/1366/D

#include <bits/stdc++.h> 
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 1e7; 
    vector<int> seive(N+ 1, 0);

    for (int i = 2; i <= N; i++) {
    	if (seive[i] == 0) {
    		for (int j = i; j <= N; j+=i) {
    			seive[j] = i;
    		}
    	}
    }

    int n; cin >> n;  
    vector<int> a(n);  
    for (int i = 0; i < n; i++) cin >> a[i];  

    vector<pair<int, int>> ans(n, {-1, -1});

    for (int i = 0; i < n; i++) {
    	int x = a[i];
    	vector<int> s; 
    	// for (int d = 2; d * d <= x; d++) {
    	// 	if (x % d == 0) {
    	// 		s.push_back(d); 
    	// 		while (x % d == 0) x /= d;
    	// 	}
    	// }
		// if (x > 1) s.push_back(x);
		int d = seive[x];
		while (d != x && x > 1) {
			// cout << d << " ";
			s.push_back(d);
			while (x % d == 0) x /= d;
			d = seive[x];
		}
		if (x > 1) s.push_back(x);
		// cout << "\n";

		int t = 1; 
		for (int d : s) t *= d;

    	if (s.size() > 1) {
    		ans[i].first = s[0];
    		ans[i].second = t / s[0];
    	}

    }  

    for (int i = 0; i < n; i++) {
    	cout << ans[i].first << " "; 
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
    	cout << ans[i].second << " ";  
    }
    return 0; 
}
