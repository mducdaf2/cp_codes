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

// Link problem: https://codeforces.com/contest/2218/problem/F

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
    	int x, y; cin >> x >> y; 
    	if ((x + y) % 2 == 0 && x == 0) {
    		cout << "NO\n"; 
    		continue; 
    	} else if ((x + y) % 2 == 1 && y == 0) {
    		cout << "NO\n";
    		continue; 
    	}

    	if ((x+y) % 2 == 0) {
    		x--; 
    	} else {
    		y--;
    	}

    	if (x > y) {
    		cout << "NO\n";
    		continue;
    	}

    	int c2 = x; 
    	int c1 = y - x; 

    	// cout << c1 << " " << c2;
    	cout << "YES\n";

    	for (int i = 1; i <= c2; i++) {
    		cout << 1 << " " << 2 * i << "\n";
    		cout << 2 * i << " " << 2 * i + 1<< "\n";
    	}

    	for (int i = 1; i <= c1; i++) {
    		// cout << "Here";
    		cout << 1 << " " << 2 * c2 + 1 + i << "\n";
    	}
    }
    return 0; 
}
