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

const string NAME = "";
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

ll n, a[100005], m, disy[100005], x[100005], cnt[100005];

int bs1(ll val) {
	int l = 1, r = n, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid] <= val) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

//#######################################################################

int bs2(ll val) {
	int l = 1, r = n, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid] > val) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}

//#######################################################################

int bs3(ll pos, ll dis, ll r) {
	int l = 1, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if ((pos - a[mid]) * (pos - a[mid]) <= dis) {
			ans = mid;
			r = mid - 1;
		}
		else  l = mid + 1;
	}
	return ans;
}

//#######################################################################

int bs4(ll pos, ll dis, ll l) {
	int r = n, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if ((pos - a[mid]) * (pos - a[mid]) <= dis) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

//#######################################################################

bool check(ll val) {
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= m; i++) {
		ll tamval = val - disy[i];
		int down = bs1(x[i]);
		if (down != -1) {
			int tam = bs3(x[i], tamval, down);
			if (tam != -1) {
				cnt[tam] ++;
				cnt[down + 1] --;
			}
		}
		int up = bs2(x[i]);
		if (up != -1) {
			int tam = bs4(x[i], tamval, up);
			if (tam != -1) {
				cnt[up] ++;
				cnt[tam + 1] --;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cnt[i] += cnt[i - 1];
		if (cnt[i] <= 0) return false;
	}
	return true;
}

//#######################################################################

void sol() {
	ll y0;
	cin >> n >> y0;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int y;
		cin >> x[i] >> y;
		disy[i] = (y - y0) * (y - y0);
	}

	//#######################################################################
	// chat ket qua
	ll l = 0, r = 1e11, mid, ans = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else  l = mid + 1;
	}
	cout << fixed << setprecision(6) << (ld) sqrtl(ans) << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
