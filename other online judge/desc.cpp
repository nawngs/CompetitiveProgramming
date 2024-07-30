#include <bits/stdc++.h>

#define name "desc"
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
const int N = 5E3;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, k;

int dp[N + 3][N + 3], s[N + 3][N + 3];

unordered_map < ll, int > pos;

vector < ll > divi;

int main() {
	fast;
	if(fopen(name".in", "r")) {
		freopen(name".in", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k;
	for (ll i = 1; i * i <= n; i++) if (n % i == 0) {
		divi.pb(i);
		if (i != n / i) divi.pb(n / i);
	}
	sort(divi.begin(), divi.end());
	int m = SZE(divi) - 1;
	for (int i = 0; i <= m; i++) pos[divi[i]] = i;
	dp[0][m] = 1;
	for (int rem = 0; rem <= m; rem++) {
		for (int j = m; j >= 0; j--) s[rem][j] = s[rem][j + 1] + dp[rem][j];
		for (int pre = rem + 1; pre <= m; pre++) {
			if (divi[pre] % divi[rem]) continue;
			ll v = divi[pre] / divi[rem];
			if (pos.find(v) == pos.end()) continue;
			dp[pre][pos[v]] += s[rem][pos[v]];
		}
	}
	cout << s[m][1] << '\n';
	ll cur = m, v = 1;
	while (1) {
		if (k > dp[cur][v]) {
			k -= dp[cur][v];
			v ++;
		}
		else {
			cout << divi[v] << " ";
			cur = divi[cur] / divi[v];
			if (cur == 1) break;
			cur = pos[cur];
		}
	}
}