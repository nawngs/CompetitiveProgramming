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

ll n, k, maxx;

pll time_land[100003];

vector < ll > land[10];

ll solve(ll x) {
	for (int i = 1; i <= k; i++) land[i].clear();
	for (int i = 1; i <= min(k, n); i++) land[i].push_back(time_land[i].fi);
	for (int i = k + 1; i <= n; i++) {
		ll pos = 0;
		ll tam = INF;
		for (int j = 1; j <= k; j++) {
			if (tam > land[j][land[j].size() - 1]) {
				tam = land[j][land[j].size() - 1];
				pos = j;
			}
		}
		if (land[pos][land[pos].size() - 1] + x <= time_land[i].se) 
			land[pos].push_back(max(time_land[i].fi, land[pos][land[pos].size() - 1] + x));
	}
	ll ans = 0;
	for (int i = 1; i <= k; i++) ans += land[i].size();
	return ans;
}

void sol() {
	cin >> n >> k >> maxx;
	for (int i = 1; i <= n; i++) cin >> time_land[i].fi >> time_land[i].se;
	sort(time_land + 1, time_land + n + 1);
	ll tam = solve(maxx);
	cout << tam << ' ';
	if (tam <= k) {
		cout  << -1 << '\n';
		return ;
	}
	ll l = maxx, r = INF, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (solve(mid) == tam) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout  << ans << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
