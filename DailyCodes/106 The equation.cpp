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

// Link problem: https://codeforces.com/problemsets/acmsguru/problem/99999/106

#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

ll extEuclid(ll a, ll b, ll &x, ll &y) {
	if (b == 0) {
		x = 1; 
		y = 0; 
		return a; 
	}

	ll q = a / b;
	ll r = a - b * q; 
	ll x1 = 0, y1 = 0;
	ll d = extEuclid(b, r, x1, y1); 
	x = y1; 
	y = x1 - q * y1;
	return d; 
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b, c; cin >> a >> b >> c;
    ll x1, x2; cin >> x1 >> x2; 
    ll y1, y2; cin >> y1 >> y2;

    if (a == 0 && b == 0) {
    	if (c == 0) {
    		cout << (x2 - x1 + 1) * (y2 - y1 + 1) << "\n";
    	} else {
	    	cout << "0\n"; 
    	}
	    return 0;    		 
    } 

    if (a == 0) {
    	if (c % b == 0) {
    		ll y = c / b; 
    		if (y1 <= y && y <= y2) {
    			cout << x2 - x1 + 1 << "\n";
    		} else {
    			cout << "0\n";
    		}
    	} else {
    		cout << "0\n";
    	}
    	return 0;
    }

    if (b == 0) {
    	if (c % a == 0) {
    		ll x = c / a; 
    		if (x1 <= x && x <= x2) {
    			cout << y2 - y1 + 1 << "\n";
    		} else {
    			cout << "0\n";
    		}
    	} else {
    		cout << "0\n";
    	}
    	return 0;
    }

    if (c > 0) {
    	a = -a; 
    	b = -b;
    } else {
    	c *= -1;
    }

    ll sa = a > 0 ? 1 : -1;
    ll sb = b > 0 ? 1 : -1;

    a = abs(a); 
    b = abs(b);
    
    ll x0 = 0, y0 = 0; 
    ll d = extEuclid(a, b, x0, y0);



    // cout << d;
    // cout << x0 << " " << y0;
    
    if (c % d != 0) {
    	cout << 0 << "\n";
    	return 0;
    }

    x0 = (ll)x0 * sa * c / d; 
    y0 = (ll)y0 * sb * c / d; 

    // cout << x0 << " " << y0;

    ll t1 = sa * b / d; 
    ll t2 = sb * a / d;  

    ll k1 = (x1 - x0) / t1; 
    ll k2 = (x2 - x0) / t1; 

    ll L = min(k1, k2); 
    ll R = max(k1, k2); 


    ll ans = 0;
    for (int k = L; k <= R; k++) {
    	ll x = x0 + k * t1; 
    	ll y = y0 - k * t2; 
    	if (x1 <= x && x <= x2 && y1 <= y && y <= y2) {
    		ans++;
    	}
    }
    cout << ans;


    return 0; 
}
