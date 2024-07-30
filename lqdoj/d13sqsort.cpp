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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, k;

vector < pii > a[45], b;

vector < int > res;

void solve(int id, int l, int r) {
	if (id == 2 * n + 1 || l > r) return ;
	int mid = (l + r) / 2;
	for (auto x : a[id]) {
		if (x <= b[mid]) {
			res.pb(id); res.pb(id + 1);
			a[id + 2].pb(x);
		}
		else {
			res.pb(id);
			a[id + 1].pb(x);
		}
	}
	a[id].clear();
	solve(id + 2, l, mid);
	reverse(a[id + 1].begin(), a[id + 1].end());
	for (auto x : a[id + 1]) res.pb(id + 1), a[id + 2].pb(x);
	a[id + 1].clear();
	solve(id + 2, mid + 1, r);
	
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		int x; cin >> x;
		a[1].pb({x, i});
		b.pb({x, i});
	}
	sort(b.begin(), b.end());
	solve(1, 0, k - 1);
	// for (auto x : a[2 * n + 1]) cout << x.fi << " ";
	// cout << '\n';
	cout << res.size() << '\n';
	for (auto x : res) cout << x << " ";
}