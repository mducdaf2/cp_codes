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

// Link problem: https://codeforces.com/problemset/problem/1458/A

#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;  

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;  

    vector<ll> a(n), b(m);  
    for (int i = 0; i < n; i++) cin >> a[i]; 

    for (int i = 0; i < m; i++) cin >> b[i];  

    ll t = 0;
	for (int i = 1; i < n; i++) {
		t = gcd(t, a[0] - a[i]);
	}

	vector<ll> ans(m); 
	for (int i = 0; i < m; i++) {
		ans[i] = gcd(a[0] + b[i], t);
	}

	for (ll i : ans) cout << i << " ";

    return 0; 
}
