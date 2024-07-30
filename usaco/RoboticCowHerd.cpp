#include <bits/stdc++.h>

#define name "roboherd"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define plll pair < ll, pii >
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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, k;

vector < ll > v;

vector < vector < ll > > a;

int main() {
	fast;
	if(fopen(name".in", "r")) {
		freopen(name".in", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k;
	ll st = 0;
	for (int i = 1; i <= n; i++) {
		int m; cin >> m; v.resize(m);
		for (auto &x : v) cin >> x;
		sort(v.begin(), v.end());
		st += v[0];
		for (int j = m - 1; j >= 0; j--) v[j] -= v[0];
		if (m > 1) a.pb(v);
	}
	sort(a.begin(), a.end());
	priority_queue < plll, vector < plll >, greater < plll > > heap;
	heap.push({0, {0, 0}});
	ll res = 0;
	while (k--) {
		int val, id, pos;
		val = heap.top().fi; tie(id, pos) = heap.top().se; heap.pop();
		res += val + st;
		if (pos + 1 < SZE(a[id])) heap.push({val + a[id][pos + 1] - a[id][pos], {id, pos + 1}});
		if (id + 1 < SZE(a)) {
			if (pos == 1) heap.push({val - a[id][1] + a[id + 1][1], {id + 1, 1}});
			if (pos) heap.push({val + a[id + 1][1], {id + 1, 1}});
		}
	}
	cout << res;
}