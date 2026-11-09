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

// Link problem: https://icpc.vnoi.info/problem/icpcna2025_i

#include <bits/stdc++.h> 
using namespace std;


typedef long long ll; 

const ll M = 998244353;

typedef pair<ll, ll> P; 
#define f first  
#define s second 

ll power(ll a, ll b) {
	ll res = 1; 
	while (b > 0) {
		if (b % 2 == 1) res = res * a % M;  
		a = a * a % M; 
		b >>= 1; 
	}
	return res; 
}

struct T {
	ll a11, a12, a21, a22;
	ll b1, b2; 

	P apply(P A) {
		P ans; 
		auto [x, y] = A; 
		x = (x + M) % M;  
		y = (y + M) % M; 
		ans.f = ((a11 * x) % M + (a12 * y) % M + b1) % M; 
		ans.s = ((a21 * x) % M + (a22 * y) % M + b2) % M; 
		return ans;
	}

	T merge(const T &o) const {
		T ans;
		ans.a11 = ((o.a11 * a11) % M + (o.a12 * a21) % M) % M;
		ans.a12 = ((o.a11 * a12) % M + (o.a12 * a22) % M) % M;
		ans.a21 = ((o.a21 * a11) % M + (o.a22 * a21) % M) % M;
		ans.a22 = ((o.a21 * a12) % M + (o.a22 * a22) % M) % M;

		ans.b1 = ((o.a11 * b1) % M + (o.a12 * b2) % M + o.b1) % M;
		ans.b2 = ((o.a21 * b1) % M + (o.a22 * b2) % M + o.b2) % M;
		return ans;
	}
};

T no_change() {
	T I; 
	I.a11 = 1;  I.a12 = 0;  
	I.a21 = 0;	I.a22 = 1;  
	I.b1 = 0; 	I.b2 = 0;  
	return I;
}

T convert(char m, ll a, ll b, ll c) {
	T ans; 
	a = (a + M) % M; 
	b = (b + M) % M; 
	c = (c + M) % M; 

	ll temp = (a * a % M + b * b % M) % M;
	temp = power(temp, M - 2); 
	if (m == 'G') {
		ans.a11 = b * b % M * temp % M; 
		ans.a12 = (-a + M) % M * b % M * temp % M; 
		ans.b1 = (-a + M) % M * c % M * temp % M;

		ans.a21 = ans.a12; 
		ans.a22 = a * a % M * temp % M; 
		ans.b2 = (-b + M) % M * c % M * temp % M;
	} else {
		ans.a11 = (b * b % M - a * a % M + M) % M * temp % M; 
		ans.a12 = 2 * (-a + M) % M * b % M * temp % M; 
		ans.b1 = 2 * (-a + M) % M * c % M * temp % M;

		// ans.a21 = a * a % M * temp % M; 
		ans.a21 = ans.a12; 
		ans.a22 = (-ans.a11 + M) % M;
		ans.b2 = 2 * (-b + M) % M * c % M * temp % M;
	}
	return ans;
}

const int MAXN = 2e5+5;
T tree[4 * MAXN];
T arr[MAXN];

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = tree[2 * node].merge(tree[2 * node + 1]);
}

void update(int node, int start, int end, int idx, T val) {
    if (start == end) {
        tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid)
        update(2 * node, start, mid, idx, val);
    else
        update(2 * node + 1, mid + 1, end, idx, val);
    tree[node] = tree[2 * node].merge(tree[2 * node + 1]);
}

T query(int node, int start, int end, int l, int r) {
    if (r < start || end < l)
        return no_change(); 
    if (l <= start && end <= r)
        return tree[node];
    
    int mid = (start + end) / 2;
    T p1 = query(2 * node, start, mid, l, r);
    T p2 = query(2 * node + 1, mid + 1, end, l, r);
    return p1.merge(p2);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
    	char m; ll a, b, c; 
    	cin >> m >> a >> b >> c; 
    	T p = convert(m, a, b, c);
    	arr[i] = p;
    }

    build(1, 1, n);

    while (q--) {
    	int type; cin >> type;
    	if (type == 1) {
	    	char m; int j; ll a, b, c; 
	    	cin >> j >> m >> a >> b >> c;
	    	T p = convert(m, a, b, c); 
	    	update(1, 1, n, j, p); 
    	} else {
    		P point; ll l, r;
    		cin >> point.f >> point.s >> l >> r;
    		T trans = query(1, 1, n, l, r); 
    		P ans = trans.apply(point);
    		cout << ans.f << " " << ans.s << "\n";
    	}
    }

    return 0; 
}
