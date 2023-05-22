/*
while (a[i] > a[s.top()] {
	r = s.top(); s.pop();
	l = s.top() + 1;
	max(j,i)-max(j,i-1)=a[i]-a[r];
}
1->i += a[i]*/
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

int n, a[50003];

ll it[200003], lazy[200003];

map < int, int > sub_gcd[50003];

vector < pii > f;

void update(int node, int l, int r, int u, int v, int val) {
	if (lazy[node] != 0) {
		it[node] += lazy[node];
		if (l != r) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		it[node] += 1ll * val;
		if (l != r) {
			lazy[node * 2] += 1ll * val;
			lazy[node * 2 + 1] += 1ll * val;
		}
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, u, v, val);
	update(node * 2 + 1, mid + 1, r, u, v, val);
	it[node] = max(it[node * 2], it[node * 2 + 1]);
}

ll query(int node, int l, int r, int u, int v) {
	if (lazy[node] != 0) {
		it[node] += lazy[node];
		if (l != r) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (v < l || r < u) return -1E18;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return max(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

int main() {
	//fast;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sub_gcd[1][a[1]] = 0;
	for (int i = 2; i <= n; i++) {
		sub_gcd[i][a[i]] = 0;
		for (auto it : sub_gcd[i - 1]) {
			//cout << i << " " << it.fi << " " << it.se << '\n';
			int new_gcd = __gcd(it.fi, a[i]);
			sub_gcd[i][new_gcd] = max(sub_gcd[i][new_gcd], it.se + 1);
		}
	}
	stack < int > st;
	st.push(0);
	a[0] = INF;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		while (a[i] > a[st.top()]) {
			int r = st.top();
			st.pop();
			int l = st.top() + 1;
			update(1, 1, n, l, r, a[r] - a[i]);
		}
		st.push(i);
		update(1, 1, n, 1, i, a[i]);
		cout << i << '\n';
		for (int j = 1; j <= n; j++) cout << query(1, 1, n, j, j) << ' ';
		cout << '\n';
		// f.clear();
		// for (auto it : sub_gcd[i]) f.push_back({it.se, it.fi});
		// sort(f.begin(), f.end());
		//for (auto x : f) cout << i << " " << x.fi << " " << x.se << '\n';
		//for (int j = 1; j < f.size(); j++) ans = max(ans, 1ll * f[j].se * query(1, 1, n, i - f[j].fi, i - f[j - 1].fi - 1));
		// for (int j = 1; j < f.size(); j++) 
		// 	cout << i << " " << f[j].se << " " << query(1, 1, n, i - f[j].fi, i - f[j - 1].fi - 1) << '\n';
	}
	cout << ans;
}
