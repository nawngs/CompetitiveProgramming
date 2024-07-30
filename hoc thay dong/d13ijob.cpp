#include <bits/stdc++.h>

#define int long long
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
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

struct Job {
	int w, t;
	Job(){};
	Job (const int &_w, const int &_t) {
		w = _w;
		t = _t;
	}
	bool cmp(const Job &y) {
		return (w * y.t) > (y.w * t);
	}
} a[200003];

struct CustomCompare {
	bool operator()(const Job& x, const Job& y) {
		return (x.w * y.t) < (y.w * x.t);
	}
};

ll ans = 0;

int n, p[200003], id[200003];

vector < int > adj[200003];
priority_queue < Job, vector < Job >, CustomCompare > dp[200003];

void dfs(int u) {
	id[u] = u;
	int len = -1, pos = -1;
	for (auto v : adj[u]) {
		dfs(v);
		if ((int) dp[id[v]].size() > len) {
			len = dp[id[v]].size();
			pos = v;
		}
	}
	if (pos == -1) {
		dp[id[u]].push(a[u]);
		return ;
	}
	id[u] = id[pos];
	for (auto v : adj[u]) {
		if (v != pos) {
			while (dp[id[v]].size()) {
				auto x = dp[id[v]].top();
				dp[id[v]].pop();
				dp[id[pos]].push(x);
			}
		}
	}
	Job tem = a[u];
	while (dp[id[pos]].size()) {
		auto x = dp[id[pos]].top();
		if (tem.cmp(x)) break;
		else {
			dp[id[pos]].pop();
			ans += 1ll * x.w * tem.t;
			tem.t += x.t;
			tem.w += x.w;
		}
	}
	dp[id[pos]].push(tem);
}

main() {
	fast;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		x ++;
		adj[x].push_back(i);
	}	
	for (int i = 1; i <= n; i++) cin >> a[i].w;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].t;
		ans += 1ll * a[i].t * a[i].w;
	}
	dfs(1);
	int total_time = 0;
	while (dp[id[1]].size()) {
		auto x = dp[id[1]].top();
		dp[id[1]].pop();
		ans += 1ll * x.w * total_time;
		total_time += x.t;
	}
	cout << ans;
}
