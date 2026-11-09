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

// Link problem: https://codeforces.com/contest/2280/problem/B

#include <bits/stdc++.h> 
using namespace std;

void query(int l, int r) {
	cout << "? " << l << " " << r << endl;
}

int main(){
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--) {
    	int n; cin >> n;

    	query(1, n); 
    	int s; cin >> s;  
    	if (s == n) {
    		cout << "! NO" << endl;
    	} else if (s == n-1) {
    		query(n, n); 
    		cin >> s; 
    		if (s == 0) {
    			cout << "! NO" << endl;
    		} else {
    			cout << "! YES" << endl;
    		}
    	} else {
    		query(s + 1, n);
    		int x; cin >> x; 
    		if (x == 0) {
    			cout << "! NO" << endl;
    		} else {
    			cout << "! YES" << endl;
    		}
    	}
    }
    return 0; 
}
