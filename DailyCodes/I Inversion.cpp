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

// Link problem: https://qoj.ac/contest/4538/problem/22836

#include <bits/stdc++.h> 
using namespace std;

long long query(int i, int j) {
	cout << "? " << i << " " << j << endl;
	long long k; cin >> k;
	return k;
}

int main(){
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;

    long long S0 = query(1, 1);
    vector<int> p;
    p.push_back(1);
    for (int i = 2; i <= n; i++) {
    	long long S = query(1, i);
    	long long diff = S - S0;
    	// cerr << diff << " - ";
    	int pos1 = 0;
    	while (p[pos1] != 1) pos1++;

 		int index = (diff + 1 + 2 * pos1) / 2;
 		p.insert(p.begin() + index, i);
    }
    vector<int> ans(n+1, 0);
    for (int i = 1; i <= n; i++) {
    	ans[p[i-1]] = i;
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) {
    	cout << ans[i] << (i == n ? "" : " "); 
    }
    cout << endl;
    return 0; 
}
