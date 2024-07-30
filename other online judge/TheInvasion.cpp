#include <bits/stdc++.h>

#define name ""
#define ld long double
#define fi first 
#define se second
#define pint pair < int, int >
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
const int N = 2e4;
const int MOD = 1e9 + 7;
const int BASE = 2309;

struct Pt {
	int x, y, w, id;
	Pt(int x = 0, int y = 0, int w = 0, int id = 0) : x(x), y(y), w(w), id(id) {}
	Pt& operator -= (const Pt &oth) {
		x -= oth.x, y -= oth.y;
		return (*this);
	}
	Pt operator - (const Pt &oth) const {
		return Pt(*this) -= oth;
	}
} a[N + 3], p[N + 3];

int n, m, f[603][603];

int cross(const Pt &x, const Pt &y) {
	return x.x * y.y - x.y * y.x;
}

int orient(const Pt &a, const Pt &b, const Pt &c) {
	return cross(b - a, c - a);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i].x >> p[i].y;
		p[i].id = i; a[i] = p[i];
	}
	cin >> m;
	int aint = 0;
	for (int i = 1; i <= m; i++) {
		cin >> a[i + n].x >> a[i + n].y >> a[i + n].w;
		aint += a[i + n].w;
	}
	for (int i = 1; i <= n; i++) {
		sort(a + 1, a + n + m + 1, [&](Pt &x, Pt &y) {
			if (x.id == i) return true;
			if (y.id == i) return false;
			int temp = orient(p[i], x, y);
			if (temp == 0) return x.id < y.id;
			return temp > 0;
		});
		int v = 0;
		for (int j = 1; j <= n + m; j++) {
			if (a[j].id > 0) f[i][a[j].id] = v;
			v += a[j].w;
		}
	}
	int res = -INF;
	for (int i = 1; i <= n; i++)
	for (int j = i + 1; j <= n; j++)
	for (int k = j + 1; k <= n; k++) res = max(res, -2 * aint + f[i][j] + f[j][k] + f[k][i]);
	cout << res;
}