#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define int ll
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
	string finp = NAME2 + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	//freopen(fout.c_str(), "w", stdout);
}

int n, a, b, w[2003], s[2003], dp2[2003];

bool dp1[2003][2003];

bool sub1(int x, ll res) {
	memset(dp1, false, sizeof(dp1));
	dp1[0][0] = 1;
	for (int k = 1; k <= b; k++) {
		for (int i = 1; i <= n; i++) {
			if (!dp1[i - 1][k - 1]) continue;
			for (int j = i; j <= n; j++) if ((((s[j] - s[i - 1]) | res) >> x) == (res >> x)) dp1[j][k] = 1;
			
		}
	}
	for (int i = a; i <= b; i++) if (dp1[n][i]) return true;
	return false;
}

bool sub2(int x, ll res) {
	for (int i = 1; i <= n; i++) dp2[i] = INF;
	dp2[0] = 0;
	for (int i = 1; i <= n; i++) 
		for (int j = i; j <= n; j++) {
			if ((((s[j] - s[i - 1]) | res) >> x) == (res >> x)) dp2[j] = min(dp2[j], dp2[i - 1] + 1);
		}
	return (dp2[n] <= b);
}

bool check(int x, ll res) {
	if (a == 1) return sub2(x, res);
	else return sub1(x, res);
}

signed main() {
	fast;
	//fre();
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
		s[i] = s[i - 1] + w[i];
	}
	ll res = 0;
	for (int i = 62; i >= 0; i--) 
		if (!check(i, res)) res |= (1ll << i);
	cout << res;
}
