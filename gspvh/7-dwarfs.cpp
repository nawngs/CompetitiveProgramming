#include <bits/stdc++.h>

#define name "7-dwarfs"
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
const int NMAX = 1000;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n;

vector < int > id[NMAX + 3];

pair < string, int > a[103];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) 
		id[a[i].se].pb(i);
	for (int i = 0; i <= NMAX; i++) if (id[i].size() == 7) {
		for (auto x : id[i]) cout << a[x].fi << " ";
		return 0;
	}
}