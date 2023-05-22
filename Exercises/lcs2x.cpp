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

const string NAME = "lcs2x";
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

ll n, m, a[1503], b[1503], f[1503];

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= n; i++) {
		ll tmp = 0;
		for (int j = 1; j <= m; j++) {
			ll temp = tmp;
			if (b[j] * 2 <= a[i]) tmp = max(tmp, f[j]);
			if (b[j] == a[i]) f[j] = max(f[j], temp + 1);
		}
	}
	ll res = 0;
	for (int i = 1; i <= m; i++) res = max(res, f[i]);
	cout << res << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
