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
const int NMAX = 100;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, m, k, invalid[NMAX + 3], len = 0, res = 0, a[NMAX + 3];

void back_track(ll cur, ll avail) {
	int cnt_cur = __builtin_popcountll(cur);
	int cnt_avail = __builtin_popcountll(avail);
	if (cnt_cur + cnt_avail <= len) return ;
	if (cnt_cur > len) {
		len = cnt_cur;
		res = cur;
	}
	for (int i = 0; i < n; i++) if (avail >> i & 1) {
		back_track(cur, avail ^ (1ll << i));
		back_track(cur ^ (1ll << i), avail & (~invalid[i]));
		return ;
	}
}

void sol() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		invalid[i] = (1ll << i);
	}
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v; u--, v --;
		invalid[u] ^= (1ll << v); invalid[v] ^= (1ll << u);
	}
	back_track(0, (1ll << n) - 1);
	len ^= 1;
	if (len - 1 < k) {
		cout << -1 << '\n';
		return ;
	}
	vector < int > choose, ans;
	for (int i = 0; i < n; i++) if (len && (res >> i & 1)) len --, choose.pb(i);
	cout << choose.size() << '\n';
	for (auto x : choose) cout << x + 1 << " ";
	cout << '\n';
	ans = choose;
	while (k--) {
		for (int i = 0; i < ans.size() / 2; i++) 
			cout << ans[i] + 1 << " " << ans[i + ans.size() / 2] + 1 << " "; 
		cout << '\n';
		choose.clear();
		choose.pb(ans[0]); choose.pb(ans[ans.size() / 2]);
		for (int i = 1; i < ans.size() / 2 - 1; i++) choose.pb(ans[i]);
		for (int i = ans.size() / 2 + 1; i < ans.size(); i++) choose.pb(ans[i]);
		choose.pb(ans[ans.size() / 2 - 1]);
		ans = choose;
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}
