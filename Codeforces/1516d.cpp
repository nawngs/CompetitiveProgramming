#include <bits/stdc++.h>

#define name ""
#define test "test"
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
const int NMAX = 1e6;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, q, a[NMAX + 3], st[NMAX + 3][22], nxt[NMAX + 3];

vector < int > prime[NMAX + 3];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> q;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	for (int i = 2; i <= NMAX; i++) {
		nxt[i] = n + 1;
		if (!sz(prime[i]))
			for (int j = i; j <= NMAX; j+=i) 
				prime[j].push_back(i);
	}
	st[n + 1][0] = n + 1;
	for (int i = n; i >= 1;i--) {
		st[i][0] = st[i + 1][0];
		for (auto x : prime[a[i]]) {
			st[i][0] = min(st[i][0], nxt[x]);
			nxt[x] = i;
		}
	}
	for (int j = 1; j <= 20; j++)
		for (int i = 1; i <= n + 1; i++) {
				st[i][j] = st[st[i][j - 1]][j - 1];
		}
	while (q--) {
		int l, r, res = 0; cin >> l >> r;
		for (int j = 20; j >= 0; j--) {
			if (st[l][j] <= r) {
				res += (1 << j);
				l = st[l][j];
			}
		}
		cout << res + 1 << '\n';
	}
}