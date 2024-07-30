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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, k, c;

struct Data {
	int val, event, id;
	Data() {
		val = event = id = 0;
	}
	Data(int _val, int _event, int _id) : val(_val), event(_event), id(_id) {}
	bool operator < (const Data &oth) {
		return val > oth.val;
	}
};

using B = bitset < 503 >;

vector < Data > a;

struct State {
	B ban;
	vector < int > selected;
	int val = 0, fix = 0;
	int visited[8];
	State (B _ban, int _fix) : ban(_ban), fix(_fix) {
		selected.clear(); val = 0;
		for (int i = 1; i <= k; i++) visited[i] = 0;
		for (auto x : a) {
			if (ban[x.id]) continue;
			if (visited[x.event]) continue;
			val += x.val; visited[x.event] = 1;
			bool ok = 1;
			for (auto y : selected) if (y == x.id) ok = false;
			if (ok) selected.pb(x.id);
		}
		for (auto x : a) {
			if (SZE(selected) == k) break;
			if (ban[x.id]) continue;
			bool ok = 1;
			for (auto y : selected) if (y == x.id) ok = false;
			if (ok) selected.pb(x.id);
		}
	}
};

bool operator < (const State &l, const State &r) {
	return l.val < r.val;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k >> c;
	for (int i = 1; i <= n; i++) 
	for (int j = 1; j <= k; j++) {
		int x; cin >> x;
		a.pb({x, j, i});
	}
	sort(a.begin(), a.end());
	priority_queue < State > heap;
	heap.push({B(), 0});
	while (c--) {
		auto u = heap.top(); heap.pop();
		// cout << u.val << '\n';
		// for (auto x : u.selected) cout << x << ' ';
		// cout << '\n';
		if (c == 0) {
			cout << u.val << '\n';
			return 0;
		}
		while (u.fix < SZE(u.selected)) {
			B t = u.ban;
			t[u.selected[u.fix]] = 1;
			auto A = State(t, u.fix);
			if (SZE(A.selected) == k) heap.push(A);
			u.fix ++;
		}
	}
}