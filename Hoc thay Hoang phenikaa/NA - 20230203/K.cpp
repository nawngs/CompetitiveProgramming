#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2e6;

int n, m, a[1000003], b[1000003];

pii pos[2 * BASE + 3];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> m;
	for (int i = 1; i <= m; i++)
		cin >> b[i];
	int ia = 0, ib = 0, cur = BASE;
	for (int i = 0; i <= 2 * BASE; i++) pos[i] = {-1, -1};
	pos[cur] = {ia, ib};
	while (1) {
		if (cur <= BASE) cur += a[++ ia];
		else cur -= b[++ ib];
		if (pos[cur] == mp(-1, -1)) pos[cur] = {ia, ib};
		else {
			cout << ia - pos[cur].fi << '\n';
			for (int i = pos[cur].fi; i < ia; i++) cout << i << " ";
			cout << '\n' << ib - pos[cur].se << '\n';
			for (int i = pos[cur].se; i < ib; i++) cout << i << ' ';
			cout << '\n';
			return 0;
		}
	}
}