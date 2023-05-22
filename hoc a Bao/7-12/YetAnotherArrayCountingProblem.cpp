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

int n, m, a[200003], st[200003][20];

map < pii, int > dp[200003];

int get(int l, int r) {
	int k = log2(r - l + 1);
	if (a[st[l][k]] >= a[st[r - (1 << k) + 1][k]]) return st[l][k];
	else return st[r - (1 << k) + 1][k];
}

int calc(int l, int r, int maxa) {
	if (r < l) return 1;
	if (maxa == 0) return 0;
	if (dp[maxa].find({l, r}) != dp[maxa].end()) return dp[maxa][{l, r}];
	int pos = get(l, r);
	ll res = 1ll * calc(l, r, maxa - 1) + 1ll * calc(l, pos - 1, maxa - 1) * calc(pos + 1, r, maxa);
	dp[maxa][{l, r}] = res % MOD;
	return dp[maxa][{l, r}];
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		st[i][0] = i;
	}
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			if (a[st[i][j - 1]] >= a[st[i + (1 << (j - 1))][j - 1]]) st[i][j] = st[i][j - 1];
			else st[i][j] = st[i + (1 << (j - 1))][j - 1];
		}
	for (int i = 1; i <= m; i++) dp[i].clear();
	cout << calc(1, n, m) << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
