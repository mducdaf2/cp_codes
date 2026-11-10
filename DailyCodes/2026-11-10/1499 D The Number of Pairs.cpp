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

// Link problem: https://codeforces.com/problemset/problem/1499/D

#include <bits/stdc++.h> 
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N = 2e7; 
    vector<int> seive(N+1, 0), val(N+1);
    for (int i = 2; i <= N; i++) {
    	if (seive[i] == 0) {
    		for (int j = i; j <= N; j+=i) {
    			seive[j] = i;
    		}
    	}
    }

    for (int i = 2; i <= N; i++) {
    	int j = i / seive[i];
    	val[i] = val[j] + (seive[i] != seive[j]);
    }

    auto cntK = [&](int k) -> int {
    	int res = 0;
    	// for (int i = 1; i * i <= k; i++) {
    	// 	if (k % i == 0) {
    	// 		res ++;
    	// 		if (k / i != i) res++;
    	// 	}
    	// }
    	int d = seive[k];  
    	while (d != k && k > 1) {
    		res++;  
    		if (d == 0) {
    			cout << "here";
    			break;
    		}
    		while (k % d == 0) k /= d; 
    		d = seive[k];
    	}
    	if (k > 1) res++;
    	return res; 
    };

    int tc; cin >> tc; while (tc--) {
    	int c, d, x; cin >> c >> d >> x;  
    	
    	vector<int> s; 
    	for (int i = 1; i * i <= x; i++) {
    		if (x % i == 0) {
    			s.push_back(i); 
    			if (x / i != i) s.push_back(x / i);
    		}
    	}

    	int ans = 0;
    	for (int i = 0; i < s.size(); i++) {
    		if ((x/s[i] + d) % c == 0) {
				// int c1 = cntK((x/s[i] + d) / c);
				int c1 = val[(x / s[i] + d) / c];
				ans += (1 << c1);
    		}
    	}

    	cout << ans << "\n";
    }
    return 0; 
}
