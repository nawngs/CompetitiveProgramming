#include <bits/stdc++.h>

#define name ""
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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, cnt[100003];

ll a[100003];

vector < pll > f;

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	ll res = 0, temp = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		res += a[i] - 1;
		temp = (temp * 2) % MOD;
	}
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		f.pb({x - 1, i}); f.pb({a[i] - x, i});
	}
	ll inv = mu(2, MOD - 2);
	sort(f.begin(), f.end());
	int pre = 0, l = 0;
	for (int i = 1; i < sz(f); i++) {
		if (f[i].fi != f[i - 1].fi) {
			res = (res + (temp * (f[i - 1].fi- pre)) % MOD) % MOD;
			for (int j = l; j < i; j++) {
				if (cnt[f[j].se] == 0) temp = (temp * inv) % MOD;
				else {
					cout << res << '\n';
					return 0;
				}
				cnt[f[j].se] ++;
			}
			pre = f[i - 1].fi; l = i;
		}
	}
	res = (res + (temp * (f[sz(f) - 1].fi- pre)) % MOD) % MOD;
	cout << res;
}