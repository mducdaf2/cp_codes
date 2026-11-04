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

// Link problem: https://codeforces.com/contest/1916/problem/B

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
    	long long a1, b1; cin >> a1 >> b1;
    	long long a = min(a1, b1); 
    	long long b = max(a1, b1);  
    	long long g = gcd(a, b);  
    	long long ans = b / g; 
    	ans *= a; 

    	if (ans == b) {
    		long long d = b / a; 
    		ans *= d;
    	}
    	cout << ans << "\n";
    }
    return 0; 
}
