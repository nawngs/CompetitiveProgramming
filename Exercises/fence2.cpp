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

const string NAME = "fence2";
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

ll n, h[1000004], w[1000003], sw[1000003], l[1000003], r[1000003];

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

ll calc(ll x) {
	x = (x + MOD) % MOD;
	return (((x * (x + 1)) % MOD) * mu(2, MOD - 2)) % MOD;
}

ll count(ll h, ll w) {
	return (calc(h) * calc(w)) % MOD;
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
		sw[i] = sw[i - 1] + w[i];
		sw[i] %= MOD;
	}
	h[0] = h[n + 1] = 0;
 	stack < ll > st;
	for (int i = 1; i <= n; i++) {
		while (st.size() && h[st.top()] > h[i]) st.pop();
		if (!st.size()) l[i] = 1;
		else l[i] = st.top() + 1;
		st.push(i);
	}
	stack < ll > st2;
	for (int i = n; i >= 1; i--) {
		while (st2.size() && h[st2.top()] >= h[i]) st2.pop();
		if (!st2.size()) r[i] = n;
		else r[i] = st2.top() - 1;
		st2.push(i);
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ll tam = max(h[l[i] - 1], h[r[i] + 1]);
		ans = (ans + count(h[i], sw[r[i]] - sw[l[i] - 1]) - count(tam, sw[r[i]] - sw[l[i] - 1]) + MOD) % MOD;
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
