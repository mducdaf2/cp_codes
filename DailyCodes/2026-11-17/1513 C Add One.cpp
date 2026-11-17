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

// Link problem: https://codeforces.com/problemset/problem/1513/C

#include <bits/stdc++.h> 
using namespace std;

const int M = 1e9+7;
const int MAX = 2e5 + 10; 
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<long long> dp(MAX+1, 1);
    for (int i = 10; i <= MAX; i++) dp[i] = (dp[i-10] + dp[i-9]) % M;
    int tc; cin >> tc; while (tc--) {
    	string n; cin >> n;  
    	int m; cin >> m;
    	long long ans = 0;  

    	for (int i = 0; i < n.size(); i++) {
    		int x = n[i] - '0';
    		ans = (ans + dp[m + x]) % M;
    	}
    	cout << ans << endl;
    }
    return 0; 
}
