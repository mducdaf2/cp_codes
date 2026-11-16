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

// Link problem: https://codeforces.com/problemset/problem/1047/B

#include <bits/stdc++.h> 
using namespace std;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template <class T> 
struct Point {
    typedef Point P; 
    T x, y; 
    explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
    bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
    
    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    P operator*(T d) const { return P(d * x, d * y); }
    P operator/(T d) const { return P(x / d, y / d); }

    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P b, P c) const { return (b-*this).cross(c-*this); }

    T dist2() const { return x*x + y*y; }
    double dist() const { return sqrt((double)dist2()); }
    double angle() const { return atan2(y, x); }

    P unit() const { return *this / dist(); }
    P perp() const { return P(-y, x); }
    P normal() const { return perp().unit(); }

    P rotate(double a) const {
        return P(x*cos(a)-y*sin(a), x*sin(a)-y*cos(a)); 
    }

    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << ", " << p.y << ")"; 
    }
    friend istream& operator>>(istream& is, P& p) {
        return is >> p.x >> p.y;
    }
};

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  	int n; cin >> n;  
  	long long m = 0; 
  	for (int i = 0; i < n; i++) {
  		Point<long long> p; cin >> p;
  		m = max(m, p.x + p.y);
  	}  

  	cout << m << "\n";
    return 0; 
}
