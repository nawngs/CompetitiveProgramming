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

ll n, m, leaf[10003], dist[1003], dp[10003];

pll machine[10003];

ll bs(ll val) {
	int l = 1, r = n, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (leaf[mid] >= val) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> leaf[i];
	sort(leaf + 1, leaf + n + 1);
	for (int i = 1; i <= m; i++) cin >> machine[i].fi >> machine[i].se;
	for (int i = 1; i <= 1000; i++) {
		dist[i] = -1;
		for (int j = 1; j <= m; j++) if (machine[j].se == i) dist[i] = max(dist[i], 2 * machine[j].fi);
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = INF;
		for (int j = 1; j <= 1000; j++) {
			if (dist[j] == -1) continue;
			ll pos = bs(leaf[i] - dist[j]);
			dp[i] = min(dp[i], dp[pos - 1] + j);
		}
	}
	cout << dp[n];
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
