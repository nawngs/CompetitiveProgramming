#include <bits/stdc++.h>

using namespace std;

using ld = long double;

struct Pt {
	ld x, y;
	Pt(ld x = 0, ld y = 0) : x(x), y(y) {}
	Pt& operator -= (const Pt &oth) {
		x -= oth.x, y -= oth.y;
		return (*this);
	}
	Pt operator - (const Pt &oth) const {
		return Pt(*this) -= oth;
	}
	bool operator == (const Pt &oth) {
		return (x == oth.x && y == oth.y);
	}
};

vector < Pt > a;

int n;

ld sqr(const Pt &x) {
	return x.x * x.x + x.y * x.y;
}

ld cross(const Pt &x, const Pt &y) {
	return x.x * y.y - x.y * y.x;
}

ld orient(const Pt &a, const Pt &b, const Pt &c) {
	return cross(b - a, c - a);
}

void solve() {
	a.resize(n);
	for (auto &x : a) cin >> x.x >> x.y;
	sort(a.begin(), a.end(), [&](Pt &x, Pt &y) {
		if (x.x == y.x) return x.y < y.y;
		return x.x < y.x;
	});
	a.erase(unique(a.begin(), a.end()), a.end());
	Pt root = a[0];
	sort(a.begin(), a.end(), [&](Pt &x, Pt &y) {
		if (x == root) return true;
		if (y == root) return false;
		ld d = orient(root, x, y);
		if (d == 0) return sqr(x - root) < sqr(y - root);
		return d > 0;
	});
	vector < Pt > res;
	for (auto x : a) {
		while (res.size() > 1 && orient(res[res.size() - 2], res.back(), x) <= 0) res.pop_back();
		res.push_back(x);
	}
	cout << res.size() << '\n';
	for (auto x : res) cout << x.x << " " << x.y << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	while (cin >> n && n != 0) solve();
}