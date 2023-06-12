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

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, k, m, s;

string str[10003];

map < string, int > f;

map < string, vector < string > > adj;

map < pair < string, string >, bool > g;

int main() {
	fast;
	cin >> n >> k >> s >> m;
	queue < string > que;
	for (int i = 1; i <= s; i++) {
		cin >> str[i];
		que.push(str[i]);
		f[str[i]] = k;
	}
	for (int i = 1; i <= m; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		if (!g[{s1, s2}]) {
			adj[s1].push_back(s2);
			adj[s2].push_back(s1);
		}
		g[{s1, s2}] = g[{s2, s1}] = 1;
	}
	while (que.size()) {
		auto u = que.front();
		que.pop();
		for (auto v : adj[u]) {
			f[v] ++;
			if (f[v] == k) que.push(v);
		}
	}
	vector < string > res;
	for (auto x : f) 
		if (x.se >= k) res.push_back(x.fi);
		
	cout << res.size() << '\n';
	sort(res.begin(), res.end());
	for (auto x : res) cout << x << " ";
}
