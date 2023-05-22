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

const string NAME = "swgame";
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

ll n, l, r, cost, f[2][100003], g[2][100003];

vector < ll > pos;

int main() {
	fast;
	fre();
	cin >> n >> l >> r;
	cost = min(l, r);
	for (int i = 1; i <= n; i++) {
		ll x; cin >> x;
		if (x & 1) pos.push_back(i);
	}
	if (pos.size() <= 1) {
		cout << 0 << '\n';
		return 0;
	}
	if (pos.size() % 2 == 0) {
		ll res = 0;
		for (int i = 1; i < pos.size(); i+=2) 
			res += (pos[i] - pos[i - 1]) * cost;
		ll cur = (pos[0] + n - pos.back()) * cost;
		for (int i = 2; i < pos.size() - 1; i+=2)
			cur += (pos[i] - pos[i - 1]) * cost;
		cout << min(res, cur) << '\n';
		return 0;
	}
	ll res = LINF;
	for (int i = 1; i < pos.size(); i++) {
		f[0][i] = f[0][i - 1];
		f[1][i] = f[1][i - 1];
		f[i % 2][i] += (pos[i] - pos[i - 1]) * cost;
	}
	// f[1] la co thg 0
	for (int i = pos.size() - 2; i >= 0; i--) {
		g[0][i] = g[0][i + 1]; g[1][i] = g[1][i + 1];
		g[i % 2][i] += (pos[i + 1] - pos[i]) * cost;
	}
	// g[0] la co thang cuoi
	for (int i = 0; i < pos.size(); i++) {
		if (i % 2 == 0) {
			//cout << i << " " << f[1][i - 1] << " " << g[1][i + 1] << '\n';
			res = min(res, f[1][i - 1] + g[1][i + 1]);
		}
		else {
			//cout << i << " " << f[0][i - 1] << " " << g[0][i + 1] << " " << pos[0] + n - pos.back() << '\n';
			res = min(res, f[0][i - 1] + g[0][i + 1] + (pos[0] + n - pos.back()) * cost);
		}
	}
	cout << res << '\n';
}
