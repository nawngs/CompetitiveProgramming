#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld ll
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int N = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

struct Point {
	ld x, y;
	Point(ld x = 0, ld y = 0) : x(x), y(y) {}
	Point operator + (const Point &oth) {
		return Point(x + oth.x, y + oth.y);
	}
	Point operator - (const Point &oth) {
		return Point(x - oth.x, y - oth.y);
	}
	Point operator * (const ld &d) {
		return Point(x * d, y * d);
	}
	Point operator / (const ld &d) {
		return Point(x / d, y / d);
	}
} A;
ld abs(const Point &x) {
	return sqrtl(x.x * x.x + x.y * x.y);
}

ld dot(const Point &x, const Point &y) {
	return x.x * y.x + x.y * y.y;
}

ld cross(const Point &x, const Point &y) {
	return x.x * y.y - x.y * y.x;
}

struct Line {
	Point v; ld c;
	Line(ld a, ld b, ld c) : v({b, -a}), c(c) {}
	Line(Point a, Point b) : v(b - a), c(cross(v, a)) {}
	ld side(const Point &x) {return cross(v, x) - c;}
	ld dis(const Point &x) { return abs(side(x)) / abs(v);}
};

bool inter(Line l1, Line l2, Point &x) {
	ld d = cross(l1.v, l2.v);
	if (d == 0) return false;
	x = (l2.v * l1.c - l1.v * l2.c) / d;
	return true;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	Line l(0, 0, 0); 
	cin >> A.x >> A.y >> l.v.y >> l.v.x;
	l.v.x *= -1;
	l.c = cross(l.v, A);
	cout << -l.v.y << " " << l.v.x << " " << -l.c << '\n';
}
