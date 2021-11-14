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

const string NAME = "UNLOCK";
const ll ESP = 1e-9;
const ll INF = 1e18;
const int nmax = 1e5 + 1;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

//#######################################################################

ll n, a[nmax + 5], sum[nmax + 5], cnt[nmax + 5], f[nmax + 5], dem = 0, m;

ll ans =  INF;

void roi_rac() {
	pii p[100005];
	for (int i = 1; i <= n; i++) {
		p[i].fi = a[i];
		p[i].se = i;
	}
	sort(p + 1, p + n + 1);
	p[0].fi = -1e9;
	for (int i = 1; i <= n; i++) {
		dem += (p[i].fi != p[i - 1].fi);
		f[dem] = a[p[i].se];
		sum[dem] += a[p[i].se];
		cnt[dem] ++;
		a[p[i].se] = dem;
	}
	for (int i = 1; i <= nmax; i++) {
		sum[i] += sum[i - 1];
		cnt[i] += cnt[i - 1];
	}
}

//#######################################################################

ll bs1(ll val) {
	ll l = 1, r = dem, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (f[mid] <= val) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
 	}
 	return ans;
}

//#######################################################################

ll bs2(ll val) {
	ll l = 1, r = dem, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (f[mid] >= val) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}

//#######################################################################

void sol1(ll pos) {
	ll res = f[pos] * cnt[pos] - sum[pos];
	ll newpos = bs1(f[pos] + m / 2);
	res += (sum[newpos] - sum[pos] - (cnt[newpos] - cnt[pos]) * f[pos]);
	res += (m + f[pos]) * (cnt[dem] - cnt[newpos]) - (sum[dem] - sum[newpos]);
	ans = min(ans, res);
}

//#######################################################################

void sol2(ll pos) {
	ll res = (sum[dem] - sum[pos]) - (cnt[dem] - cnt[pos]) * f[pos];
	ll newpos = bs2(f[pos] - m / 2);
	res += (cnt[pos] - cnt[newpos - 1]) * f[pos] - (sum[pos] - sum[newpos - 1]);
	res += sum[newpos - 1] + m * cnt[newpos - 1] - cnt[newpos - 1] * f[pos];
	ans = min(ans, res);
}

//#######################################################################

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	roi_rac();
	for (int i = 1; i <= n; i++) {
		if (f[a[i]] < (m + 1) / 2) sol1(a[i]);
		else sol2(a[i]);
	}
	cout << ans << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
