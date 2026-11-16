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

// Link problem: https://codeforces.com/contest/2290/problem/D

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
    	string s; cin >> s;  
    	vector<pair<int, int>> p; 
    	for (int i = 0; i < (int) n / 2; i++) {
    		int a = s[i] - 'a'; 
    		int b = s[n-i-1] - 'a';
    		pair<int, int> x; 
    		x.first = max(a, b); 
    		x.second = min(a, b);
    		p.push_back(x);
    	}
    	if (n % 2 == 1) {
    		int x = s[n / 2] - 'a';
    		p.push_back({x, x});
    	}
    	sort(p.begin(), p.end());
    	reverse(p.begin(), p.end()); 
    	int ans = p[0].first - p[0].second; 
    	int last = p[0].second;
    	for (int i = 1; i < p.size(); i++) {
    		if (last < p[i].first) {
    			ans += max(0, (last - p[i].second)); 
    			last = min(last, p[i].second);
    		} else {
    			ans += (p[i].first - p[i].second); 
    			last = p[i].second;
    		}
    	}
    	cout << ans << endl;
    }
    return 0; 
}
