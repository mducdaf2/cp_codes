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

// Link problem: 

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
    	vector<int> a(n);  
    	for (int i = 0; i < n; i++) {
    		cin >> a[i]; 
    	}

    	// sort(a.begin(), a.end());
    	int s = 0;
    	for (int i = 0; i < n-1; i++) {
    		for (int j = i+1; j < n; j++) {
    			s = max(s, a[i] ^ a[j]);
    		}
    	}
    	cout << s << "\n"; 
    }
    return 0; 
}
