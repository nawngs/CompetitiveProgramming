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
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;
const int BLOCK_SIZE = 450;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, k, language[100003], timer, num[100003], tail[100003], val[100003], res[100003], cnt[100003];

pair < int, int > p[100003];

vector < int > adj[100003];

void dfs(int u) {
	num[u] = ++ timer;
	val[timer] = u;
	for (auto v : adj[u]) dfs(v);
	tail[u] = timer;
	p[u] = {num[u] - 1, tail[u]};
}

int main() {
	fast;
	cin >> n >> m >> k;
	for (int i = 2; i <= n; i++) {
		int p;
		cin >> p;
		adj[p].push_back(i);
	}
	for (int i = 1; i <= n; i++) cin >> language[i];
	dfs(1);
	sort(p + 1, p + n + 1, [&](pii &x, pii &y) {
		if (x.fi / BLOCK_SIZE == y.fi / BLOCK_SIZE) return x.se < y.se;
		else return x.fi < y.fi;
	});
	cnt[0] = -1e9;
	int l = 0, r = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		//cout << val[p[i].fi + 1] << " " << p[i].fi << " " << p[i].se << " " << l << " " << r << " " << ans << '\n';
		while (l < p[i].fi) {
			++ l;
			int x = language[val[l]];
			cnt[x] --;
			ans -= (cnt[x] == 0);
			ans += (cnt[x] == k);
		}
		while (l > p[i].fi) {
			int x = language[val[l]];
			//if (i == 2) cout << x << " " << cnt[x] << '\n';
			ans -= (cnt[x] == k);
			ans += (cnt[x] == 0);
			cnt[x] ++;	
			l --;	
		}
		while (r < p[i].se) {
			++ r;
			int x = language[val[r]];
			//if (i == 2) cout << val[r] << " " << x << " " << cnt[x] << '\n';
			ans += (cnt[x] == 0);
			ans -= (cnt[x] == k);
			cnt[x] ++;
		}
		while (r > p[i].se) {
			int x = language[val[r]];
			cnt[x] --;
			ans += (cnt[x] == k);
			ans -= (cnt[x] == 0);
			r --;		
		}
		res[val[p[i].fi + 1]] = ans;
	}
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		cout << res[x] << "\n";
	}
}
