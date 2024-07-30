#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define piii pair < int, pii >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e6;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, a[1003][1003];

vector < int > szea, szeb;

vector < piii > resa, resb;

void solve(vector < int > &sze, vector < piii > &res) {
	int dem = 0, st = 1;
	for (int currw = 1; currw <= n; currw++) {
		int pos = -1;
		for(int i = currw; i <= n; i++) if (a[i][currw] == 1) {
				pos = i;
				break;
		}
		assert(pos != -1);
		if(currw != pos) res.pb({1, {currw, pos}});
		for (int j = 1; j <= n; j++) swap(a[currw][j], a[pos][j]);
		if (a[currw][st] == -1) {
			sze.pb(dem);
			st = currw + 1;
			dem = 0;
		}
		else {
			dem ++;
			pos = -1;
			for (int j = currw + 1; j <= n; j++) if (a[currw][j] == -1) {
				pos = j;
				break;
			}
			assert(pos != -1);
			if (currw + 1 != pos) res.pb({2, {currw + 1, pos}});
			for (int i = 1; i <= n; i++) swap(a[i][currw + 1], a[i][pos]);
		}
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) 
	for (int j = 1; j <= n; j++) cin >> a[i][j];
	solve(szea, resa);
	for (int i = 1; i <= n; i++) 
	for (int j = 1; j <= n; j++) cin >> a[i][j];
	solve(szeb, resb);
	// for (auto x : szea) cout << x << " ";
	// cout << '\n';
	// for (auto x : szeb) cout << x << " ";
	// cout << '\n';
	if (szea != szeb || resa.size() + resb.size() > INF) {
		cout << -1 << '\n';
		return 0;
	}
	cout << resa.size() + resb.size() << '\n';
	for (auto x : resa) cout << x.fi << " " << x.se.fi << " " << x.se.se << '\n';
	reverse(resb.begin(), resb.end());
	for (auto x : resb) cout << x.fi << " " << x.se.fi << " " << x.se.se << '\n';
	
}