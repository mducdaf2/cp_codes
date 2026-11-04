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

// Link problem: https://codeforces.com/problemset/problem/630/I

#include <bits/stdc++.h> 
using namespace std;

long long power(long long a, long long b) {
	long long res = 1; 
	while (b > 0) {
		if (b % 2 == 1) {
			res *= a; 
		}
		a *= a; 
		b >>= 1; 
	}
	return res; 
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n; 

    long long res = (long long)4 * 2 * 3 * power(4, n-3);  
    if (n > 3) {
    	res += 4 * (n-3) * 9 * power(4, n-4);
    }
    cout << res;
    return 0; 
}
