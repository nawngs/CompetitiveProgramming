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
const ll ESP = 1e-9;
const ll INF = 1e18;
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
	Point(ll _x, ll _y) : x(_x), y(_y) {};
};

ll area(Point a, Point b, Point c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x); 
}

vector < Point > points, hull;

int n;

void monotone_chain() {
	vector < Point > temp;
	temp = points;
	points.clear();
	points.push_back(temp[0]);
	for (int i = 1; i < temp.size(); i++) {
		if (temp[i].x == temp[i - 1].x && temp[i].y == temp[i - 1].y) continue;
		//cout << temp[i].x << " " << temp[i].y << '\n';
		points.push_back(temp[i]);
	}
	n = points.size();
	if (n < 3) {
		hull = points;
		return ;
	}
	for (int i = 0; i < n; i++) {
		while (hull.size() >= 2 && area(hull[hull.size() - 2], hull.back(), points[i]) <= 0) hull.pop_back();
		hull.push_back(points[i]);
	}
	int tam = hull.size();
	for (int i = n - 2; i >= 0; i--) {
		while (hull.size() > tam && area(hull[hull.size() - 2], hull.back(), points[i]) <= 0) hull.pop_back();
		hull.push_back(points[i]);
	}
	hull.pop_back();
}

void sol() {
	points.clear();
	hull.clear();
	for (int i = 1; i <= n; i++) {
		ll x, y;
		cin >> x >> y;
		points.push_back({x, y});
	}
	sort(points.begin(), points.end(), [](Point &x, Point &y) {
		return (x.x < y.x) || (x.x == y.x && x.y < y.y);
	});
	monotone_chain();
	
	cout << hull.size() << '\n';
	for (auto x : hull) cout << x.x << " " << x.y << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (cin >> n && n != 0) sol();
	
}
