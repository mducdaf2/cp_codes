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

// Link problem: https://codeforces.com/contest/2218/problem/D

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
    	vector<long long> ans(n);
    	ans[0] = 1;
    	for (int i = 1; i < n; i++) {
    		ans[i] = (long long)(2 * i - 1) * (2 * i + 1); 
    	}

    	for (long long i : ans) cout << i << " "; 
    		cout << "\n";
    }
    return 0; 
}
