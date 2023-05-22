#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Point {
    ll x, y;

    Point(ll x = 0, ll y = 0): x(x), y(y) {}

    Point& operator += (const Point &o) {
        x += o.x; y += o.y; return *this;
    }

    Point& operator -= (const Point &o) {
        x -= o.x; y -= o.y; return *this;
    }

    Point& operator *= (const ll &k) {
        x *= k; y *= k; return *this;
    }

    bool operator != (const Point &o) const {
        return x != o.x || y != o.y;
    }

    bool operator == (const Point &o) const {
        return x == o.x && y == o.y;
    }

    Point operator + (const Point &o) const {
        return Point(*this) += o;
    }

    Point operator - (const Point &o) const {
        return Point(*this) -= o;
    }

    Point operator * (const ll &k) const {
        return Point(*this) *= k;
    }
};

ll dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}

ll cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

ll orient(const Point &a,
const Point &b, const Point &c) {
    return cross(b - a, c - b);
}

ll norm(const Point &p) {
    return dot(p, p);
}

istream& operator >> (istream &is, Point &p) {
    return is >> p.x >> p.y;
}

ostream& operator << (ostream &os, const Point &p) {
    return os << p.x << ' ' << p.y;
}

vector < Point > points;

int n;

int main() {
	fast;
	//fre();
	cin >> n;
	points.resize(n);
	for (auto &x : points) cin >> x;
	int q;
	cin >> q;
	while (q--) {
		Point p;
		cin >> p;
		if (orient(points[0], p, points[1]) >= 0) {
			cout << "NO" << '\n';
			continue;	
		}
		int l = 1, r = n - 1, mid, ans = -1;
		while (l <= r) {
			mid = (l + r) / 2;
			if (orient(points[0], p, points[mid]) > 0) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		if (ans == -1 || orient(points[ans - 1], p, points[ans]) >= 0) cout << "NO" << '\n';
		else cout << "YES" << '\n';
	}
}
