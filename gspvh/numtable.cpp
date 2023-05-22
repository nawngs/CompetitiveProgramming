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

const string NAME = "numtable";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;
const ll base = 2309;
const int mx = 1e6;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, a[mx + 3];

bool check[nmax + 3], vs[mx + 3];

vector < int > prime, pos[nmax + 5], start, path;

queue < int > que;

void sang() {
	memset(check, 1, sizeof(check));
	for (int i = 2; i * i <= nmax; i++) 
		if (check[i]) for (int j = i * i; j <= nmax; j+=i) check[j] = false;
	for (int i = 2; i <= nmax; i++) if (check[i]) {
		prime.push_back(i);
	}
}

pii change(int x) {
    int p1 = (x / m + 1) - (x % m == 0);
    int p2 = (x % m == 0) ? m : x % m;
    return {p1, p2};
}

int change(pii tam) {
	return (tam.fi - 1) * m + tam.se;
}

int bfs(int pos, int val) {
	if (vs[pos]) return 0;
	que.push(pos);
	int cnt = 0;
	vs[pos] = 1;
	while (que.size()) {
		int u = que.front();
		que.pop();
		cnt ++;
		path.push_back(u);
		pii tam = change(u);
		for (int i = 0; i < 4; i++) {
			int newi = tam.fi + dx[i];
			int newj = tam.se + dy[i];
			int cur = change({newi, newj});
			if (newi < 1 || newj < 1 || newi > n || newj > m || vs[cur] || (a[cur] % val) != 0) continue;
			vs[cur] = 1;
			que.push(cur);
		}
	}
	return cnt;
}

int solve(int val) {
	start.clear();
	path.clear();
	for (int i = val; i <= nmax; i+=val) 
		for (auto x : pos[i]) start.push_back(x);
	int res = 0;
	for (auto x : start) res = max(res, bfs(x, val));
	for (auto x : path) vs[x] = false;
	return res;
}

int main() {
	fast;
	fre();
	int o; cin >> o;
	sang();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int cur = (i - 1) * m + j;
			cin >> a[cur];
			pos[a[cur]].push_back(cur);
		}
	}
	int res = 0;
	for (auto x : prime) res = max(res, solve(x));
	cout << res;
}
