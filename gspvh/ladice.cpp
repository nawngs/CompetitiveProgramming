#include <bits/stdc++.h>

#define name "ladice"
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
const int NMAX = 3e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int par[NMAX + 3], n, l, a, b, i;

int vs[NMAX + 3];

int find(int x) {
	if (vs[x] == i || x == 0) return 0;
	if (par[x] == x) return x;
	vs[x] = i;
	return par[x] = find(par[x]);
}

bool check(int x) {
	if (par[a] == a) {
		par[a] = b;
		return true;
	}
	if (par[b] == b) {
		par[b] = a;
		return true;
	}
	if (find(a)) {
		par[par[a]] = b;
		return true;
	}
	if (find(b)) {
		par[par[b]] = 0; 
		return true;
	}
	return false;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> l;
	for (int i = 1; i <= l; i++) par[i] = i;
	for (i = 1; i <= n; i++) {
		cin >> a >> b;
		cout << (check(i) ? "Yes" : "No") << '\n';
	}
	
}