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

// Link problem: https://codeforces.com/contest/2290/problem/C

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
    	map<int, int> cnt;
    	for (int i = 0; i < n; i++) {
    		int x; cin >> x;  
    		cnt[x]++;
    	}
    	long long ans = 0; 
    	vector<int> left, right;
    	for (auto [k, v] : cnt) {
    		if (v >= 2) {
    			ans += 2; 
    			left.push_back(k);
    			for (int i = 0; i < v-1; i++) {
    				right.push_back(k);
    			}
    		} else if (v == 1) {
    			ans++;
    			left.push_back(k);
    		}
    	}
    	cout << ans << endl;
    	reverse(right.begin(), right.end()); 
    	vector<int> res; 
    	for (int i : left) res.push_back(i);
    	for (int i : right) res.push_back(i);

    	for (int i : res) cout << i << " ";
    	cout << endl;
    }
    return 0; 
}
