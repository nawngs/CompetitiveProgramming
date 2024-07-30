#include <bits/stdc++.h>

#define name "obilazak"
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

int n, a[NMAX + 3];

vector < int > res[11];

void solve(int l, int r, int dep) {
	int mid = (l + r) / 2;
	res[dep].pb(a[mid]);
	if (l == r) return ;
	solve(l, mid - 1, dep + 1); solve(mid + 1, r, dep + 1);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i < (1 << n); i++) 
		cin >> a[i];
	solve(1, (1 << n) - 1, 1);
	for (int i = 1; i <= n; i++) {
		for (auto x : res[i]) cout << x << " ";
		cout << '\n';
	}
}