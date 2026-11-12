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

// Link problem: https://codeforces.com/problemset/problem/2120/A

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
    	int l1, b1, l2, b2, l3, b3; cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3; 
    	int S = l1 * b1 + l2 * b2 + l3 * b3; 
    	
    	if (l1 + l2 + l3 == b1 && b1 == b2 && b2 == b3) cout << "YES\n";
    	else if (b1 == b2 + b3 && l2 == l3 && l1 + l2 == b1) cout << "YES\n"; 
		else if (b1 + b2 + b3 == l1 && l1 == l2 && l2 == l3) cout << "YES\n";
    	else if (l1 == l2 + l3 && b2 == b3 && b1 + b2 == l1) cout << "YES\n"; 
    	else cout << "NO\n";
    }
    return 0; 
}
