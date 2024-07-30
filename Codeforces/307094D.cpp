#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
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
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll l[4], n, ans[4];

vector < ll > v[4];

bool minimize(ll &x, ll y) {
	if (x > y) {
		x = y;
		return true;
	}
	return false;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	for (int i = 0; i < 4; i++) {
		cin >> n;
		v[i].resize(n);
		for (auto &x : v[i]) cin >> x;
		sort(v[i].begin(), v[i].end());
	}
	ll res = LINF;
	while (1) {
		ll mn = LINF;
		if (minimize(res, max({v[0][l[0]], v[1][l[1]], v[2][l[2]], v[3][l[3]]}) - min({v[0][l[0]], v[1][l[1]], v[2][l[2]], v[3][l[3]]}))) {
			for (int i = 0; i < 4; i++) ans[i] = v[i][l[i]];
		}
		for (int i = 0; i < 4; i++) mn = min(mn, v[i][l[i]]);
		bool th = 1;
		int pos = -1;
		for (int i = 0; i < 4; i++) if (mn == v[i][l[i]]) {
			if (l[i] == SZE(v[i]) - 1) th = false;
			else if (pos == -1 || v[i][l[i] + 1] < v[pos][l[pos] + 1]) pos = i;
		}
		if (!th) break;
		l[pos] ++;
	}
	cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3];
}