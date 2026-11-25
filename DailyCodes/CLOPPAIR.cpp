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

// Link problem: https://www.spoj.com/problems/CLOPPAIR/

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

typedef Point<long long> P;
const int INF = 1e9;


int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;

    vector<P> points(n);
    for (int i = 0; i < n; i++) {
    	cin >> points[i];
    }

    map<P, int> m;
    for (int i = 0; i < n; i++) {
    	m[points[i]] = i;
    }

    sort(points.begin(), points.end());

    long long ans = (points[0] - points[1]).dist2();
    // long l ans = 2 * INF;
    auto comp1 = [](P p1, P p2) { return tie(p1.y, p1.x) < tie(p2.y, p2.x); };
    set<P, decltype(comp1)> s(comp1);

    P a1 = points[0], a2 = points[1];

    for (int i = 0; i < n; i++) {
    	P p = points[i];
    	long double d = sqrt((long double)ans);
    	P f = P(-INF, p.y - d);
    	while (true) {
    		auto it = s.upper_bound(f);

    		if (it == s.end()) break;

    		f = *it;
    		if (f.y > p.y + d) break;

    		if (f.x < p.x - d) {
    			s.erase(it);
    			continue;
    		}

    		if ((p-f).dist2() < ans) {
    			ans = (p-f).dist2();
    			d = sqrt((long double)ans);
    			a1 = p;
    			a2 = f;
    		}
    	}
    	s.insert(p);
    }

    int id1 = m[a1]; int id2 = m[a2];
    if (id1 > id2) swap(id1, id2);

    cout << id1 << " " << id2 << " ";
    cout << fixed << setprecision(6) << sqrt((long double)ans);
    return 0; 
}
