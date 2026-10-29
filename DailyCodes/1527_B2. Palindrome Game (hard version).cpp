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

// Link problem: https://codeforces.com/problemset/problem/1527/B2

#include <bits/stdc++.h> 
using namespace std;

void solve() {
	int n; cin >> n;  
	string s; cin >> s; 
	int c0n = 0;
	int c0 = 0;  
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			c0++;
			if (s[n-i-1] == '1') {
				c0n++;
				s[i] = '1';
			}
		}
	}
	int c0p = c0 - c0n;
	int p1 = 0, p2 = 0; 
	p2 = c0n;

	if (c0n == 0) {
		if (s[n / 2] == '0' && n % 2 == 1) {
			c0p--;
			p1++;
			// s is palindrome, bob play 
			p2 += c0p > 0 ? 2 : 0;
		} else {
			// s is palindrome, alice play 
			p1 += c0p > 0 ? 2 : 0;
		}
	} else {
		// Alice can determine who place on new palindrome string
		// Case 1: Bob play first 
		int p11 = 1; int p21 = c0n - 1;
		int c = c0p;
		if (s[n / 2] == '0' && n % 2 == 1) {
			c--;
			p21++;
			// s is palindrome, alice play 
			p11 += c > 0 ? 2 : 0;
		} else {
			p21 += c > 0 ? 2 : 0;
		}

		// Case 2: Alice play first 
		int p12 = 0; int p22 = c0n;
		c = c0p;
		if (s[n / 2] == '0' && n % 2 == 1) {
			c--;
			p12++;
			// s is palindrome, bob play 
			p22 += c > 0 ? 2 : 0;
		} else {
			p12 += c > 0 ? 2 : 0;
		}

		if (p11 - p21 < p12 - p22) {
			p1 = p11; 
			p2 = p21; 
		} else {
			p1 = p12; 
			p2 = p22;
		}
	}

	if (p1 < p2) {
		cout << "ALICE\n";
	} else if (p1 > p2) {
		cout << "BOB\n";
	} else {
		cout << "DRAW\n";
	}

}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--) {
    	solve();
    }
    return 0; 
}
