#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define int ll
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "cheating";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 2e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Coder {
	int b, c, id;
} a[(1 << 18) + 5];

int n, m, s, res[(1 << 18) + 5];

pii problems[(1 << 18) + 5];

bool check(int x) {
	int r = 1, i = 1;
	ll total = 0;
	priority_queue < int, vector < int >, greater < int > > heap;
	while (i <= m) {
		while (r <= n && a[r].b >= problems[i].fi) {
			heap.push(a[r].c);
			r ++;
		}
		if (!heap.size()) return false;
		total += 1ll * heap.top();
		heap.pop();
		i = i + x;
	}
	return (total <= s);
}

void sol() {
	cin >> n >> m >> s;
	for (int i = 1; i <= m; i++) {
		cin >> problems[i].fi;
		problems[i].se = i;
	}
	for (int i = 1; i <= n; i++)
		cin >> a[i].b;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].c;
		a[i].id = i;
	}
	sort(problems + 1, problems + m + 1, greater < pii > ());
	sort(a + 1, a + n + 1, [&](Coder &x, Coder &y) {
		return x.b > y.b;
	});
	a[n + 1].b = 0;
	int l = 1, r = m, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	if (ans == -1) {
		cout << "NO" << '\n';
		return ;
	}
	int i = 1;
	r = 1;
	priority_queue < pii, vector < pii >, greater < pii > > heap;
	while (i <= m) {
		while (r <= n && a[r].b >= problems[i].fi) {
			heap.push({a[r].c, a[r].id});
			r ++;
		}
		for (int j = i; j < min(i + ans, m + 1); j++)
			res[problems[j].se] = heap.top().se;
		heap.pop();
		i += ans;
	}
	cout << "YES" << '\n';
	for (int i = 1; i <= m; i++)
		cout << res[i] << " ";
	cout << '\n';
}

main() {
	fast;
	fre();
	int O; cin >> O;
	int t = 1;
	cin >> t;
	while (t --) sol();
}
