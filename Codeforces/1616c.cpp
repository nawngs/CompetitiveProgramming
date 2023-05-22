#pragma GCC optimize ("O3")
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
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[73], cnt[73];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n == 1) {
		cout << 0 << '\n';
		return ;
	}
	int ans = n;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int dem = 0;
			for (int p = 1; p <= n; p++) if ((a[j] - a[i]) * (p - i) != (a[p] - a[i]) * (j - i)) dem ++;
			ans = min(ans, dem);
			
		}
	}
	cout << ans << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
