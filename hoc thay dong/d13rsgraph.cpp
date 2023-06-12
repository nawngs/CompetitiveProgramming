#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define int ll
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
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, a[100003], cnt[100003], cnt_same[100003], cnt_up[100003];

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

main() {
	fast;
	cin >> n >> m;
	for (int i = 2; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]] ++;
	}
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		if (a[x] < a[y]) swap(x, y);
		if (a[x] - a[y] > 1) {
			cout << 0 << '\n';
			return 0;
		}
		if (a[x] == a[y]) cnt_same[a[x]] ++;
		else cnt_up[x] += 1;
	}
	ll res = 1;
	cnt[0] = 1;
	for (int i = 1; i <= n; i++) {
		res = (res * mu(2, cnt[i] * (cnt[i] - 1) / 2 - cnt_same[i])) % MOD;
	}
	for (int i = 2; i <= n; i++) {
		res = (res * (mu(2, cnt[a[i] - 1] - cnt_up[i]) - (cnt_up[i] == 0))) % MOD;
	}
	cout << res;
}
