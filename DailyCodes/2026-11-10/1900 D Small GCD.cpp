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

// Link problem: https://codeforces.com/problemset/problem/1900/D

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
    	int n; cin >> n;  
    	vector<int> a(n);  
    	for (int i = 0; i < n; i++) cin >> a[i];  

    	sort(a.begin(), a.end());  

    	long long ans = 0;

    	// Brute force 
    	// for (int i = 0; i < n-2; i++) {
    	// 	for (int j = i + 1; j < n-1; j++) {
    	// 		for (int k = j + 1; k < n; k++) {
    	// 			vector<int> s = {a[i], a[j], a[k]};
    	// 			sort(s.begin(), s.end()); 
    	// 			ans += gcd(s[0], s[1]);
    	// 		}
    	// 	}
    	// }



    	// for (int i = 0; i < n-2; i++) {
    	// 	for (int j = i+1; j < n-1; j++) {
    	// 		int k = n - j - 1;
    	// 		ans += gcd(a[i], a[j]) * k; 
    	// 	}
    	// }

        int M = 0;  
        for (int i : a) M = max(M, i);  

        vector<vector<int>> div(M+1);
        for (int i = 0; i < n; i++) {
            int x = a[i];
            for (int d = 1; d * d <= x; d++) {
                if (x % d == 0) {
                    div[d].push_back(i);
                    if (x / d != d) div[x / d].push_back(i); 
                }
            }
        }

        vector<long long> G(M+1, 0);
        for (int d = M; d >= 1; d--) {
            // int cnt = 0; 
            for (int i = 0; i < div[d].size(); i++) {
                G[d] += i * (n - div[d][i] - 1);
            }
            for (int k = 2; k * d <= M; k++) {
                G[d] -= G[k * d];
            }
        }
        // long long ans = 0;
        for (int d = 1; d <= M; d++) {
            ans += d * G[d];
        }
    	cout << ans << "\n";
    }

    return 0; 
}
