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

// Link problem: https://codeforces.com/contest/2185/problem/D

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
    int tc; cin >> tc; while (tc--) {
    	int n, m, h; cin >> n >> m >> h; 
    	vector<int> a(n); 
    	for (int &i : a) cin >> i;

    	vector<int> ori = a;
    	vector<int> last_update(n, -1);
    	int last_reset = -1; 

   		for (int i = 0; i < m; i++) {
   			int b, c; cin >> b >> c; 
   			b--;

   			if (last_update[b] < last_reset) a[b] = ori[b]; 
   			a[b] += c; 
   			if (a[b] > h) {
   				last_reset = i; 
   				a[b] = ori[b];
   			}
   			last_update[b] = i;
   		}	
    
    	for (int i = 0; i < n; i++) {
    		if (last_update[i] < last_reset) a[i] = ori[i]; 
    		cout << a[i] << " ";
    	}
    	cout << "\n";
    }
    return 0; 
}
