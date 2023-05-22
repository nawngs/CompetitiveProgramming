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

struct Card {
	int color, val;
};

Card card[403];

int c, n, f[10], d[403], dp[403], ans = MOD;

bool used[10];

void create() {
	for (int i = 1; i <= n * c; i++) d[i] = f[card[i].color] * base + card[i].val;
}

void find_lis() {
	int res = 0;
	for (int i = 1; i <= n * c; i++) dp[i] = 1;
	for (int i = 2; i <= n * c; i++) {
		for (int j = 1; j < i; j++) if (d[i] > d[j]) dp[i] = max(dp[i], dp[j] + 1);
		res = max(res, dp[i]);
	}
	ans = min(ans, n * c - res);
}

void backtrack(int pos) {
	if (pos == c + 1) {
		create();
		find_lis();
	}
	for (int i = 1; i <= c; i++) {
		if (!used[i]) {
			f[i] = pos;
			used[i] = true;
			backtrack(pos + 1);
			used[i] = false;
		}
	}
}

void sol() {
	cin >> c >> n;
	for (int i = 1; i <= n * c; i++) cin >> card[i].color >> card[i].val;
	backtrack(1);
	cout << ans;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
