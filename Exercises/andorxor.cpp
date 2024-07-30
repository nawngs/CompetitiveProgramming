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
const int N = 5e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, q, a[N + 3];

string s, t;

struct Node {
	ll vx, vo, va, ux, uo, ua, sze;
	Node (ll x = 0, ll y = 0) {
		vx = vo = va = x;
		ux = uo = ua = 0;
		sze =y;
	}
} it[6 * N + 3];

void merge(Node &ans, const Node &x, const Node &y) {
	ans.vx = x.vx ^ y.vx;
	ans.vo = x.vo ^ y.vo;
	ans.va = x.va ^ y.va;
	ans.sze = x.sze + y.sze;
}

void build(int node, int l, int r) {
	if (l == r) {
		it[node] = Node(a[l], r - l + 1);
		return ;
	}
	build(lnode); build(rnode);
	merge(it[node], it[node * 2], it[node * 2 + 1]);
}

void updx(int node, int l, int r, int u, int v, ll x) {
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	while (q--) {
		ll l, r, x;
		cin >> s >> t >> l >> r;
		if (s == "upd") {
			cin >> x;
		}
		else {
			
		}
	}
}