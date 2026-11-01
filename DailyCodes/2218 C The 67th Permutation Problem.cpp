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

// Link problem: https://codeforces.com/contest/2218/problem/C

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
    	vector<int> a(3*n); 
    	for (int i = 0; i < n; i++) {
    		a[3 * i] = i + 1; 
    		a[3 * i + 1] = n + 2 * i + 1; 
    		a[3 * i + 2] = n + 2 * i + 2;
    	}
    	for (int i : a) cout << i << " "; 
    	cout << "\n";
    }
    return 0; 
}
