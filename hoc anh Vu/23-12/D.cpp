#include <bits/stdc++.h>

#define name ""
#define test "test"
#define ll long long
#define double long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const double EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;
const double PI = 3.14159265358979323846;
int n;

struct Point {
	double x, y;
	Point(double x = 0, double y = 0) : x(x), y(y) {}
	bool operator == (const Point &oth) {
		return x == oth.x && y == oth.y;
	}
} a[1503];

struct Line { // ax + b = y
	double a, b, y;
	Line(double a = 0, double b = 0, double y = 0) : a(a), b(b), y(y) {}
};

struct Data {
	double len;
	Point midpoint;
	Line equa;
	bool operator == (const Data &oth) {
		return len == oth.len && midpoint == oth.midpoint;
	}
};

double calc_dis(const Point &x, const Point &y) {
	return sqrtl((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y));
}

Point calc_mid(const Point &x, const Point &y) {
	Point res;
	res.x = (x.x + y.x) / 2;
	res.y = (x.y + y.y) / 2;
	return res;
}

Line calc_line(const Point &x, const Point &y) {
	Line res;
	double a1, a2, b, c1, c2, val1, val2;
	a1 = x.x, a2 = y.x;
	c1 = x.y, c2 = y.y;
	val1 = a2;
	val2 = a1;
	a1 *= val1, c1 *= val1;
	a2 *= val2, c2 *= val2;
	b = (c1 - c2) / (val1 - val2);
	a1 = a1 / val1;
	res.a = a1; res.b = b;
	return res;
}

double arctan(double val) {
	double res = atan(val);
	if (res < 0) res += PI;
	return res; 
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
	calc_line(a[1], a[2]);
	vector < Data > temp;
	for (int i = 1; i <= n; i++) 
		for (int j = i + 1; j <= n; j++) {
			Data val;
			val.len = calc_dis(a[i], a[j]);
			val.midpoint = calc_mid(a[i], a[j]);
			val.equa = calc_line(a[i], a[j]);
			temp.push_back(val);
			cout << val.len << " " << val.midpoint.x << " " << val.midpoint.y << " " << val.equa.a << " " << val.equa.b << '\n';
		}
	sort(temp.begin(), temp.end(),[&](Data &x, Data &y) {
		if (x.len != y.len) return x.len <= y.len;
		if (x.midpoint.x != y.midpoint.x) return x.midpoint.x < y.midpoint.x;
		return x.midpoint.y < y.midpoint.y;
	});
	vector < Data > cur;
	vector < double > positive, negative; // he so goc duong, he so goc am (a > 0, a < 0)
	set < double > rev;
	cur.push_back(temp[0]);
	double area = 0;
	for (int i = 1; i < sz(temp); i++) {
		auto x = temp[i];
		if (x == temp[i - 1]) cur.push_back(x);
		else {
			//##############################################################################
			positive.clear(); negative.clear();
			bool parallel = 0;
			double hypotenuse = cur[0].len;
			for (auto l : cur) {
				if (l.equa.a == 0) parallel = 1;
				else if (l.equa.a > 0) positive.push_back(arctan(l.equa.a));
				else negative.push_back(arctan(l.equa.a));
			}
			double res = -1;
			if (parallel) {
				for (auto x : positive) res = max(res, x);
				for (auto x : negative) res = max(res, PI - x);
			}
			rev.clear();
			for (auto x : positive) rev.insert(PI - x);
			for (auto x : positive) {
				rev.erase(PI - x);
				if (rev.size()) res = max(res, PI - x - *rev.begin());
				rev.insert(PI - x);
			}
			rev.clear();
			for (auto x : negative) rev.insert(PI - x);
			for (auto x : negative) {
				rev.erase(PI - x);
				if (sz(rev)) res = max(res, PI - x - *rev.begin());
				rev.insert(PI - x);
			}
			for (auto &x : negative) 
				x = PI - x;
			sort(negative.begin(), negative.end());
			for (auto x : positive) {
				int l = 0, r = sz(negative) - 1, mid;
				double ans = -1;
				while (l <= r) {
					mid = (l + r) / 2;
					if ((x + negative[mid]) * 2.0 <= PI) {
						ans = negative[mid];
						l = mid + 1;
					}
					else r = mid - 1;
				}
				if (ans != -1) res = max(res, x + ans);
				l = 0, r = sz(negative) - 1, ans = -1;
				while (l <= r) {
					mid = (l + r) / 2;
					if ((x + negative[mid]) * 2.0 >= PI) {
						ans = negative[mid];
						r = mid - 1;
					}
					else l = mid + 1;
				}
				if (ans != -1) res = max(res, PI - x - ans);
			}
			if (res != -1) {
				double angle = PI / 2 - res / 2;
				double ab = sin(angle) * hypotenuse;
				double ac = sqrtl(hypotenuse * hypotenuse - ab * ab);
				area = max(area, ab * ac);
			}
			//##############################################################################
			cur.clear();
			cur.push_back(x);
		}
	}
	positive.clear(); negative.clear();
	bool parallel = 0;
	double hypotenuse = cur[0].len;
	for (auto l : cur) {
		if (l.equa.a == 0) parallel = 1;
		else if (l.equa.a > 0) positive.push_back(arctan(l.equa.a));
		else negative.push_back(arctan(l.equa.a));
	}
	double res = -1;
	if (parallel) {
		for (auto x : positive) res = max(res, x);
		for (auto x : negative) res = max(res, PI - x);
	}
	rev.clear();
	for (auto x : positive) rev.insert(PI - x);
	for (auto x : positive) {
		rev.erase(PI - x);
		if (sz(rev)) res = max(res, PI - x - *rev.begin());
		rev.insert(PI - x);
	}
	rev.clear();
	for (auto x : negative) rev.insert(PI - x);
	for (auto x : negative) {
		rev.erase(PI - x);
		if (sz(rev)) res = max(res, PI - x - *rev.begin());
		rev.insert(PI - x);
	}
	for (auto &x : negative) 
		x = PI - x;
	sort(negative.begin(), negative.end());
	for (auto x : positive) {
		int l = 0, r = sz(negative) - 1, mid;
		double ans = -1;
		while (l <= r) {
			mid = (l + r) / 2;
			if ((x + negative[mid]) * 2.0 <= PI) {
				ans = negative[mid];
				l = mid + 1;
			}
			else r = mid - 1;
		}
		cout << x << ' ' << ans << '\n';
		if (ans != -1) res = max(res, x + ans);
		l = 0, r = sz(negative) - 1, ans = -1;
		while (l <= r) {
			mid = (l + r) / 2;
			if ((x + negative[mid]) * 2.0 >= PI) {
				ans = negative[mid];
				r = mid - 1;
			}
			else l = mid + 1;
		}
		cout << x << " " << ans << '\n';
		if (ans != -1) res = max(res, PI - x - ans);
	}
	cout << res << '\n';
	if (res != -1) {
		double angle = PI / 2.0 - res / 2.0;
		double ab = sin(angle) * hypotenuse;
		double ac = sqrtl(hypotenuse * hypotenuse - ab * ab);
		area = max(area, ab * ac);
	}
	cout << fixed << setprecision(0) << area;
}