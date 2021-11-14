#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define slow ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const ll ESP = 1e-9;
const ll INF = 1e18;
const int nmax = 8200;
const ll MOD = 1e9 + 7;

int n, cnt[5005];

ll dp[1002][nmax + 2];

vector < int > p;

bool check[nmax + 2];

void sang() {
	for (int i = 1; i <= nmax; i++) check[i] = true;
	check[1] = check[0] = false;
	for (int i = 2; i * i <= nmax; i++) 
		if (check[i]) for (int j = i * i; j <= nmax; j += i) check[j] = false;
}

void sol() {
	cin >> n;	
	memset(cnt, 0, sizeof(cnt));
	p.clear();
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (cnt[x] == 0) p.push_back(x);
		cnt[x] ++;
	}
	for (int i = 0; i < p.size(); i++)
		for (int j = 0; j <= nmax; j++) dp[i][j] = 0;

	ll ans = 0;
	dp[0][0] = cnt[p[0]] / 2 + 1;
	dp[0][p[0]] = cnt[p[0]] - dp[0][0] + 1;
	for (int i = 0; i < p.size() - 1; i++) {
		int demc = cnt[p[i + 1]] / 2 + 1;
		int deml =	cnt[p[i + 1]] - demc + 1;
		for (int j = 0; j <= nmax; j++) {
			dp[i + 1][j] += (dp[i][j] * demc) % MOD;
			dp[i + 1][(j ^ p[i + 1])] += (dp[i][j] * deml) % MOD;
			dp[i + 1][j] %= MOD;
			dp[i + 1][(j ^ p[i + 1])] %= MOD;
		}
	}
	for (int i = 1; i <= nmax; i++) if (check[i]) ans = (ans + dp[p.size() - 1][i]) % MOD;
	cout << ans << '\n';
}

int main() {
	slow;
	sang();
	int t;
	cin >> t;
	while (t --) sol();
}
;