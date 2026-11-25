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

// Link problem: https://codeforces.com/gym/106840/problem/C

#include <bits/stdc++.h> 
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while (t--) {
    	long long m, n; cin >> m >> n;
    	if (m == 0) {
    		if (n == 0) {
    			cout << "YES\n0 0 0\n"; 
    		} else {
    			cout << "NO\n";
    		}
    		continue;
    	}
     	long long b = n / m;
    	long long c = n % m;
    	if (b == m+1 && c == 0) {
    		b = m; c = m;
    	}
    	if (c > m || b > m) {
    		cout << "NO\n"; continue;
    	}
    	cout << "YES\n" << m << " " << b << " " << c << '\n'; 
    }
    return 0; 
}
