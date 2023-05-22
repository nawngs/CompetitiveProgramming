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

const string NAME = "uocso";
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

int n, m, a[200003], b[200003], dem[1000003];

void sub1() {
	int ans = 0;
	for (int i = 1; i <= m; ++i) {
		int cnt = 0;
		for (int j = 1; j <= n; ++j) if (a[j] % b[i] == 0) cnt ++;
		ans = max(ans, cnt);
	}
	cout << ans;
}

void sub2() {
	int dem0 = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == 0) {
			dem0 ++;
			continue;
		}
		for (int j = 1; j <= sqrt(a[i]); j++) {
			if (a[i] % j == 0) {
				dem[j] ++;
				if (a[i] / j != j) dem[a[i] / j] ++;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= m; ++i) ans = max(ans, dem[b[i]]);
	cout << ans + dem0;
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int j = 1; j <= m; ++j) cin >> b[j];
	if (n <= 1000 && m <= 1000) sub1();
	else sub2();
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
