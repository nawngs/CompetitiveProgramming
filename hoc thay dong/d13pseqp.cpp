#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 1e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, a[NMAX + 3], b[NMAX + 3], posa[NMAX + 3], s[NMAX + 3], q;

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		posa[a[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		s[(posa[b[i]] + n - i) % n] ++; 
	}
	set < pii > ms;
	for (int i = 0; i < n; i++) ms.insert({s[i], i});
	while (q--) {
		int u, v; cin >> u >> v;
		u --, v --;
		int val = b[u], dis = (posa[val] + n - u) % n;
		ms.erase(ms.lower_bound({s[dis], dis}));
		s[dis] --; ms.insert({s[dis], dis});
		val = b[v], dis = (posa[val] + n - v) % n;
		ms.erase(ms.lower_bound({s[dis], dis}));
		s[dis] --; ms.insert({s[dis], dis});
		swap(b[u], b[v]);
		val = b[u], dis = (posa[val] + n - u) % n;
		ms.erase(ms.lower_bound({s[dis], dis}));
		s[dis] ++; ms.insert({s[dis], dis});
		val = b[v], dis = (posa[val] + n - v) % n;
		ms.erase(ms.lower_bound({s[dis], dis}));
		s[dis] ++; ms.insert({s[dis], dis});
		cout << ms.rbegin()->fi << '\n';
	}
}