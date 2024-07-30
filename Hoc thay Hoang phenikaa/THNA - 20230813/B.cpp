//[UNFINISHED]
#include <bits/stdc++.h>

#define int ll
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
const int NMAX = 1e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, x[NMAX + 3], a[NMAX + 3], b[NMAX + 3];

bool check(int k) {
	int mn = 0, mx = LINF;
	for (int i = 1; i <= n; i++) {
		if (a[i] == b[i] && x[i] / a[i] < k) return false;
		if (x[i] < k * a[i] && x[i] < k * b[i]) return false;
		if (a[i] > b[i]) mx = min(mx, (x[i] - k * b[i]) / (a[i] - b[i]));
		if (a[i] < b[i]) mn = max(mn, k - (x[i] - k * a[i]) / (b[i] - a[i]));
	}
	return mn <= mx;
}

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> x[i];
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	int l = 0, r = INF, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans;
}