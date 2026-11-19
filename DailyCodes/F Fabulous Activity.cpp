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

// Link problem: https://qoj.ac/contest/4538/problem/22833

#include <bits/stdc++.h> 
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long double n, x0, y0, a, b; cin >> n >> x0 >> y0 >> a >> b;  
    long double len = sqrt(a * a + b * b);
    // vector<long long> dp(n+2, 0);
    // dp[0] = 1; dp[0] = 0;
    // for (int i = 2; i <= n+1; i++) {
    // 	dp[i] = dp[i-1] + dp[i-2];
    // }

    cout << fixed << setprecision(10) << n * len / 2 << endl;
    return 0; 
}
