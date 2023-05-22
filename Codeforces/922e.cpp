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

ll n, W, B, X, c[1003], cost[1003], dp[1003][10003];

int main() {
	fast;
	//fre();
	cin >> n >> W >> B >> X;
	ll total = 0;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		total += c[i];
	}
	for (int i = 1; i <= n; i++)
		cin >> cost[i];
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= total; j++)
			dp[i][j] = -LINF;
	dp[0][0] = W;
	for (int i = 1; i <= n; i++) {
		deque < pll > dq;
		for (int j = 0; j <= total; j++) {
			pll cur = {dp[i - 1][j] - (n - j) * cost[i], j};
			while (dq.size() && dq.front().fi < cur.fi) dq.pop_front();
			dq.push_front(cur);
			while (dq.size() && dq.back().se < j - c[i]) dq.pop_back();
			if (!dq.size()) break;
			ll tam = dq.back().fi + (n - dq.back().se) * cost[i];
			tam = tam - (j - dq.back().se) * cost[i];
			if (tam < 0) break;
			dp[i][j] = min(W + j * B, tam + X);
		}
	}
	ll ans = -1;
	for (int j = 0; j <= total; j++) 
		if (dp[n][j] >= 0) ans = j;
	cout << ans;
}
