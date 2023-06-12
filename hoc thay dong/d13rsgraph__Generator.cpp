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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getrand(const int& mi, const int& ma) {
    return rng() % (ma - mi + 1) + mi;
}

int d[302];

map < pii, bool > f;

int main() {
	fast;
	int n = getrand(50, 60), m = getrand(1, n - 1);
	cout << n << " " << m << '\n';
	for (int i = 2; i <= n; i++) {
		d[i] = getrand(1, 15);
		cout << d[i] << ' ';
	}
	cout << '\n';
	for (int i = 1; i <= m; i++) {
		while (1) {
			int u = getrand(1, n - 1), v = getrand(u + 1, n);
			if (abs(d[u] - d[v]) > 1 || f[{u, v}] == 1) continue;
			cout << u << " " << v << '\n';
			f[{u, v}] = 1;
			break;
		}
	}
}
