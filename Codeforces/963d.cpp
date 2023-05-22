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
const int NMAX = 1e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, nxt[NMAX + 3][26], jump[NMAX + 3][26], cnt_node = 0, ed[NMAX + 3], k[NMAX + 3], f[NMAX + 3], pre[NMAX + 3];

string s, m[NMAX + 3];

vector < int > pos[NMAX + 3];

void add(int id) {
	int cur = 0;
	for (auto c : m[id]) {
		if (!nxt[cur][c - 'a']) 
			nxt[cur][c - 'a'] = ++cnt_node;
		cur = nxt[cur][c - 'a'];
	}
	ed[cur] = id;
}

void build() {
	queue < int > Q;
	Q.push(0);
	while (!Q.empty()) {
		int i = Q.front(); Q.pop();
		for (int j = 0; j < 26; j++) if (nxt[i][j]) {
			int x = nxt[i][j];
			f[x] = jump[f[i]][j];
			jump[i][j] = x;
			Q.push(x);
			if (ed[f[x]]) pre[x] = f[x];
			else pre[x] = pre[f[x]]; 
		} else jump[i][j] = jump[f[i]][j];
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> s >> n;
	for (int i = 1; i <= n; i++) {
		cin >> k[i] >> m[i];
		add(i);
	}
	build();
	int cur = 0;
	for (int i = 0; i < sz(s); i++) {
		cur = jump[cur][s[i] - 'a'];
		int x = cur;
		while (x) {
			if (ed[x]) 
				pos[ed[x]].push_back(i);
			x = pre[x];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (sz(pos[i]) < k[i]) {
			cout << -1 << '\n';
			continue;
		}
		int res = INF;
		for (int j = k[i] - 1; j < sz(pos[i]); j++) 
			res = min(res, pos[i][j] - pos[i][j - k[i] + 1] + sz(m[i]));
		cout << res << '\n';
	}
}