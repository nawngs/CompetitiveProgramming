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

const string NAME = "I";
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
	//freopen(fout.c_str(), "w", stdout);
}

int n, q, num[200003], tail[200003], timeDFS = 0, scc, num_scc[200003], a[200003], valincycle[200003], numincycle[200003], cyclesze[200003], distocycle[200003];

int d[200003][32];

bool instack[200003], incycle[200003];

stack < int > st;

void dfs(int u) {
	num[u] = ++timeDFS;
	st.push(u);
	instack[u] = 1;
	if (!num[a[u]]) dfs(a[u]);
	else {
		if (instack[a[u]]) {
			scc ++;
			int dem = 0;
			while (st.top() != a[u]) {
				num_scc[st.top()] = scc;
				incycle[st.top()] = 1;
				instack[st.top()] = false;
				valincycle[st.top()] = st.top();
				numincycle[st.top()] = ++dem;
				distocycle[st.top()] = 0;
				st.pop();
			}
			if (instack[st.top()]) {
				num_scc[st.top()] = scc;
				incycle[st.top()] = 1;
				instack[st.top()] = false;
				valincycle[st.top()] = st.top();
				numincycle[st.top()] = ++dem;
				distocycle[st.top()] = 0;
			}
			cyclesze[scc] = dem;
			st.pop();
			return ;
		}
	}
	if (instack[u]) {
		num_scc[u] = num_scc[a[u]];
		valincycle[u] = valincycle[a[u]];
		distocycle[u] = distocycle[a[u]] + 1;
		st.pop();
		instack[u] = false;
	}
}

int check(int u, int v) {
	int x = distocycle[u] - distocycle[v], res = x;
	for (int i = 30; i >= 0; i--) if (x >= (1 << i)) {
			u = d[u][i];
			x -= (1 << i);
		}
	if (u != v) return -1;
	return res;
}

int main() {
	fast;
	//fre();
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		d[i][0] = a[i];
	}
	for (int i = 1; i <= 30; i++)
		for (int j = 1; j <= n; j++) d[j][i] = d[d[j][i - 1]][i - 1];
	for (int i = 1; i <= n; i++) if (!num[i]) dfs(i);
	while (q--) {
		int u, v;
		cin >> u >> v;
		if (num_scc[u] != num_scc[v]) {
			cout << -1 << '\n';
			continue;
		}
		if (!incycle[u] && !incycle[v] && valincycle[u] != valincycle[v]) {
			cout << -1 << '\n';
			continue;
		}
		if (incycle[u] && !incycle[v]) {
			cout << -1 << '\n';
			continue;
		}
		if (valincycle[u] == valincycle[v]) {
			if (distocycle[u] < distocycle[v]) cout << -1 << '\n';
			else cout << check(u, v) << '\n';
			continue ;
		}
		//cout << num_scc[u] << " " << num_scc[v] << " " << near[u] << " " << near[v] << '\n';
		int ans = distocycle[u];
		u = valincycle[u];
		cout << ans + (numincycle[v] - numincycle[u] <= 0 ? abs(numincycle[v] - numincycle[u]) : (cyclesze[num_scc[u]] - numincycle[v] + numincycle[u])) << '\n';
	}
}
