#pragma GCC optimize ("O3")
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
const ll ESP = 1e-9;
const ll INF = 1e18;
const int nmax = 1e5;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n;

string s;

vector < int > it, f;

bool check(string s) {
	string news = s;
	reverse(news.begin(), news.end());
	return (s == news);
}

void build() {
	it.clear();
	it.resize(6 * n + 5, 0);
	f.clear();
	f.resize(n + 5, 0);
}

void update(int node, int l, int r, int pos) {
	if (pos < l || pos > r) return;
	it[node] ++;
	if (l == r) return ;
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos);
	update(node * 2 + 1, mid + 1, r, pos);
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u || l > r) return 0;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return query(node * 2, l, mid, u, v) + query(node * 2 + 1, mid + 1, r, u, v);
}

void sol() {
	cin >> n >> s;
	s = ' ' + s;
	int ans = 1e9 + 7;
	for (int i = 'a'; i <= 'z'; i++) {
		char ch = i;
		string res = "";
		int tam = 0;
		build();
		for (int j = 1; j <= n; j++) {
			if (s[j] == ch) {
				update(1, 0, n, j);
				tam ++;
			}
			else {
				res = res + s[j];
				f[res.size()] = j;
			}
		}
		if (!check(res)) continue;
		f[res.size() + 1] = n + 1;
		//cout << res << '\n';
		int pre = -1;
		for (int j = 1; j <= res.size() / 2 + 1; j++) {
			if (res.size() - j + 1 == pre) break;
			int taml = query(1, 0, n, f[j - 1], f[j]);
			int tamr = query(1, 0, n, f[res.size() - j + 1], f[res.size() - j + 2]);
			pre = j - 1;
			if (j - 1 == res.size() - j + 1) tam -= min(taml, tamr);
			else tam -= 2 * min(taml, tamr);
		}
		//cout << tam << '\n';
		ans = min(ans, tam);
	}
	cout << (ans == 1e9 + 7 ? -1 : ans) << '\n';
}

int main() {
	fast;
	//fre();
	int t;
	cin >> t;
	while (t --) sol();
}
