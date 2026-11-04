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

// Link problem: https://codeforces.com/contest/1349/problem/A

#include <bits/stdc++.h> 
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int tc; cin >> tc; while (tc--) {

    // }

    int n; cin >> n;  
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i]; 
    }

    vector<long long> pre(n, 0), suf(n, 0);
    pre[0] = a[0];
    for (int i = 1; i < n; i++) {
    	pre[i] = gcd(pre[i-1], a[i]);
    }

    suf[n-1] = a[n-1];
    for (int i = n-2; i >= 0; i--) {
    	suf[i] = gcd(suf[i+1], a[i]);
    }

    long long ans = suf[1] * pre[n-2] / gcd(suf[1], pre[n-2]); 
    for (int i = 1; i < n-1; i++) {
    	long long gd = gcd(pre[i-1], suf[i+1]); 
    	ans = ans * gd / gcd(gd, ans);
    }
    cout << ans;
    return 0; 
}
