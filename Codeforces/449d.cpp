#include <bits/stdc++.h>

#define name ""
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
const int NMAX = 1e6;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, cnt[(1 << 20)], pw[1000003];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	pw[0] = 1;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		cnt[x] ++;
		pw[i] = (pw[i - 1] * 2) % MOD;
	}
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < (1 << 20); j++)
			if (j >> i & 1) cnt[j ^ (1 << i)] += cnt[j];
	ll res = 0;
	for (int i = 0; i < (1 << 20); i++) {
		if (__builtin_popcount(i) % 2 == 0) res = (res + pw[cnt[i]]) % MOD;
		else res = (res - pw[cnt[i]] + MOD) % MOD;
	}
	cout << res;
}