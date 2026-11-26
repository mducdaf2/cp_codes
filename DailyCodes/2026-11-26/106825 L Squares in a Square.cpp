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

// Link problem: https://codeforces.com/gym/106825/problem/L

#include <bits/stdc++.h> 
using namespace std;

const long long N = 2e9;
const int B = 1260;

vector<int> primes;
vector<int> seive(B+1, 0);
void preCal() {
	for (int i = 2; i <= B; i++) {
		if (seive[i] == 0) {
			primes.push_back(i);
			for (int j = i; j <= B; j+=i) seive[j] = i;
		}
	}
}

bool isSquare(long long n) {
	long long y = sqrtl(n);
	return y * y == n;
}

void solve() {
	long long n; cin >> n;
	long long r = n; 
	long long s = 1;
	for (int p : primes) {
		if (1LL * p * p > r) break;
		int e = 0;
		while (r % p == 0) {
			e++;
			r /= p;
		}
		if (e & 1) s *= p;
	}
	if (r != 1 && !isSquare(r)) s *= r;
	// cout << "s = " << s << '\n';
	long long m = n / s;
	m = sqrt(m);
	if (m < 2) {
		cout << "0 0\n";
	} else {
		cout << s * s * m * m << " " << s * s * m * m * 4 << "\n";
	}

}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	// long long B = 1000;  
	// while (B * B * B <= N) B++;

	// cout << B;
    preCal();
    // cout << sqrt(N * N);
    int tc; cin >> tc; while (tc--) {
    	solve();
    }
    return 0; 
}
