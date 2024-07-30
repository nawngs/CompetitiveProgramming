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

int n;

pii a[NMAX + 3];

set < pii > ms[NMAX + 3];

bool cmp(const pii &x, const pii &y) {
	return x.fi < y.fi && x.se < y.se;
}

bool check(int id, const pii &x) {
	for (auto it : ms[id]) 
		if (cmp(it, x)) return true;
	return false;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	int res = 0;
	ms[0].insert({-INF, -INF});
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
		int l = 0, r = n, mid, ans;
		while (l <= r) {
			mid = (l + r) / 2;
			if (check(mid, a[i])) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		ans ++;
		res = max(res, ans);
		auto it = ++ms[ans].insert(a[i]).fi;
		while (it != ms[ans].end()) {
			if (cmp(a[i], *it)) ms[ans].erase(it++);
			else it++;
		}
	}
	cout << res;
}