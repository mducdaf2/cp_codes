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

// Link problem: https://codeforces.com/problemset/problem/2271/C

#include <bits/stdc++.h> 
using namespace std;

int find(int n) {
	int x = 1;  
	while (x <= n) {
		x *= 2; 
	}
	return x; 
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--) {
    	int n; cin >> n;  

    	int x = find(n);


    	vector<int> a(2 * x), p(2 * x);
    	for (int i = 0; i <= x -1; i++) {
    		p[2 * i] = i; 
    		p[2 * i + 1] = i; 
    	}

    	for (int i = 1; i < 2*x; i++) {
    		a[i] = p[i-1] ^ p[i];
    	}

    	cout << 2*x - 1 << "\n";
    	for (int i = 1; i < 2*x; i++) cout << a[i] << " ";
		cout << "\n";
    }
    return 0; 
}
