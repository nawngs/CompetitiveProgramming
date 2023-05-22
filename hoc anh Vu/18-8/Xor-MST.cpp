#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 200000;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Node {
	int child[2];
	int cnt;
	int id;
} trie[nmax * 30];

ll res = 0;

int n, a[nmax + 1], root[nmax + 1], timer = 0;

vector < int > component[nmax + 1];

stack < pii > temp;

int find_root(int u) {
	return (root[u] == u ? u : root[u] = find_root(root[u]));
}

bool join(int u, int v) {
	
		int root_u = find_root(u);
		int root_v = find_root(v);
		if (root_u == root_v) return false;
		if (component[root_u].size() < component[root_v].size()) swap(root_u, root_v);
		for (auto x : component[root_v]) component[root_u].push_back(x);
		root[root_v] = root_u;
		return true;
	}

void update(int i, int x, int val) {
	int cur = 0;
	trie[cur].cnt += val;
	for (int i = 30; i >= 0; i--) {
		int bit = (x >> i) & 1;
		if (trie[cur].child[bit] == 0) trie[cur].child[bit] = ++ timer;
		cur = trie[cur].child[bit];
		trie[cur].cnt += val;
	}
	if (val == 1) trie[cur].id = i;
	else trie[cur].id = 0;
}
 
int query(int x) {
	int cur = 0;
	for (int i = 30; i >= 0; i--) {
		int bit = (x >> i) & 1;
		if (trie[cur].child[bit] > 0 && trie[trie[cur].child[bit]].cnt > 0) cur = trie[cur].child[bit]; 
		else cur = trie[cur].child[bit ^ 1];
	}
	return trie[cur].id;
}

int main() {
	//fast;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	 n = unique(a + 1, a + 1 + n) - (a + 1);
	for (int i = 1; i <= n; i++) {
		update(i, a[i], 1);
		component[i].push_back(i);
		root[i] = i;
	}
	//cout << trie[35].child[1] << " " << trie[35].child[0] << '\n';
	while ((int)component[find_root(1)].size() != n) {
		for (int i = 1; i <= n; i++) {
			int u = find_root(i);
			if (u != i) continue;
			for (auto x : component[u]) update(x, a[x], -1);
			int val = 2e9;
			pii ans;
			for (auto x : component[u]) {
				int pos = query(a[x]);
				if (val > (a[pos] ^ a[x])) {
					val = (a[pos] ^ a[x]);
					ans = {x, pos};
				}
			}
			temp.push(ans);
			for (auto x : component[u]) update(x, a[x], 1);
		}
		while(temp.size()) {
			pii x = temp.top();
			if (join(x.fi, x.se)) res += (a[x.fi] ^ a[x.se]);
			temp.pop();
		}
	}
	cout << res;
}
