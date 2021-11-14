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

const string NAME = "L2CX";
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

int n, m, a[1505], b[1505], f[1505];

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	int ans = 0;
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		for (int j = 1; j <= m; j++) {
			int temp = tmp;
			if (2 * b[j] <= a[i]) tmp = max(tmp, f[j]);
			if (b[j] == a[i]) {
				f[j] = max(f[j], temp + 1);
				ans = max(ans, f[j]);
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
