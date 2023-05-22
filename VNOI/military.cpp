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
	
} points[4003];
 
int hull[4003];
 
ll area(Point a, Point b, Point c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x); 
}
 
 
int n, val;
 
bool used[4003];
 
void monotone_chain() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (used[i]) continue;
		while (cnt >= 2 && area(points[hull[cnt - 1]], points[hull[cnt]], points[i]) < 0) cnt --;
		hull[++ cnt] = i;
	}
	int tam = cnt;
	for (int i = n; i >= 1; i--) {
		if (used[i]) continue;
		while (cnt > tam && area(points[hull[cnt - 1]], points[hull[cnt]], points[i]) < 0) cnt --;
		hull[++ cnt] = i;
	}
	val = 0;
	for (int i = 1; i <= cnt; i++) used[hull[i]] = 1;
	for (int i = 1; i <= n; i++) val += !used[i];
}
 
int main() {
	fast;
	cin >> n;
	val = n;
	for (int i = 1; i <= n; i++) cin >> points[i].x >> points[i].y;
	sort(points + 1, points + n + 1, [&](Point &x, Point &y) {
		return x.x < y.x || (x.x == y.x && x.y < y.y);
	});
	int res = 0;
	while (val >= 3) {
		res ++;
		monotone_chain();
	}
	cout << res;
}
 