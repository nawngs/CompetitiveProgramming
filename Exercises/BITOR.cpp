#include <bits/stdc++.h>

#define int ll
#define name "bitor"
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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, a[200003], st[200003][19], f[30], pre[200003], nxt[200003];

int get(int l, int r) {
	int k = log2(r - l + 1);
	if (a[st[l][k]] > a[st[r - (1 << k) + 1][k]]) return st[l][k];
	else return st[r - (1 << k) + 1][k];
}

ll solve(int l, int r) {
	if (r <= l) return 0;
	ll res = 0;
	int pos = get(l, r);
	int low = max(pre[pos], l), high = min(nxt[pos], r);
	res = res + (pos - l + 1) * (r - pos + 1) - (pos - low + 1) * (high - pos + 1);
	return res + solve(l, pos - 1) + solve(pos + 1, r);
}

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		st[i][0] = i;
	}
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			int nxt = i + (1 << (j - 1));
			if (a[st[i][j - 1]] > a[st[nxt][j - 1]]) 
				st[i][j] = st[i][j - 1];
			else st[i][j] = st[nxt][j - 1];
		}
	for (int i = 1; i <= n; i++) {
		pre[i] = 0;
		for (int bit = 0; bit < 30; bit++) {
			if (!(a[i] >> bit & 1)) pre[i] = max(pre[i], f[bit] + 1);
			else f[bit] = i;
		}	
	}
	for (int i = 0; i < 30; i++) f[i] = n + 1;
	for (int i = n; i >= 1; i--) {
		nxt[i] = n + 1;
		for (int bit = 0; bit < 30; bit++) {
			if (!(a[i] >> bit & 1)) nxt[i] = min(nxt[i], f[bit] - 1);
			else f[bit] = i;
		}	
	}
	cout << solve(1, n);
}