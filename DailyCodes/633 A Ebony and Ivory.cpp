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

// Link problem: https://codeforces.com/contest/633/problem/A

#include <bits/stdc++.h> 
using namespace std;

int extEuclid(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1; 
		y = 0;
		return a; 
	}

	int q = a / b; 
	int r = a - b * q; 

	int x0 = 0, y0 = 0; 
	int d = extEuclid(b, r, x0, y0); 
	x = y0; 
	y = x0 - q * y0; 
	return d;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b, c; cin >> a >> b >> c;  

    int x, y; 
    int d = extEuclid(a, b, x, y);
    x *= c / d; 
    y *= c / d;
    int t1 = b / d; 
    int t2 = a / d;
    // cout << x << " " << y;
    if (c % d == 0) {
    	if (x >= 0 && y >= 0) {
    		cout << "Yes\n";
    	} else if (x >= 0) {
    		int k = x / t1; 
    		if (y + k * t2 >= 0) {
    			cout << "Yes\n";
    		} else {
    			cout << "No\n";
    		}
    	} else if (y >= 0) {
    		int k = y / t2; 
    		if (x + k * t1 >= 0) {
    			cout << "Yes\n";
    		} else {
    			cout << "No\n";
    		} 		
    	} else {
    		cout << "No\n";
    	}
    } else {
    	cout << "No\n";
    }
    return 0; 
}
