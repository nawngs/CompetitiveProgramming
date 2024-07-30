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
const int N = 1e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

struct Point {
	ll x, y;
	Point(ll x = 0, ll y = 0) : x(x), y(y) {}
	Point& operator -= (const Point &oth) {
		x -= oth.x; y -= oth.y; return *this;
	}
	Point& operator += (const Point &oth) {
		x += oth.x; y += oth.y; return *this;
	}
	Point operator - (const Point &oth) const {
		return Point(*this) -= oth;
	}
	Point operator + (const Point &oth) const {
		return Point(*this) += oth;
	}
};

ll dot (const Point &a, const Point &b) {
	return a.x * b.x + a.y * b.y;
}

ll cross (const Point &a, const Point &b) {
	return a.x * b.y - a.y * b.x;
}

ll orient(const Point &a, const Point &b, const Point &c) {
	return cross(b - a, c - a);
}

int n;

Point a[N + 3];

vector < Point > b, c;

bool check() {
	for (int i = 4; i <= n; i++) {
		if (orient(b[b.size() - 1], b[b.size() - 2], a[i]) == 0) b.pb(a[i]);
		else c.pb(a[i]);
	}
	for (int i = 2; i < b.size(); i++) if (orient(b[i - 2], b[i - 1], b[i]) != 0) return false;
	for (int i = 2; i < c.size(); i++) if (orient(c[i - 2], c[i - 1], c[i]) != 0) return false;
	return true;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i].x >> a[i].y;
	if (n <= 3) {
		cout << "YES" << '\n';
		return 0;
	}
	sort(a + 1, a + n + 1, [&](Point &x, Point &y) {
		return x.x < y.x;
	});
	for (int i = 1; i < 8; i++) if (__builtin_popcount(i) >= 2) {
		b.clear(); c.clear();
		for (int j = 0; j < 3; j++) {
			if (i >> j & 1) b.pb(a[j + 1]);
			else c.pb(a[j + 1]);
		}
		if (check()) {
			// for (auto x : b) cerr << x.x << " " << x.y << '\n';
			// cerr << '\n';
			// for (auto x : c) cerr << x.x << " " << x.y << '\n';
			return cout << "YES", 0;
		}
	}
	cout << "NO";
}