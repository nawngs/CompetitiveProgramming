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
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, k, a[1000003], dem = 0, cnt[1000003];

bool vs[1000003];

vector < int > adj[1000003], scc;

bitset < 1000003 > dp;

void dfs(int u) {
	vs[u] = 1;
	dem ++;
	for (auto v : adj[u]) {
		if (!vs[v]) dfs(v);
	}
}

int main() {
	fast;
	//fre();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		adj[x].push_back(i);
	}
	for (int i = 1; i <= n; i++) if (!vs[i]) {
		dem = 0;
		dfs(i);
		scc.push_back(dem);
		cnt[dem] ++;
	}
	for (int i = 2; i <= n / 2; i++) {
		if (cnt[i] < 2) continue;
		if (cnt[i] % 2 == 0) {
			int tam = cnt[i] - 2;
			cnt[i] = 2;
			cnt[i * 2] += tam / 2;
		}
		else {
			int tam = cnt[i] - 1;
			cnt[i] = 1;
			cnt[i * 2] += tam / 2;
		}
	}
	dp |= 1;
	for (int i = 2; i <= n; i++) {
		if (cnt[i]) dp |= dp << i;
		if (cnt[i] >= 2) dp |= dp << i;
	}
	if (dp[k] == 1) cout << k << " ";
	else cout << k + 1 << ' ';
	dem = 0;
	for (auto x : scc) {
		int tam = x / 2;
		dem += min(k, tam) * 2;
		k -= min(k, tam);
		if (k == 0) break;
	}
	if (k == 0) cout << dem;
	else {
		for (auto x : scc) {
			if (x % 2 == 1) {
				dem ++;
				k --;
				if (k == 0) {
					cout << dem;
					return 0;
				}
			}
		}
		//cout << dem;
	}
}
