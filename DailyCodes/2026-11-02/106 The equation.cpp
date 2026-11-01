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

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, c; cin >> a >> b >> c;  
    int x1, x2, y1, y2; cin >> x1 >> x2 >> y1 >> y2;  

    if (a == 0 && b == 0) {
    	if (c != 0) {
    		cout << "0\n"; 
    	} else {
    		cout << (x2 - x1 + 1) * (y2 - y1 + 1) << "\n";
    	}
    	return ;
    }
    int d = gcd(a, b); 
    return 0; 
}
