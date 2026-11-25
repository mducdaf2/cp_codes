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

// Link problem: https://codeforces.com/gym/106840/problem/L

#include <bits/stdc++.h> 
using namespace std;

const long double PI = acos(-1);



void solve() {
	int a, b; cin >> a >> b; 

	if (a == b) {
		cout << -1 << "\n";
		return;
	}

	if (a > b) {
		int c = a - b;
		if (360 % c != 0) {
			cout << -1 << '\n';
			return;
		}
		long double n = 360 / c;

		// cout << n << ' ';
		long double alpha = PI * a / 180;
		long double beta = PI * (180 - c) / 180;

		// long double edge = 2 * cos(alpha / 2);
		// cout << edge << " ";
		long double ans = n * (2 * cos(alpha) + 2) * tan(beta / 2) / 4 + n * sin(alpha) / 2;
		cout << fixed << setprecision(20) << ans << endl;
	} else {
		int c = b - a;
		if (360 % c != 0) {
			cout << -1 << '\n';
			return;
		}
		long double n = 360 / c;

		// cout << n << ' ';
		long double alpha = PI * a / 180;
		long double beta = PI * (180 - c) / 180;

		// long double edge = 2 * cos(alpha / 2);
		// cout << edge << " ";
		long double ans = n * (2 * cos(alpha) + 2) * tan(beta / 2) / 4 - n * sin(alpha) / 2;
		cout << fixed << setprecision(20) << ans << endl;
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
