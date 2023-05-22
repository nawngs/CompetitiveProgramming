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

const string NAME = "trains";
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

ll n, a[100003], st[100003][23];

ll dp[100003], maxpos[100003];

ll getmax(ll l, ll r) {
	ll t = log2(r - l + 1);
	return (a[st[l][t]] > a[st[r - (1 << t) + 1][t]] ? st[l][t] : st[r - (1 << t) + 1][t]);
}

void sol() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a[i];	
		st[i][0] = i;
		maxpos[i] = i;
	}
	maxpos[n] = n;
	a[n] = n + 1;
	st[n][0] = n;
	for (int t = 1; t <= 20; t++) {
		for (int i = 1; i <= n; i++) {
			if (i + (1 << t) - 1 > n) break;
			st[i][t] = (a[st[i][t - 1]] > a[st[i + (1 << (t - 1))][t - 1]] ? st[i][t - 1] : st[i + (1 << (t - 1))][t - 1]);
		}
	}
	ll ans = 0;
	for (int i = n - 1; i >= 1; i--) {
		ll tam = getmax(i, a[i]);
		dp[i] = tam - i;
		dp[i] += dp[tam] + (maxpos[tam] - a[i]);
		maxpos[i] = maxpos[tam];
		//cout << tam << " " << a[i] << " " <<  dp[i] << '\n';
		ans += dp[i];
	}
	cout << ans;
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
