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

// Link problem: https://www.spoj.com/problems/CEQU/

#include <bits/stdc++.h> 
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; for (int i = 1; i <= tc; i++) {
    	cout << "Case " << i << ": ";
    	int a, b, c; cin >> a >> b >> c;  

    	if (a == 0 && b == 0) {
    		if (c == 0) {
    			cout << "Yes\n";
    		} else {
	    		cout << "No\n"; 
    		}
    		continue; 
    	}

    	if ((a == 0 && c % b == 0) || (b == 0 && c % a == 0)) {
    		cout << "Yes\n"; 
    		continue; 
    	}

    	if (a == 0 || b == 0) {
    		cout << "No\n";
    		continue;
    	}

    	int d = gcd(a, b); 
    	if (c % d == 0) {
    		cout << "Yes\n"; 
    	} else {
    		cout << "No\n";
    	}
    }
    return 0; 
}
