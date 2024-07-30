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
	Point& operator -= (Point const &oth) {
		x -= oth.x, y -= oth.x;
		return *this;
	}
	Point& operator += (Point const &oth) {
		x += oth.x, y += oth.x;
		return *this;
	}
	Point operator - (Point const &oth) const {
		return Point(*this) -= oth;
	}
	Point operator + (Point const &oth) const {
		return Point(*this) += oth;
	}
};

ld cross(Point const &a, Point const &b) {
	return a.x * b.y - a.y * b.x;
}

int n;

vector < Point > a;

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ld x, y; cin >> x >> y;
		a.pb({x, y});
	}
	ld res = 0;
	for (int i = 0; i < n; i++) res += cross(a[i], a[(i + 1) % n]);
	res = abs(res);
	cout << fixed << setprecision(9) << res / 2.0;
}