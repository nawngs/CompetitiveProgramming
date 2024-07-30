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
const int N = 1e6;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, a[N + 3], r[N + 3], it[4 * N + 3];

vector < int > pos[N + 3];

void update(int node, int l, int r, int u) {
	if (u < l || r < u) return ;
	it[node] ++;
	if (l == r) return ;
	update(lnode, u); update(rnode, u);
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	return query(lnode, u, v) + query(rnode, u, v);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	stack < int > st;
	a[0] = LINF; st.push(0);
	for (int i = 1; i <= n; i++) {
		while (a[st.top()] <= a[i]) st.pop();
		pos[st.top() + 1].pb(i);
		st.push(i);
	}
	while (st.size()) st.pop();
	a[n + 1] = -LINF; st.push(n + 1);
	for (int i = n; i >= 1; i--) {
		while (a[st.top()] >= a[i]) st.pop();
		r[i] = st.top() - 1;
		st.push(i);
	}
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		for (auto x : pos[i]) update(1, 1, n, x);
		//cout << i << " " << r[i] << " " << query(1, 1, n, i, r[i]) << '\n';
		res += 1ll * query(1, 1, n, i, r[i]);
	}
	cout << res;
}