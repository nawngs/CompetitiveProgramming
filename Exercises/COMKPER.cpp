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

const string NAME = "COMKPER";
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

int a[15][1005], f[1005], trace[1005], n, k, pos[15][1005];	

bool check(int val1, int val2) {
	for (int i = 1; i <= k; i++) if (pos[i][val1] < pos[i][val2]) return false;
	return true;
}

void sol() {
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		for (int j = n; j >= 1; j--) {
			cin >> a[i][j];
			pos[i][a[i][j]] = j;
		}
	}

	for (int i = 1; i <= n; i++) f[i] = 1;
	memset(trace, 255, sizeof(trace));
	a[1][0] = 1e9 + 7;
	int last = 0, ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = i - 1; j >= 1; j--) {
			if (check(a[1][i], a[1][j])) {
				if (f[i] < f[j] + 1) {
					f[i] = f[j] + 1;
					trace[i] = j;
				}
				else if (f[i] == f[j] + 1 && a[1][trace[i]] > a[1][j]) trace[i] = j;
			}
		}
		if (ans < f[i]) {
			ans = f[i];
			last = i;
		}
		else if (ans == f[i] && a[1][last] > a[1][i]) last = i;
	}
	cout << ans << '\n';
	while (last != -1) {
		cout << a[1][last] << " ";
		last = trace[last];
	}
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
