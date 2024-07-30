#include <bits/stdc++.h>

#define int ll
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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

struct Point {
	int x, y;
	Point() {
		x = y = 0;
	}
	Point(int _x, int _y) : x(_x), y(_y) {}
};

int n;

using Polygon = vector < Point >;

Polygon a;

int dot(const Point &a, const Point &b) {
	return a.x * b.x + a.y * b.y;
}

int cross(const Point &a, const Point &b) {
	return a.x * b.y - a.y * b.x;
}

int orient(const Point &a, const Point &b, const Point &c) {
	Point vecab = {b.x - a.x, b.y - a.y}, vecbc = {c.x - b.x, c.y - b.y};
	return cross(vecab, vecbc);
}

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, y; cin >> x >> y;
		a.pb({x, y});
	}
	int q; cin >> q;
	while (q--) {
		Point p; cin >> p.x >> p.y;
		if (orient(a[0], p, a[1]) >= 0) {
			cout << "NO" << '\n';
			continue;
		}
		int l = 1, r = n - 1, mid, ans = -1;
		while (l <= r) {
			mid = (l + r) / 2;
			if (orient(a[0], p, a[mid]) > 0) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		if (ans == -1 || orient(a[ans - 1], p, a[ans]) >= 0) cout << "NO" << '\n';
		else cout << "YES" << '\n';
	}
}