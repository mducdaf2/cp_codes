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

// Link problem: https://qoj.ac/contest/4538/problem/22837

#include <bits/stdc++.h> 
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (true)  {
    	string s; cin >> s;
    	if (s == "$") break;  
	    int n = s.size();
	    vector<long long> dp1(n+1, 0);
	    vector<long long> dp2(n+1, 0);
	    vector<long long> dp3(n+1, 0);
	    vector<long long> dp4(n+1, 0);

	    for (int i = 1; i <= n; i++) {
	    	if (i <= 2) {
	    		if (s[i-1] == 'I') {
	    			dp1[i] = dp1[i-1] + 1;
	    		} else {
	    			dp1[i] = dp1[i-1];
	    		}
	    		continue;
	    	}
    		dp1[i] = dp1[i-1];
    		dp2[i] = dp2[i-1];
    		dp3[i] = dp3[i-1];
    		dp4[i] = dp4[i-1];
	    	if (s[i-1] == 'I') {
	    		dp1[i] += 1;
	    	} else if (s[i-1] == 'C') {
	    		dp2[i] += dp1[i-2];
	    		dp4[i] += dp3[i-2];
	    	} else if (s[i-1] == 'P') {
	    		dp3[i] += dp2[i-2];
	    	} 
	    }

	    cout << dp4[n] << endl;
    }

    return 0; 
}
