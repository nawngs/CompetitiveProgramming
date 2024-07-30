#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
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
	Point operator + (Point oth) {return Point(x + oth.x, y + oth.y);}
	Point operator - (Point oth) {return Point(x - oth.x, y - oth.y);}
	Point operator * (ld oth) {return Point(x * oth, y * oth);}
} A, B, C, D;

ld dot(const Point &x, const Point &y) {
	return x.x * y.x + x.y * y.y;
}

ld cross(const Point &x, const Point &y) {
	return x.x * y.y - x.y * y.x;
}

ld orient(Point a, Point b, Point c) {
	return cross(b - a, c - a);
}

ld abs(Point x) {
	return sqrtl(x.x * x.x + x.y * x.y);
}

bool check() {
	ld oa = orient(C, D, A), ob = orient(C, D, B), oc = orient(A, B, C), od = orient(A, B, D);
	if (oa * ob < 0 && oc * od < 0) return true;
	return false;
}

struct Line {
	Point v; ld c;
	Line(Point a, Point b) : v(b - a), c(cross(v, a)) {}
	Line(ld a, ld b, ld c) : v(-b, a), c(c) {}
	ld side(const Point &x) {return cross(v, x) - c;}
	ld dis (const Point &x) {return abs(side(x)) / abs(v);}
};

ld solve(Point A, Point B, Point C) {
	if (dot(A - B, C - B) < 0) return abs(B - A);
	if (dot(A - C, B - C) < 0) return abs(C - A);
	Line l(B, C);
	return l.dis(A);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cout << fixed << setprecision(9);
	cin >> A.x >> A.y >> B.x >> B.y;
	cin >> C.x >> C.y >> D.x >> D.y;
	if (check()) cout << 0 << '\n';
	else {
		cout << min({solve(A, C, D), solve(B, C, D), solve(C, A, B), solve(D, A, B)});
	}
}