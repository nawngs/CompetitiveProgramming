#include <bits/stdc++.h>
#define FNAME "candy"
using namespace std;

#define BIT(x, i) ((x) >> (i) & 1)

typedef pair<int, int> pii;
#define fi first
#define se second

using ll = long long;

const int N = 2e5 + 5;
const ll oo = LLONG_MAX;

struct node {
	ll a = oo, b = oo;
	node() {}
	node(ll a, ll b) : a(a), b(b) {}
	node operator + (const node &x) const {
		return node(min(a, x.a), min(b, x.b));
	}
} st[4 * N];

int n;
ll s[N], m, A, B;

void upd(int id, int l, int r, int x, ll val) {
	if (l > x || r < x) return;
	if (l == r) {
		st[id].a = val - s[l] * A;
		st[id].b = val + s[l] * B;
		return; 
	}
	int mi = (l + r) / 2;
	upd(2 * id, l, mi, x, val);
	upd(2 * id + 1, mi + 1, r, x, val);
	st[id] = st[2 * id] + st[2 * id + 1];
} 

node get(int id, int l, int r, int u, int v) {
	if (l > v || r < u) return node();
	if (u <= l && r <= v) return st[id];
	int mi = (l + r) / 2;
	return get(2 * id, l, mi, u, v) +
				 get(2 * id + 1, mi + 1, r, u, v);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	if (fopen(FNAME".inp", "r")) {
		freopen(FNAME".inp", "r", stdin);
		freopen(FNAME".out", "w", stdout);
	}
	cin >> n >> m >> A >> B;
	for (int i = 1; i <= n; ++i)
		cin >> s[i], s[i] += s[i - 1];
	ll dp = 0;
	upd(1, 0, n, 0, dp);
	for (int i = 1, j = 0; i <= n; ++i) {
		while (j < i && s[i] - s[j] >= m) ++j;
		ll ansA = oo, ansB = oo;
		if (j - 1 >= 0) 
			ansA = get(1, 0, n, 0, j - 1).a + s[i] * A - m * A;
		if (j < i) 
			ansB = get(1, 0, n, j, i - 1).b - s[i] * B + m * B;
		dp = min(ansA, ansB); 
		upd(1, 0, n, i, dp);
	}
	cout << dp;
	return 0;
}