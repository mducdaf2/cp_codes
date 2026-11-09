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

// Link problem: https://codeforces.com/contest/2280/problem/A

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
    	vector<int> a(n), b(n);  
    	for (int i = 0; i < n; i++) cin >> a[i]; 

    	for (int i = 0; i < n; i++) cin >> b[i];

    	int cnta = 0; 
    	for (int i = 0; i < n; i++) {
    		if (a[i] % 2 == 0) cnta++;
    	}


    	int cntb = 0; 
    	for (int i = 0; i < n; i++) {
    		if (b[i] % 2 == 0) cntb++;
    	}

    	if (cnta == cntb) {
    		cout << "YES\n";
    	} else {
    		if (k % 2 == 1) {
    			if (cnta > cntb) {
    				cout << "YES\n";
    			} else {
    				cout << "NO\n";
    			}
    		} else {
    			if (cnta < cntb) {
    				cout << "YES\n";
    			} else {
    				cout << "NO\n";
    			}
    		}
    	}
    }
    return 0; 
}
