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

// Link problem: https://codeforces.com/problemset/problem/2267/C

#include <bits/stdc++.h> 
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--) {
    	int n, x; cin >> n >> x;  

    	vector<int> a(n); 
    	for (int i = 0; i < n; i++) {
    		cin >> a[i]; 
    	}

    	// div of x 
    	vector<int> div; 
    	for (int i = 2; i * i <= x; i++) {
    		if (x % i == 0) {
    			div.push_back(i); 
    			if (x / i != i) div.push_back(x/i);
    		}
    	}
    	if (x != 1) div.push_back(x);

    	// vector<int> s; 
    	long long ans = 0; 
    	for (int i = 0; i < (int)div.size(); i++) {
    		int d = div[i];
    		long long temp = 0;
    		for (int j = 0; j < n; j++) {
    			if (a[j] % d == 0) temp += a[j];
    		}
    		ans = max(temp, ans); 
    	}

    	cout << ans << "\n";
    }

    return 0; 
}
