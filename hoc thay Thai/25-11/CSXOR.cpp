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

int n;

ll f[100003], mu2[100003];

map < int, int > pre, cnt;

void add(ll &x, ll y) {
	x = x + y;
	if (x >= MOD) x -= MOD;
	if (x < 0) x += MOD;
}

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

signed main() {
	fast;
	//fre();
	int cur = 0;
	pre[cur] = 0, cnt[cur] = 1;
	ll res = 0;
	cin >> n;
	f[0] = 1;
	mu2[0] = 1;
	for (int i = 1; i <= n; i++) {
		mu2[i] = (mu2[i - 1] * 2) % MOD;
		int x; cin >> x;
		cur ^= x;
		if (cnt.find(cur) == cnt.end()) {
			cnt[cur] = 1;
			pre[cur] = i;
			f[i] = 1;
		}
		else {
			int pos = pre[cur];
			f[i] = (f[pos] * mu2[i - pos]) % MOD;
			add(res, f[i] - 2 * cnt[cur]);
			f[i] ++;
			cnt[cur] ++;
			pre[cur] = i;
		}
	}
	cout << (res * mu(2, MOD - 2)) % MOD;
}
