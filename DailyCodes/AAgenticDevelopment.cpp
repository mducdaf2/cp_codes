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

// Link problem: https://pc2pnwonline.icpc-vcss.org/problems/A-Agenticdevelopment-1/A-Agenticdevelopment-1.pdf

#include <bits/stdc++.h> 
using namespace std;

struct Task {
	int t, s, f, c; 

	long double T, P, comp;
	Task(int t, int s, int f, int c) : t(t), s(s), f(f), c(c) {
		long double total = s + f + c;
		if (total == 0) return;
		long double sucess, fail, corrupt;
		sucess = (long double)s / total;
		fail = (long double)f / total;
		corrupt = (long double)c / total;

		T = (long double)t / (1 - fail);
		P = sucess / (1 - fail);
		comp = T / (1 - P);
	}
};

bool comp1(const Task& a, const Task& b) {
    if (a.c == 0) return false;
    if (b.c == 0) return true;

    return a.comp < b.comp;
}

void solve() {
	int n; cin >> n;
	vector<Task> v;
	bool check = false;
	for (int i = 0; i < n; i++) {
		int t, s, f, c;
        cin >> t >> s >> f >> c;
		v.push_back(Task(t, s, f, c));
		if (s == 0) {
			check = true;
			// return;
		}
	}
	if (check) {
		cout << "impossible\n";
		return;
	}
	sort(v.begin(), v.end(), comp1);
	long double P = 1;
	long double ans = 0;
	for (int i = 0; i < n; i++) {
		ans += P * v[i].T;
		P *= v[i].P;
	}
	// long double mauso = 
	ans /= P;
	cout << fixed << setprecision(20) << ans << endl;
}

int main(){
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc; while (tc--) {
    	solve();
    }
    return 0; 
}
