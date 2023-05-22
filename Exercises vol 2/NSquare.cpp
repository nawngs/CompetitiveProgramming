#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define int ll
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pld pair < ld, ld >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "nsquare";
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
	ld x, y;
} p[1003];

int n;

map < pld, bool > f;

signed main() {
	fast;
	//fre();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i].x >> p[i].y;
		f[make_pair(p[i].x, p[i].y)] = 1;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			Point mid;
			mid.x = (p[i].x + p[j].x) / 2;
			mid.y = (p[i].y + p[j].y) / 2;
			ld leny = abs(p[i].x - mid.x);
			ld lenx = abs(p[i].y - mid.y);
			pld dot1, dot2;
			if ((p[i].x - p[j].x) * (p[i].y - p[j].y) >= 0) {
				dot1 = make_pair((mid.x - lenx), (mid.y + leny));
				dot2 = make_pair((mid.x + lenx), (mid.y - leny));
			}
			else {
				dot1 = make_pair((mid.x - lenx), (mid.y - leny));
				dot2 = make_pair((mid.x + lenx), (mid.y + leny));
			}
			if (f[dot1] && f[dot2]) {
				//cout << i << " " << j << " " << dot1.fi << " " << dot1.se << '\n';
				ans ++;
			}
		}
	}
	cout << ans / 2;
}
