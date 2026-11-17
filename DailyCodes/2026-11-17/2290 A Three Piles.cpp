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

// Link problem: https://codeforces.com/problemset/problem/2290/A

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
    	vector<int> v(3); 
    	for (int i = 0; i < 3; i++) cin >> v[i];

    	sort(v.begin(), v.end()); 
    	v[0] ++; 
    	v[2] --; 
    	if (v[0] == v[1] && v[1] == v[2]) {
    		cout << "YES\n";
    	} else {
    		cout << "NO\n";
    	}
    }
    return 0; 
}
