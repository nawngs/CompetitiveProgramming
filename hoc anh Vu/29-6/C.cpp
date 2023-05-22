/*
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
const ll ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;
const ll BLOCK_SIZE = 700;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Query {
	int l, r, index;
} q[500003];

int n, m, a[500003], lef[500003], righ[500003], res[500003];

vector < int > val;

void getmin(int &x, int y) {
	x = min(x, y);
	return ;
}

int main() {
	fast;	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		val.push_back(a[i]);
	}
	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());
	for (int i = 0; i < n; i++) 
		a[i] = lower_bound(val.begin(), val.end(), a[i]) - val.begin();
	for (int i = 0; i < m; i++) {
		cin >> q[i].l >> q[i].r;
		q[i].l --;
		q[i].r --;
		q[i].index = i;
	}
	sort(q, q + m, [&](Query &x, Query &y) {
		return (x.l / BLOCK_SIZE == y.l / BLOCK_SIZE ? x.r < y.r : x.l < y.l);
	});
	memset(lef, 0xc0, sizeof lef);
	for (int i = 0; i < m; i++) {
		if (q[i].r - q[i].l <= BLOCK_SIZE) {
			res[q[i].index] = INF;
			for (int j = q[i].l; j <= q[i].r; j++) {
				getmin(res[q[i].index], j - lef[a[j]]);
				lef[a[j]] = j;
			}
			for (int j = q[i].l; j <= q[i].r; j++) lef[a[j]] = -INF;
		}
	}
	int last_block = -1, l, r, temp;
	for (int i = 0; i < m; i++) {
		if (q[i].r - q[i].l <= BLOCK_SIZE) continue;
		res[q[i].index] = INF;
		if (q[i].l / BLOCK_SIZE != last_block) {
			memset(lef, 0xc0, sizeof lef);
            memset(righ, 0x3f, sizeof righ);
			last_block = q[i].l / BLOCK_SIZE;
			l = (last_block + 1) * BLOCK_SIZE;
			r = l - 1;
			temp = INF;
		}
		while (r < q[i].r) {
			r++;
			getmin(temp, r - lef[a[r]]);
			lef[a[r]] = r;
			if (righ[a[r]] > n) righ[a[r]] = r;
		}
		getmin(res[q[i].index], temp);
		stack < int > st;
		while (l > q[i].l) {
			l --;
			st.push(righ[a[l]]);
			getmin(res[q[i].index], righ[a[l]] - l);
			righ[a[l]] = l;
		}
		while (st.size()) {
			righ[a[l]] = st.top();
			st.pop();
			l ++;
		}
	}
	for (int i = 0; i < m; i++) cout << (res[i] > n ? -1 : res[i]) << '\n';
}
*/

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
const ll ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Query {
	int l, r, index;
} q[500003];


int n, m, a[500003], it[2000003], res[500003];

map < int, int > pre;

void update(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node] = val;
		return ;
	}
	update(node * 2, l, (l + r) / 2, pos, val);
	update(node * 2 + 1, (l + r) / 2 + 1, r, pos, val);
	it[node] = min(it[node * 2], it[node * 2 + 1]);
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return INF;
	if (u <= l && r <= v) return it[node];
	return min(query(node * 2, l, (l + r) / 2, u, v), query(node * 2 + 1, (l + r) / 2 + 1, r, u, v));
}

int main() {
	fast;
	//fre();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) {
		cin >> q[i].l >> q[i].r;
		q[i].index = i;
	}
	sort(q + 1, q + m + 1, [&](Query &x, Query &y) {
		return x.r < y.r;
	});
	int cur = 0;
	fill(it + 1, it + 4 * n + 1, INF);
	for (int i = 1; i <= m; i++) {
		for (int j = cur + 1; j <= q[i].r; j++) {
			if (pre[a[j]] != 0) update(1, 1, n, pre[a[j]], j - pre[a[j]]);
			pre[a[j]] = j;
		}
		cur = q[i].r;
		res[q[i].index] = query(1, 1, n, q[i].l, q[i].r);
	}
	for (int i = 1; i <= m; i++) cout << (res[i] > n ? -1 : res[i]) << '\n';
}

