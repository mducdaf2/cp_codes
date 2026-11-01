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

// Link problem: https://codeforces.com/contest/2218/problem/B

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
    	int s = 0; 
    	vector<int> a(7); 
    	for (int i = 0; i < 7; i++) {
    		cin >> a[i]; 
    	}
    	sort(a.begin(), a.end()); 
    	for (int i = 0; i < 6; i++) {
    		s -= a[i]; 
    	}
    	s += a[6]; 
    	cout << s << "\n";
    }
    return 0; 
}
