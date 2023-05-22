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
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, dem = 0, cnt[400003], s[400003], dem2[400003];

pii a[200003];

vector < pair < int, pii > > f;

void roi_rac() {
	f.clear();
	for (int i = 1; i <= n; i++) {
		f.push_back({a[i].fi, {i, 1}});
		f.push_back({a[i].se, {i, 2}});
	}
	sort(f.begin(), f.end());
	dem = 0;
	for (int i = 0; i < f.size(); i++) {
		dem += (i == 0 || (f[i].fi != f[i - 1].fi));
		if (f[i].se.se == 1) a[f[i].se.fi].fi = dem;
		else a[f[i].se.fi].se = dem;
	}
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
	roi_rac();
	for (int i = 0; i <= 2 * dem; i++) {
		cnt[i] = 0;
		s[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		a[i].fi *= 2;
		a[i].se *= 2;
		cnt[a[i].fi] ++;
		cnt[a[i].se + 1] --;
	}
	for (int i = 1; i <= 2 * dem; i++) {
		cnt[i] += cnt[i - 1];
		cout << i << " " << cnt[i] << '\n';
	}
	cnt[2 * dem + 1] = 0;
	int res = 0;
	for (int i = 1; i <= 2 * dem; i++) {
		s[i] = s[i - 1] + (cnt[i] > 1 && cnt[i + 1] == 1);
		res = res + (cnt[i] > 0 && cnt[i + 1] == 0);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, res + s[a[i].se] - s[a[i].fi - 1]);
		cout << i << " " << ans << '\n';
	}
	cout << ans << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
