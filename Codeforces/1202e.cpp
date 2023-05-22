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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, nxt[NMAX + 3][26], jump[NMAX + 3][26], f[NMAX + 3], cnt[NMAX + 3], node = 0, dp[2][NMAX + 3];

string t, s[200003];

void add_string(string s) {
	int cur = 0;
	for (auto c : s) {
		if (!nxt[cur][c - 'a'])
			nxt[cur][c - 'a'] = ++node;
		cur = nxt[cur][c - 'a'];
	}
	cnt[cur] ++;
}

void build() {
	queue < int > Q;
	Q.push(0);
	while (Q.size()) {
		int i = Q.front(); Q.pop();
		cnt[i] += cnt[f[i]];
		for (int j = 0; j < 26; j++) if (nxt[i][j]) {
			int x = nxt[i][j];
			f[x] = jump[f[i]][j];
			jump[i][j] = x;
			Q.push(x);
		}
		else jump[i][j] = jump[f[i]][j];
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> t >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		add_string(s[i]);
	}
	build();
	int cur = 0;
	for (int i = 0; i < sz(t); i++) {
		cur = jump[cur][t[i] - 'a'];
		dp[0][i] = cnt[cur];
	}
	memset(nxt, 0, sizeof(nxt)); memset(jump, 0, sizeof(jump));
	memset(f, 0, sizeof(f)); memset(cnt, 0, sizeof(cnt));
	node = 0;
	for (int i = 1; i <= n; i++) {
		reverse(s[i].begin(), s[i].end());
		add_string(s[i]);
	} 
	build();
	cur = 0; reverse(t.begin(), t.end());
	for (int i = 0; i < sz(t); i++) {
		cur = jump[cur][t[i] - 'a'];
		dp[1][i] = cnt[cur];
	}
	ll res = 0;
	for (int i = 0; i < sz(t); i++) {
		res += 1ll * dp[0][i] * 1ll * dp[1][sz(t) - 2 - i];
	}
	cout << res;
}