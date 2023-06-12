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

int n, m, k, lazy[400003];

struct Node {
	int cnt[11][11], lst, frst;
} it[400003];

string s;

void build(int node, int l, int r) {
	if (l == r) {
		it[node].lst = it[node].frst = s[l] - 'a';
		return ;
	}
	int mid = (l + r) / 2;
	build(node * 2, l, mid); build(node * 2 + 1, mid + 1, r);
	for (int i = 0; i < k; i++) 
		for (int j = 0; j < k; j++) 
			it[node].cnt[i][j] = it[node * 2].cnt[i][j] + it[node * 2 + 1].cnt[i][j];
	it[node].cnt[it[node * 2].lst][it[node * 2 + 1].frst] ++;
	it[node].lst = it[node * 2 + 1].lst; it[node].frst = it[node * 2].frst;
} 

void update(int node, int l, int r) {
	if (lazy[node] != -1) {
		memset(it[node].cnt, 0, sizeof(it[node].cnt));
		it[node].cnt[lazy[node]][lazy[node]] = r - l;
		it[node].lst = it[node].frst = lazy[node];
		if (l != r) 
			lazy[node * 2] = lazy[node * 2 + 1] = lazy[node];
		lazy[node] = -1;
	}
}

void update(int node, int l, int r, int u, int v, int val) {
	update(node, l, r);
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		lazy[node] = val; 
		return update(node, l, r);
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, u, v, val); update(node * 2 + 1, mid + 1, r, u, v, val);
	for (int i = 0; i < k; i++) 
		for (int j = 0; j < k; j++) 
			it[node].cnt[i][j] = it[node * 2].cnt[i][j] + it[node * 2 + 1].cnt[i][j];
	it[node].cnt[it[node * 2].lst][it[node * 2 + 1].frst] ++;
	it[node].lst = it[node * 2 + 1].lst; it[node].frst = it[node * 2].frst;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	cin >> n >> m >> k >> s;
	s = ' ' + s;
	build(1, 1, n);
	memset(lazy, 255, sizeof(lazy));
	while (m--) {
		int type; cin >> type;
		if (type == 1) {
			int l, r; char c; cin >> l >> r >> c; 
			update(1, 1, n, l, r, c - 'a');
		}
		else {
			string str; cin >> str;
			int ans = 1;
			for (int i = 0; i < k; i++)
				for (int j = i; j < k; j++) ans += it[1].cnt[str[j] - 'a'][str[i] - 'a'];
			cout << ans << '\n';
		}
	}
}