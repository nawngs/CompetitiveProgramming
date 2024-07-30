#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int N = 5e5;
const ll BASE = 2309;

ll n, t, MOD, s[N + 3], a[N + 3], cnt[N + 3];

ll get(int l, int r) {
	return (s[r] - s[l - 1] + MOD) % MOD;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> t >> MOD;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[a[i]] ++;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= N; i++) {
		cnt[0] = (cnt[0] + s[i] * s[i - 1]) % MOD;
		s[i] = (s[i] + s[i - 1]) % MOD;
	}
	for (int i = 1; i <= N; i++) 
		for (int j = i; j <= N; j+=i) {
			cnt[i] = (cnt[i] + get(j / i, j / i) * get(j, min(N, j + (j / i) - 1))) % MOD;
		}
	// for (int i = 0; i <= 2; i++) cout << i << " " << cnt[i] << '\n';
	ll res = 0;
	for (int i = 0; i <= t; i++) 
		res = (res + cnt[i] * cnt[t - i]) % MOD;
	cout << res;
}