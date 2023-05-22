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

const string NAME = "sortyyhu";
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

int n, m, s, a[10003][103], pos[10003], b[10003], k;

void sol() {
	cin >> n >> m >> s;
	for (int i = 1; i  <= n; i++) {
		for (int j = 1; j <= m; j++) cin >> a[i][j];
		pos[i] = i;
	}
	for (int i = 1; i <= s; i++) {
		cin >> k;
		for (int j = 1; j <= n; j++) b[j] = j;
		sort(b + 1, b + n + 1, [](int &x, int &y) {
			return (a[x][k] < a[y][k] || (a[x][k] == a[y][k] && pos[x] < pos[y]));
		});
		for (int j = 1; j <= n; j++) pos[b[j]] = j;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cout << a[b[i]][j] << ' ';
		cout << '\n';
	}
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
