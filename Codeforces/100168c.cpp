#include <bits/stdc++.h>

#define name "area"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

struct Point {
	int x, y;
	Point(int _x, int _y) {
		x = _x, y = _y;
	}
};

int n;

vector < Point > a;

double cross(Point x, Point y) {
	return x.x * y.y - y.x * x.y;
}

int main() {
	fast;
	if(fopen(name".in", "r")) {
		freopen(name".in", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, y; cin >> x >> y;
		a.pb(Point(x, y));
	}
	int res = 0;
	for (int i = 0; i < n; i++)
		res = (res + cross(a[i], a[(i + 1) % n]));
	if (res < 0) res = -res;
	cout << fixed << setprecision(5) << res / 2.0 << '\n';
}