#include <bits/stdc++.h>

#define name "wedding"
#define test "test"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 15e5 + 5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;
const ll BASE2 = 5;

ll nk, M, p[NMAX + 5], sump[NMAX + 5], nxt[NMAX + 5], pw2[NMAX + 5], pwbase[NMAX + 5];

ll inv[NMAX + 5], hash2[NMAX + 5], hashb[NMAX + 5], ra[NMAX + 5], rb[NMAX + 5];

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % M;
	if (b % 2 == 1) x = (x * a) % M;
	return x;
}

ll mul(const ll &a, const ll &b) {
	ll res = a * b;
	return res % M;
}

ll get_hash2(ll l, ll r) {
	return (hash2[r] - hash2[l - 1] * pw2[r - l + 1] + MOD * MOD) % MOD;
}

ll get_hash(ll l, ll r) {
	if (l > r) return 0;
	return (hashb[r] - hashb[l - 1] * pwbase[r - l + 1] + MOD * MOD) % MOD;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> nk >> M;
	for (int i = 1; i <= nk; i++) {
		cin >> p[i];
		sump[i] = sump[i - 1] + p[i];
	}
	nxt[nk + 1] = nk + 1;
	for (int i = nk; i >= 1; i--) {
		nxt[i] = nxt[i + 1];
		if (p[i] != 0) nxt[i] = i;
	}
	pw2[0] = pwbase[0] = 1;
	for (int i = 1; i <= nk; i++) {
		pw2[i] = (pw2[i - 1] * BASE2) % MOD;
		pwbase[i] = (pwbase[i - 1] * BASE) % MOD;
	}
	for (int i = 1; i < M; i++) 
		inv[i] = mu(i, M - 2);
	for (int i = 1; i <= nk; i++) {
		hash2[i] = (hash2[i - 1] * BASE2 + (p[i] != 0)) % MOD;
		hashb[i] = (hashb[i - 1] * BASE + (nxt[i + 1] <= nk ? mul(p[i], inv[p[nxt[i + 1]]]) : 0)) % MOD;
	}
	for (int n = 2; n < nk; n++) {
		if (nk % n != 0) continue;
		int m = nk / n;
		for (int i = 1; i <= n; i++) ra[i] = -1;
		for (int i = 1; i <= m; i++) rb[i] = -1;
		bool correct = 1, th = 1;
		ll val2 = 0, len = -1, valb = 0, pos = -1;
		for (int i = 1; i <= nk; i+=m) {
			if (sump[i + m - 1] - sump[i - 1] == 0) {
				ra[i / m + 1] = 0;
				continue;
			}
			if (th) val2 = get_hash2(i, i + m - 1);
			else if (val2 != get_hash2(i, i + m - 1)) {
				correct = false;
				break;
			}
			th = false; pos = i / m + 1;
			if (len == -1) {
				for (int j = i; j <= i + m - 1; j++) 
					if (nxt[j + 1] <= i + m - 1) len = j - i;
				valb = get_hash(i, i + len);
			}
			else if (valb != get_hash(i, i + len)) {
				correct = false;
				break;
			}
		}
		if (!correct) continue;
		if (pos != -1) {
			int pos2 = -1;
			for (int i = 1; i <= m; i++) {
				if (p[(pos - 1) * m + i] == 0) rb[i] = 0;
				else {
					if (pos2 == -1) {
						ra[pos] = p[(pos - 1) * m + i];
						rb[i] = 1;
						pos2 = i;
					}
				}
			}
			for (int i = 1; i <= n; i++) 
				if (ra[i] == -1) ra[i] = p[(i - 1) * m + pos2];
			for (int i = 1; i <= m; i++) 
				if (rb[i] == -1) rb[i] = mul(p[(pos - 1) * m + i], inv[ra[pos]]);
		}
		else for (int i = 1; i <= m; i++) rb[i] = 0;
		cout << "YES" << '\n';
		cout << n << " "; for (int i = 1; i <= n; i++) cout << ra[i] << ' ';
		cout << '\n' << m << " "; for (int i = 1; i <= m; i++) cout << rb[i] << " ";
		return 0;
	}
	cout << "NO" << '\n';
}