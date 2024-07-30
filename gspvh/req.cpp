#include <bits/stdc++.h>

#define name "req"
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

const string NAME = "req";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const int N = 4E5;
const int Q = 1e6;
const int NMAX = 1E7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, q, p, pre[NMAX + 3], f[NMAX + 3], it[4 * N + 3], res[Q + 3];

struct Data {
	int l, r, val;
	bool IsQuery;
	Data (int _l, int _r, int _val, bool _IsQuery) : l(_l), r(_r), val(_val), IsQuery(_IsQuery) {};
};

vector < Data > a;

void sieve() {
	f[1] = 1;
	vector < int > p;
    for (int i = 2; i <= NMAX; i++) {
        if (f[i] == 0) f[i] = i, p.push_back(i);
        for (int j = 0; j < SZE(p) && p[j] <= f[i] && p[j]*i <= NMAX; j++) {
            f[p[j]*i] = p[j];
        }
    }
}


void build(int node, int l, int r) {
	it[node] = 1;
	if (l == r) return ;
	build(lnode); build(rnode);
}

void update(int node, int l, int r, int pos, pii val) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node] /= val.se;
		it[node] *= val.fi;
		return ;
	}	
	update(lnode, pos, val); update(rnode, pos, val);
	it[node] = (it[node * 2] * it[node * 2 + 1]) % p;
}

void update(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node] *= val;
		return ;
	}	
	update(lnode, pos, val); update(rnode, pos, val);
	it[node] = (it[node * 2] * it[node * 2 + 1]) % p;
}

ll query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 1;
	if (u <= l && r <= v) return it[node];
	return (query(lnode, u, v) * query(rnode, u, v)) % p;
}

signed main() {
	fast;
	fre();
	sieve();
	int sub; cin >> sub;
	cin >> n >> q >> p;
	build(1, 1, n);
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		a.pb({i, i, x, 0});
	}
	for (int i = 1; i <= q; i++) {
		int l, r; cin >> l >> r;
		a.pb({l, r, i, 1});
	}
	sort(a.begin(), a.end(), [&](Data &x, Data &y) {
		if (x.r == y.r) return (!x.IsQuery);
		return x.r < y.r;
	});
	memset(pre, 255, sizeof pre);
	vector < int > prime;
	for (auto q : a) {
		if (q.IsQuery) res[q.val] = query(1, 1, n, q.l, q.r);
		else {
			int tmp = q.val;
			prime.clear();
			while (q.val > 1) {
				if (prime.empty() || prime.back() != f[q.val]) prime.pb(f[q.val]);
				q.val /= f[q.val];
			}
			
			for (auto x : prime) {
				assert(pre[x] != q.l);
				if (pre[x] != -1) update(1, 1, n, pre[x], {x, x - 1});
				tmp /= x; tmp *= x - 1; pre[x] = q.l;
			}
			update(1, 1, n, q.l, tmp);
		}
	}
	for (int i = 1; i <= q; i++) cout << res[i] % p << " ";
}
