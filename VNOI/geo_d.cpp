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
}X, Y, Z;

struct Line {
	ld A, B, C;
	Line(ld A = 0, ld B = 0, ld C = 0) : A(A), B(B), C(C) {}
	Line operator *= (const ld &x) {
		A *= x; B *= x; C *= x;
		return *this;
	}
};

Line create(const Point &a, const Point &b) {
	Line res; res.B = -1;
	if (b.y - a.y == 0) {
		res.A = 0; res.B = 1; res.C = -a.y;
		return res;
	}
	if (b.x - a.x == 0) {
		res.B = 0; res.C = -a.x; res.A = 1;
		return res;
	}
	res.C = (a.y * b.x + a.x * b.y) / (b.x - a.x);
	if (a.x != 0) res.A = (a.y - res.C) / a.x;
	else res.A = (b.y - res.C) / b.x;
	return res;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> X.x >> X.y >> Y.x >> Y.y >> Z.x >> Z.y;
	Line XY = create(X, Y), XZ = create(X, Z);
	cout << fixed << setprecision(9);
	// cout << XY.A << " " << XY.B << " " << XY.C << '\n';
	// cout << XZ.A << " " << XZ.B << " " << XZ.C << '\n';
	ld txy = sqrtl(XZ.A * XZ.A + XZ.B * XZ.B), txz = sqrtl(XY.A * XY.A + XY.B * XY.B);
	XY *= txy; XZ *= txz;
	// cout << XY.A << " " << XY.B << " " << XY.C << '\n';
	// cout << XZ.A << " " << XZ.B << " " << XZ.C << '\n';
	cout << XY.A - XZ.A << " " << XY.B - XZ.B << " " << XY.C - XZ.C;
	
}