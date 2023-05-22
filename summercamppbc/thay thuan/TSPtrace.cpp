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
const ll INF = 1e9 + 7;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, adj[21][21], dp[(1 << 20)][20], trace[(1 << 20)][20];

bool getbit(int a, int pos){
	return (a & 1 << pos);
}

void minimize(int &x, int y) {
	if (x == -1 || x > y) x = y;
}

void sol() {
	cin >> n >> m;
	memset(adj, 255, sizeof(adj));
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		u --;
		v --;
		minimize(adj[u][v], c);
	}
	for (int i = 0; i < (1 << n); i++) 
		for (int j = 0; j < n; j++) dp[i][j] = INF;
	
	dp[1][0] = 0;
	trace[1][0] = -1;
	for (int i = 2; i < (1 << n); i++) {
		if (!getbit(i, 0)) continue;
		for (int j = 1; j < n; j++) {
			if (getbit(i, j)) {
				int tam = i - (1 << j);
				for (int k = 0; k < n; k++) {
					if (getbit(tam, k) && adj[k][j] != -1) {
						if (dp[i][j] > dp[tam][k] + adj[k][j]) {
							dp[i][j] = dp[tam][k] + adj[k][j];
							trace[i][j] = k;
						}
					}
				}
			}
		}
	}
	int ans = INF, pos = -1;
	for (int i = 0; i < n; i++) {
		if (adj[i][0] == -1) continue;
		if (ans > dp[(1 << n) - 1][i] + adj[i][0]) {
			pos = i;
			ans = dp[(1 << n) - 1][i] + adj[i][0];
		}
	}
	cout << ans << '\n';
	int tam = (1 << n) - 1;
	vector < int > res;
	while (pos != -1) {
		res.push_back(pos + 1);
		if (pos == 0) break; 
		int newpos = trace[tam][pos];
		tam -= (1 << pos);
		pos = newpos;
	}
	reverse(res.begin(), res.end());
	for (auto x : res) cout << x << ' ';
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
