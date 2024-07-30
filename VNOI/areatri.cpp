#include <bits/stdc++.h>

#define ll long long

using namespace std;

struct Point {
	ll x, y;
	Point(ll x = 0, ll y = 0) : x(x), y(y) {}
	Point& operator -= (const Point &oth) {
		x -= oth.x; y -= oth.y;
		return *this;
	}
	Point& operator += (const Point &oth) {
		x += oth.x; y += oth.y;
		return *this;
	}
	Point operator - (const Point &oth) const {
		return Point(*this) -= oth;
	}
	Point operator + (const Point &oth) const {
		return Point(*this) += oth;
	}
};

ll dot(const Point &x, const Point &y) {
	return x.x * y.x + x.y * y.y;
}

ll cross(const Point &x, const Point &y) {
	return x.x * y.y - x.y * y.x;
}

ll orient(const Point &a, const Point &b, const Point &c) {
	return cross(b - a, c - a);
}

const int N = 1000;

ll res = 0, n;

Point a[N + 3], b[N + 3];

void solve(int id) {
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
	for (int i = 1; i <= n; i++) solve(i);
	cout << res;
}