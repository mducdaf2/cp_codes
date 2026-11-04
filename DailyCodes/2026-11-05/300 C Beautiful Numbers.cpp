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

// Link problem: https://codeforces.com/problemset/problem/300/C

#include <bits/stdc++.h> 
using namespace std;

const int M = 1e9+7;
const int N = 1e6; 
long long fact[N+1], invfact[N+1];

long long power(long long a, long long b) {
	long long res = 1; 
	while (b > 0) {
		if (b % 2 == 1) {
			res = res * a % M; 
		}
		a = a * a % M; 
		b /= 2; 
	}
	return res; 
}

bool check(int p, int a, int b) {
	while (p > 0) {
		int m = p % 10;
		if (m != a && m != b) {
			return false;
		}
		p /= 10;
	}
	return true;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fact[0] = 1; 
    for (int i = 1; i <= N; i++) {
    	fact[i] = (fact[i-1] * i) % M;
    }

    invfact[N] = power(fact[N], M-2); 
    for (int i = N; i > 0; i--) {
    	invfact[i-1] = (invfact[i] * i) % M;
    }
    // int p = 10;
    // int q = 2;
    // cout << (fact[p] * invfact[q] % M) * invfact[p-q] % M; 
    int a, b, n; cin >> a >> b >> n;
    long long ans = 0;
    for (int x = 0; x <= n; x++) {
    	int p = n * a + (b - a) * x;
    	if (check(p, a, b)) {
    		ans = ans + (fact[n] * invfact[x] % M) * invfact[n-x] % M; 
    		ans %= M; 
    	}
    }
    cout << ans;
    return 0; 
}
