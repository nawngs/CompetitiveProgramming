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

const string NAME = "urgent";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 19972207;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, k, dp[(1 << 24)];

void add(ll &x, ll y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

int main() {
	fast;
	//fre();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		int cur = 0;
		for (auto c : s)
			cur |= (1 << (c - 'a'));
		dp[cur] ++;
	}
	for (int i = 0; i < k; i++)
		for (int mask = 0; mask < (1 << k); mask++)
			if ((mask >> i & 1))
				add(dp[mask], dp[mask ^ (1 << i)]);
	ll cur = 1, res = 0;
	for (int i = 0; i < (1 << k); i++) {
		ll cnt = n - dp[(1 << k) - 1 - i];
		//cout << i << " " << cur << " " << cnt << '\n';
		add(res, (cnt * cur) % MOD);
		cur = (cur * (n + 1)) % MOD;
	}
	cout << res;
}
