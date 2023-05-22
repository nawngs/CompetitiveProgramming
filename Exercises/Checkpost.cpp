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

const string NAME = "checkpost";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
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

ll n, a[100003], m, res = 0, cnt = 1, num[100003], low[100003], timer;;

bool deleted[100003];

vector < ll > adj[100003];

stack < ll > st;

void dfs(int u) {
	num[u] = low[u] = ++timer;
	st.push(u);
	for (auto v : adj[u]) {
		if(deleted[v]) continue;
		if(!num[v]){
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
		else low[u] = min(low[u], num[v]);
	}
	if (num[u] == low[u]){
		pll cur = {INF, 0};
		while (st.top() != u) {
			deleted[st.top()] = true;
			if (cur.fi > a[st.top()]) cur = {a[st.top()], 1};
			else if (cur.fi == a[st.top()]) cur.se ++;
			st.pop();
		}
		deleted[st.top()] = true;
		if (cur.fi > a[st.top()]) cur = {a[st.top()], 1};
		else if (cur.fi == a[st.top()]) cur.se ++;
		st.pop();
		res += cur.fi;
		cnt = (cnt * cur.se) % MOD;
	}
	for (int i = 1; i <= n; i++) 
}

int main() {
	fast;
	fre();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	for (int i = 1; i <= n; i++) if (!num[i]) dfs(i);
	cout << res << " " << cnt << '\n';
}
