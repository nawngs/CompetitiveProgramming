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

struct Point {
	int x, y, id;
};

int n, m, nxt[300003], par[300003], cnt[300003], res[300003];

Point p[600003];

int find(int u) {
	return (u == par[u] ? u : par[u] = find(par[u]));
}

bool join(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return false;
	par[v] = u;
	cnt[u] += cnt[v];
	return 1;
}

int main() {
	fast;
	//fre();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i].x >> p[i].y;
		p[i].x = (p[i].x * 2) - 1;
		p[i].y = (p[i].y * 2) - 1;
		p[i].id = 0;
	}
	cin >> m;
	for (int i = n + 1; i <= n + m; i++) {
		cin >> p[i].x >> p[i].y;
		p[i].x *= 2;
		p[i].y *= 2;
		p[i].id = i - n;
	}
	sort(p + 1, p + n + m + 1, [&](Point &x, Point &y) {
		return (x.y > y.y);
	});
	set < pii > ms;
	for (int i = 1; i <= n + m; i++) {
		pii cur = {p[i].x, p[i].id};
		if (cur.se != 0) {
			ms.insert(cur);
			auto pos = ms.find(cur);
			if ((++pos) != ms.end()) 
				nxt[cur.se] = pos->se;
			while (1) {
				pos = ms.find(cur);
				if (pos == ms.begin()) 
					break;
				pos --;
				if (pos->se < cur.se) break;
				ms.erase(pos);
			}
		}
		else {
			auto it = ms.lower_bound(cur);
			if (it != ms.end()) 
				cnt[it->se] ++;
		}
	}
	for (int i = 1; i <= m; i++) 
		par[i] = i;
	for (int i = m; i >= 1; i--) {
		res[i] = cnt[find(i)];
		if (nxt[i] != 0) 
			join(i, nxt[i]);
	}
	for (int i = 1; i <= m; i++) cout << res[i] << '\n';
}
