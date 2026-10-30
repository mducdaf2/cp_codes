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

// Link problem: https://codeforces.com/problemset/problem/1472/D

#include <bits/stdc++.h> 
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc;  
    while (tc--) {
    	int n; cin >> n; 
    	vector<int> a(n);  
    	vector<int> even, odd; 
    	for (int i = 0; i < n; i++) {
    		cin >> a[i]; 
    	}


    	sort(a.begin(), a.end(), greater<int>());  
    	long long p1 = 0, p2 = 0; 
    	for (int i = 0; i < n; i++) {
    		if (i % 2 == 0) {
    			if (a[i] % 2 == 0) {
    				p1 += a[i]; 
    			}
    			// a.pop_back(); 
    		} else {
    			if (a[i] % 2 == 1) {
    				p2 += a[i]; 
    			}
    			// a.pop_back();
    		}
    	}

    	if (p1 > p2) {
    		cout << "Alice\n"; 
    	} else if (p1 < p2) {
    		cout << "Bob\n";
    	} else {
    		cout << "Tie\n";
    	}
    }
    return 0; 
}
