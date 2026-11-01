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

// Link problem: https://codeforces.com/problemset/problem/489/B

#include <bits/stdc++.h> 
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;  
    vector<int> a(n);  
    for (int &i : a) cin >> i; 

    int m; cin >> m;  
    vector<int> b(m);  
    for (int &i : b) cin >> i; 

    sort(a.begin(), a.end());
	sort(b.begin(), b.end()); 

	int res = 0; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (abs(a[i] - b[j]) <= 1) {
				res ++;  
				b[j] = 1000; 
				break;
			}
		}
	}
	cout << res; 
    return 0; 
}
