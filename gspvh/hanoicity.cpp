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
const ll MOD = 998244353;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int f, o, s, z;

ll d[8][500003];

int t[100003], h[100003];

bool visited[100003];

vector < int > village[100003];

vector < pii > adj[500003]; 

vector < int > num[500003];

void dijkstra(int start) {
	priority_queue < pll, vector < pll >, greater < pll > > heap;
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= f; i++) d[start][i] = INF;
	d[start][start] = 0;
	heap.push({d[start][start], start});
	while (heap.size()) {
		auto u = heap.top();
		heap.pop();
		if (u.fi != d[start][u.se]) continue;
		for (auto v : adj[u.se]) {
			if (d[start][v.fi] > u.fi + v.se) {
				d[start][v.fi] = u.fi + v.se;
				heap.push({d[start][v.fi], v.fi});
			}
		}
		for (auto city : num[u.se]) {
			if (visited[city]) continue;
			for (auto x : village[city]) {
				if (d[start][x] > u.fi + h[city]) {
					d[start][x] = u.fi + h[city];
					heap.push({d[start][x], x});
				}
			}
			visited[city] = 1;
		}
	}
	//for (int i = 1; i <= f; i++) cout << start << " " << d[start][i] << '\n';
}

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

void sol() {
	cin >> f >> o >> s;	
	for (int i = 1; i <= o; i++) {
		cin >> t[i] >> h[i];
		for (int j = 1; j <= t[i]; j++) {
			int x;
			cin >> x;
			village[i].push_back(x);
			num[x].push_back(i);
		}
	}
	//cout << "OK" << '\n';
	for (int i = 1; i <= s; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
	cin >> z;
	for (int i = 1; i <= z; i++) dijkstra(i);
	for (int i = 1; i <= f; i++) {
		ll s = 0;
		for (int j = 1; j <= z; j++) {
			ll res = d[j][i];
			if (res == INF) res = -1;
			res = (res + MOD) % MOD;
			s = (s + (res * mu(j, j)) % MOD) % MOD;
		}
		cout << s << " ";
	}
}

int main() {
	//fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
