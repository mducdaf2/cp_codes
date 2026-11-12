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

// Link problem: https://qoj.ac/contest/3420/problem/17255

#include <bits/stdc++.h> 
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;  
    vector<long long> a(n), b(n), c(n); 
    for (int i = 0; i < n; i++) {
    	cin >> a[i] >> b[i];
    	c[i] = a[i] - b[i];
    }

    sort(c.begin(), c.end()); 
    int cnt_pos = 0; 
    deque<long long> dq;  
    for (int i = 0; i < n; i++) {
    	dq.push_back(c[i]);
    	cnt_pos += (c[i] >= 0) ? 1 : 0;
    }

    deque<long long> temp = dq;



    // for (int i = 0; i < n; i++) cout << c[i] << " ";
 
    if (n == 1) {
    	long long ans = max(a[0], b[0]) + max(-a[0], -b[0]);
    	cout << ans << "\n";
    	return 0;
    }

    vector<long long> s;
    long long ans = 0;

    long long ans1 = 0;  
    s.push_back(0);
	while (dq.size() > 1) {
	    long long n1 = dq.front();  
	    long long n2 = dq.back(); 
    	s.push_back(n1); 
    	s.push_back(n2);
    	dq.pop_front(); 
    	dq.pop_back(); 
	}
	if (dq.size() == 1) {
		s.push_back(dq.back());
		dq.pop_back();
	}
	s.push_back(0);
    for (int i = 1; i < s.size(); i++) {
    	ans1 += abs(s[i] - s[i-1]);
    }

    dq = temp;
    s.clear();
    long long ans2 = 0;  
    s.push_back(0);
	while (dq.size() > 1) {
	    long long n1 = dq.back();  
	    long long n2 = dq.front(); 
    	s.push_back(n1); 
    	s.push_back(n2);
    	dq.pop_front(); 
    	dq.pop_back(); 
	}
	if (dq.size() == 1) {
		s.push_back(dq.back());
		dq.pop_back();
	}
	s.push_back(0);
    for (int i = 1; i < s.size(); i++) {
    	ans2 += abs(s[i] - s[i-1]);
    }

    ans = max(ans1, ans2);
    cout << ans / 2 << "\n";
    return 0;

    long long n1 = dq.front();  
    long long n2 = dq.back(); 
    s.push_back(0);  
    if (abs(n1) > abs(n2)) {
    	while (dq.size() > 1) {
		    long long n1 = dq.front();  
		    long long n2 = dq.back(); 
	    	s.push_back(n1); 
	    	s.push_back(n2);
	    	dq.pop_front(); 
	    	dq.pop_back(); 
    	}
    	if (dq.size() == 1) {
    		s.push_back(dq.back());
    		dq.pop_back();
    	}
    } else if (abs(n1) < abs(n2)) {
    	while (dq.size() > 1) {
    		long long n1 = dq.back();  
		    long long n2 = dq.front(); 
	    	s.push_back(n1); 
	    	s.push_back(n2);
	    	dq.pop_front(); 
	    	dq.pop_back(); 
    	}
    	if (dq.size() == 1) {
    		s.push_back(dq.back());
    		dq.pop_back();
    	}
    } else {
    	if (cnt_pos > (n / 2)) {
	    	while (dq.size() > 1) {
	    		long long n1 = dq.back();  
			    long long n2 = dq.front(); 
		    	s.push_back(n1); 
		    	s.push_back(n2);
		    	dq.pop_front(); 
		    	dq.pop_back(); 
	    	}
	    	if (dq.size() == 1) {
	    		s.push_back(dq.back());
	    		dq.pop_back();
	    	}
    	} else {
	    	while (dq.size() > 1) {
			    long long n1 = dq.front();  
			    long long n2 = dq.back(); 
		    	s.push_back(n1); 
		    	s.push_back(n2);
		    	dq.pop_front(); 
		    	dq.pop_back(); 
	    	}
	    	if (dq.size() == 1) {
	    		s.push_back(dq.back());
	    		dq.pop_back();
	    	}	
    	}
    }
    s.push_back(0);

    // for (int i = 0; i < s.size(); i++) cout << s[i] << " ";


    for (int i = 1; i < s.size(); i++) {
    	ans += abs(s[i] - s[i-1]);
    }
    cout << ans / 2 << "\n";
    return 0; 
}
