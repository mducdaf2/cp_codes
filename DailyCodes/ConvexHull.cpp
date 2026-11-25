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

// Link problem: https://open.kattis.com/problems/convexhull

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

typedef Point<int> P;

bool compPolar(P a, P b) {
    if (b == P(0, 0)) return false;
    if (a == P(0, 0)) return true;

    if (a.angle() != b.angle())
        return a.angle() < b.angle();

    return a.dist2() < b.dist2();
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (true) {
        int n; cin >> n;
        if (n == 0) break; 

        vector<P> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        P p0 = v[0];
        for (int i = 0; i < n; i++) {
            if (p0.y > v[i].y) {
                p0 = v[i];
            } else if (p0.y == v[i].y && p0.x > v[i].x) {
                p0 = v[i];
            }
        }

        // vector<bool> check(n, false);

        vector<P> hull;
        // hull.push_back(p0);
        for (int i = 0; i < n; i++) {
            v[i] = v[i] - p0;
            // if (v[i] == P(0, 0)) check[i] = true; 
        }

        sort(v.begin(), v.end(), compPolar);
        // for (P u : v) cout << u << "\n";
        hull.push_back(v[0]);
        for (int i = 1; i < n; i++) {
            P cur = v[i];
            if (hull.back() == cur) continue;
            if (hull.size() < 2) {
                hull.push_back(cur);
                continue;
            } 

            while (hull.size() >= 2) {
                P mid = hull.back();
                P prev = hull[hull.size() - 2];
                if ((mid - prev).cross(cur - mid) <= 0) {
                    hull.pop_back();
                    // hull.push_back(cur);
                } else {
                    break;
                    // hull.push_back(cur);
                }
            }
            hull.push_back(cur);
        }
        cout << hull.size() << '\n';
        for (P p : hull) {
            cout << p.x + p0.x << " " << p.y + p0.y << '\n';
        }
    }


    return 0; 
}
