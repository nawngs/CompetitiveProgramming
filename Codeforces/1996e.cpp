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
const int N = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = N;

string s;

int cnt[N + 3], n;

ll total[2 * N + 3];

void sol() {
	cin >> s; 
	n = s.size(), s = ' ' + s;
	for (int i = 0; i <= n; i++) total[BASE + i] = total[BASE - i] = 0;
	total[BASE] = 1;
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		cnt[i] = cnt[i - 1] + (s[i] == '0' ? -1 : 1);
		res = (res + 1ll * (n - i + 1) * total[BASE + cnt[i]]) % MOD;
		//cerr << i << " " << cnt[i] << " " << total[BASE + cnt[i]] << '\n';
		total[BASE + cnt[i]] += i + 1;
	}
	cout << res << '\n';
	
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}