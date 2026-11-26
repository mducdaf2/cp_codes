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

// Link problem: https://codeforces.com/gym/106840/problem/A

#include <bits/stdc++.h> 
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, k, a, b, l, m; cin >> n >> k >> a >> b >> l >> m;
	m = m - k * a - b * (n - k) - l * a;
	cout << (m < 0 ? "NO\n" : "YES\n");	
    return 0; 
}
