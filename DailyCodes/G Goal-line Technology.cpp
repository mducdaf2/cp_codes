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

// Link problem: https://qoj.ac/contest/4538/problem/22834

#include <bits/stdc++.h> 
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, r, x1, x2; cin >> n >> r >> x1 >> x2;
    vector<int> p(n); 
    for (int i = 0; i < n; i++) cin >> p[i];

    sort(p.begin(), p.end());
	
	if (x1 < x2) {
		if (p[0] + r <= x1) {
			cout << "GOAL\n";
		} else {
			cout << "NO GOAL\n";
		}
	} else {
		if (p[n-1] - r >= x1) {
			cout << "GOAL\n";
		} else {
			cout << "NO GOAL\n";
		}
	}

    return 0;
}
