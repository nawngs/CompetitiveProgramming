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
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

int n, m, a[100002], s[500002], f[500002], c[500002], num[500002], base = 0;

int bs(int templ, int r, ll val) {
	int l = templ + 1, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (1ll * (a[mid] - a[templ]) <= val) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

bool check(ll x) {
	for (int i = 1; i <= m; i++) {
		if (c[i] == 0) continue;
		int l = s[i], r = f[i], dem = -1;
		while (l < r) {
			int tam = bs(l, r, x / (1ll * c[i]));
			if (tam == -1) return false;
			l = tam;
			dem ++;
			if (dem > num[i]) return false;
		}
	}
	return true;
}

void sol1() {
	ll l = 1, r = 1ll * base * 1ll * (a[n] - a[1]), mid, res = -1;
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
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) {
		cin >> s[i] >> f[i] >> c[i] >> num[i];
		base = max(base, c[i]);
	}
	sol1();
}

