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
const ll nmax = 3e6;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, dem_u[nmax + 3], dem_b[nmax + 3];

bool have[nmax + 3];

int main() {
	fast;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		have[x] = 1;
	}
	ll res = 0;
	for (int i = 1; i <= nmax; i++) {
		if (!have[i]) continue;
		for (int j = i * 2; j <= nmax; j+=i) {
			dem_b[i] += have[j];
			dem_u[j] ++;
		}
		res += (1ll * dem_b[i] * 1ll * dem_u[i]);
	}
	cout << res;
}
