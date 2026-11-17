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

// Link problem: https://codeforces.com/contest/2290/problem/E

#include <bits/stdc++.h> 
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--) {
    	int n, k; cin >> n >> k;  
    	vector<int> a(n+1);
    	for (int i = 0; i < n; i++) cin >> a[i+1];

    	// vector<int> w(n+1); 
    	// w[1] = 1; 
    	// for (int i = 2; i <= n; i++) {
    	// 	w[i] = 1;
    	// 	for (int j = max(1, i-k); j <= i-1; j++) {
    	// 		w[i] = (w[i] + w[j]) % 2;
    	// 	}
     	// }

     	// int W = 0;
     	// for (int i = 1; i <= n; i++) {
     	// 	W += w[i] * a[i] % 2;
     	// 	W %= 2;
     	// }

        int W = 0;
        for (int i = 1; i <= n; i++) {
            W += (i % (k+1) == 1) ? (a[i] % 2) : 0;
        } 

     	cout << (W % 2 == 1 ? "Alice" : "Bob") << endl;
    }
    return 0; 
}
