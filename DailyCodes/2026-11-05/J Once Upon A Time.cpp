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

// Link problem: https://codeforces.com/gym/100963/attachments/download/4256/20072008-summer-petrozavodsk-camp-japanese-contest-20070829-en.pdf

#include <bits/stdc++.h> 
using namespace std;

long long extEuclid(long long a, long long b, long long &x, long long &y) {
	if (b == 0) {
		x = 1; 
		y = 0; 
		return a; 
	}

	long long x0 = 0, y0 = 0; 
	long long d = extEuclid(b, a % b, x0, y0); 

	x = y0; 
	y = x0 - (a/b) * y0; 
	return d;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (true) {
    	long long n, m, a1, k1; cin >> n >> m >> a1 >> k1; 
    	if (n == 0 && m == 0 && a1 == 0 && k1 == 0) {
    		break;
    	}

    	long long a = m; 
    	long long b = -a1; 
    	long long c = k1+a1 - n; 

    	if (a == 0 && b == 0) {
    		if (c == 0) {
    			cout << 0 << "\n";
    		} else {
    			cout << "Impossible\n";
    		}
    		continue;
    	} 

    	if (c < 0) {
    		a = -a; 
    		b = -b; 
    	}
    	int sa = a > 0 ? 1 : -1; 
    	int sb = b > 0 ? 1 : -1; 

    	a = abs(a); 
    	b = abs(b); 

    	if (a == 0) {
    		if (c % b != 0) {
    			cout << "Impossible\n";
    		} else {
    			long long y = c / b * sb; 
    			if (y < 0) {
	    			cout << "Impossible\n";
    			} else {
    				cout << k1 + a1 + k1 * y << "\n";
    			}
    		}
    		continue;
    	}


    	if (b == 0) {
    		if (c % a != 0) {
    			cout << "Impossible\n";
    		} else {
    			long long x = c / a * sa; 
    			if (x < 0) {
	    			cout << "Impossible\n";
    			} else {
    				cout << n + m * x << "\n";
    			}
    		}
    		continue;
    	}

    	long long x, y; 
    	long long d = extEuclid(a, b, x, y); 

    	if (c % d != 0) {
    		cout << "Impossible\n";
    		continue;
    	}

    	x = c / d * x * sa; 
    	y = c / d * y * sb; 

    	long long t1 = b / d * sa; 
    	long long t2 = - a / d * sb; 

    	int k3 = - x / t1;
    	int k4 = - y / t2;  
    	
    	int L = -1, R = -1; 
    	if (t1 < 0) {
    		R = max(R, k3); 
    	} else {
    		L = max(L, k3);
    	}

    	if (t2 < 0) {
    		R = max(R, k4); 
    	} else {
    		L = max(L, k4);
    	}

    	if (R == -1) R = 1e5;
    	if (L > R) {
    		cout << "Impossible\n";
    		continue; 
    	} else {
    		bool check = false; 
    		for (int i = L; i <= R; i++) {
    			long long x0 = x + i * t1; 
    			long long y0 = y + i * t2; 
    			if (x0 >= 0 && y0 >= 0) {
    				cout << n + m * x0 << "\n";
    				check = true;
    				break;
    			}
    		}
    		if (!check) {
    			cout << "Impossible\n";
    		}
    		continue;
    	}
    }
    return 0; 
}
