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

const string NAME = "groupdiv";
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

int n, gr[300004];

vector < int > adj[300004];

void sol() {
	cin >> n;
	queue < int > q;	
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		while (k --) {
			int x;
			cin >> x;
			adj[i].push_back(x);
		}
		q.push(i);
	}
	while (q.size()) {
		auto u = q.front();
		q.pop();
		int dem = 0;
		for (auto v : adj[u]) dem += gr[u] == gr[v];
		if (dem > 1) {
			gr[u] = !gr[u];
			for (auto v : adj[u]) if (gr[v] == gr[u]) q.push(v);
		}
	}
	cout << "YES" << '\n';
	for (int i = 1; i <= n; i++) if (gr[i]) cout << i << " ";
	cout << '\n';
	for (int i = 1; i <= n; i++) if (!gr[i]) cout << i << " ";
	cout << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
