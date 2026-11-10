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

// Link problem: 


#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll l = 1, r = 2e9;

    while (l <= r) {
        ll mid = l + (r - l) / 2;

        cout << mid << endl; 
        string s;
        cin >> s;

        if (s == "HOLA") {
            return 0;
        }
        else if (s == "BIGGER") {
            l = mid + 1;
        }
        else if (s == "SMALLER") {
            r = mid - 1;
        }
    }

    return 0;
}

