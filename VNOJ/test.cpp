#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "ktour";
const string NAME2 = "test";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME2 + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, a[100005];

pii pos[100005];

ll calcdis(int x1, int y1, int x2, int y2) {
	if (x1 == -1 || x2 == -1 || y1 == -1 || y2 == -1) return INF;
	ll disx = 1ll * abs(x1 - x2);
	ll disy = 1ll * abs(y1 - y2);
	return disx * disx + disy * disy;
}

void sol() {
	int y0;
	cin >> n >> y0;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> m;
	for (int i = 1; i <= m; i++) cin >> pos[i].fi >> pos[i].se;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ll res = INF;
		for (int j = 1; j <= m; j++) res = min(res, calcdis(a[i], y0, pos[j].fi, pos[j].se));
		cout << res << '\n';
		ans = max(ans, res);
	}
	cout << fixed << setprecision(6) <<  sqrtl(ans) << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
