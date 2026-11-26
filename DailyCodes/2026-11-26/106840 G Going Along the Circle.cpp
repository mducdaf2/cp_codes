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

// Link problem: https://codeforces.com/gym/106840/problem/G

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
    	int n; cin >> n;
    	vector<int> p(n), f(n);
    	for (int i = 0; i < n; i++) {
    		cin >> p[i];
    		f[p[i] - 1] = i;
    	}

    	int m = 2e5;
    	int M = 0;

    	for (int i = 0; i < n-1; i++) {
    		int dist = (f[i+1] - f[i] + n) % n;
    		m = min(m, dist);
    		M = max(M, dist);
    	}

    	cout << m << " " << M << "\n";
    }
    return 0; 
}
