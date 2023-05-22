/*#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "DaiLy";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, m, a[100005], s[500005], f[500005], c[500005], num[500005];

ll bs(ll templ, ll r, ll val) {
	ll l = templ + 1, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid] - a[templ] <= val) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

bool check(ll x) {
	for (int i = 1; i <= m; i++) {
		ll l = s[i], r = f[i], dem = -1;
		while (l < r) {
			ll tam = bs(l, r, x / c[i]);
			if (tam == -1) return false;
			l = tam;
			dem ++;
			if (dem > num[i]) return false;
		}
	}
	return true;
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> s[i] >> f[i] >> c[i] >> num[i];
	ll l = 1, r = 1e18, mid, res = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			res = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << res;
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
*/
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

const string NAME = "DaiLy";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, a[100005], s[500005], f[500005], c[500005], num[500005], dp[405][405][405];

ll bs(ll templ, ll r, ll val) {
	ll l = templ + 1, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid] - a[templ] <= val) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

bool check(ll x) {
	for (int i = 1; i <= m; i++) {
		ll l = s[i], r = f[i], dem = -1;
		while (l < r) {
			ll tam = bs(l, r, x / c[i]);
			if (tam == -1) return false;
			l = tam;
			dem ++;
			if (dem > num[i]) return false;
		}
	}
	return true;
}

void sol1() {
	ll l = 1, r = 1e18, mid, res = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			res = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << res;
}

void sol2() {
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) dp[i][j][1] = a[j] - a[i];

	for (int k = 2; k < n; k++) {
		for (int i = 1; i <= n - k; i++) {
			ll t = i + k - 1;
			for (int j = i + k; j <= n; j++) {
				while(t < j - 1 && max(dp[i][t + 1][k - 1], dp[t + 1][j][1]) < max(dp[i][t][k - 1], dp[t][j][1])) t++;
                dp[i][j][k] = max(dp[i][t][k - 1], dp[t][j][1]);
			}
		}
	}
	ll res = 0;
	for (int i = 1; i <= m; i++) res = max(res, dp[s[i]][f[i]][min(f[i] - s[i] - 1, num[i]) + 1] * c[i]);
	cout << res;
}

int main() {
	fast;
	fre();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> s[i] >> f[i] >> c[i] >> num[i];
	if (n > 400 || n <= 100) sol1();
	else sol2();
}

