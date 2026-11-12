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

// Link problem: https://codeforces.com/problemset/problem/2269/A

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
    	int n, k; cin >> n >> k;  
    	int ans = 0; 
    	int d = n - k + 1; 
    	ans = (1 << d) + 2 * (k - 1);
    	cout << ans << "\n";
    }

    return 0; 
}
