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

const string NAME = "";
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

ll n, m, k, a[300003], dp[300003][32];

vector < int > adj[300003];

bool getbit(int a, int pos){
	return (a & 1 << pos);
}

ll solve(int u, int bit) {
	if (dp[u][bit] != -1) return dp[u][bit];
	if (!getbit(bit, a[u])) {
		dp[u][bit] = 0;
		return 0;
	}
	ll res = 0;
	for (auto v : adj[u]) res += solve(v, bit - (1 << a[u]));
	dp[u][bit] = res;
	return res;
}

int main() {
	fast;
	//fre();
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] --;
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(dp, 255, sizeof(dp));
	for (int i = 1; i <= n; i++) dp[i][(1 << a[i])] = 1;
	ll res = 0;
	for (int i = 1; i <= n; i++)
		for (int bit = 0; bit < (1 << k); bit++) {
			res += solve(i, bit);
			//cout << i << " " << bit << " " << dp[i][bit] << '\n';
		}
	cout << res - n;
}
