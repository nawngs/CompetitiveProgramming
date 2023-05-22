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

const string NAME = "grtravel";
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

ll n, m, cnt[100003];

int main() {
	fast;
	fre();
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cnt[i] = i - 1;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		cnt[v] --;
		cnt[u] ++;
	}
	ll res = n * (n - 1) * (n - 2) / 6;
	for (int i = 1; i <= n; i++) 
		res -= cnt[i] * (cnt[i] - 1) / 2;
	cout << res << '\n';
}
