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
const ll nmax = 3e6;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[nmax + 3], min_id[2], dem[2], vs[nmax + 3];

bool IsPrime[nmax + 3], th[nmax + 3];
 
vector < int > adj[nmax + 3], pos[nmax + 3], prime, res, id_[2];

bool odd_cycle;

void sieve() {
	memset(IsPrime, 1, sizeof(IsPrime));
	for (int i = 2; i * i <= nmax; i++)
		if (IsPrime[i])
			for (int j = i * i; j <= nmax; j+=i) IsPrime[j] = false;
	for (int i = 2; i <= nmax; i++)
		if (IsPrime[i]) prime.push_back(i);
}

void dfs(int u, int len) {
	vs[u] = len;
	min_id[len] = min(min_id[len], u); dem[len] ++; id_[len].push_back(u);
	for (auto v : adj[u]) {
		if (vs[v] == len) {
			odd_cycle = 1;
			return ;
		}
		if (vs[v] != -1) continue;
		dfs(v, (len ^ 1));
	}
}

void sol() {
	cin >> n;
	for (int i = 1; i <= nmax; i++)
		pos[i].clear();
	res.clear();
	for (int i = 1; i <= n; i++) {
		cin >> a[i];	
		adj[i].clear();
		vs[i] = -1;
		pos[a[i]].push_back(i);
		th[i] = 0;
	}
	for (auto x : prime) {
		int cnt = 0, id1 = -1, id2 = -1;
		for (int i = x; i <= nmax; i+=x) {
			if (!pos[i].size()) continue;
			cnt += pos[i].size();
			if (cnt > 2) {
				cout << -1 << '\n';
				return ;
			}
			for (auto v : pos[i]) {
				if (id1 == -1) id1 = v;
				else id2 = v;
			}
		}
		if (cnt == 0 || cnt == 1) continue;
		adj[id1].push_back(id2);
		adj[id2].push_back(id1);
		th[id1] = th[id2] = 1;
	}
	for (int i = 1; i <= n; i++)
		if (!th[i]) res.push_back(i);
	for (int i = 1; i <= n; i++) {
		if (vs[i] == -1 && th[i]) {
			dem[0] = dem[1] = 0;
			min_id[0] = min_id[1] = INF;
			id_[0].clear(); id_[1].clear();
			odd_cycle = 0;
			dfs(i, 0);
			if (odd_cycle) {
				cout << -1 << '\n';
				return ;
			}
			int val = 0;
			if ((dem[1] > dem[0]) || (dem[1] == dem[0] && min_id[1] < min_id[0]))
				val = 1;
			for (auto x : id_[val]) 
				res.push_back(x);
		}
	}
	sort(res.begin(), res.end());
	cout << res.size() << " ";
	for (auto x : res) cout << x << " ";
	cout << '\n';
}

int main() {
	fast;
	//fre();
	sieve();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
