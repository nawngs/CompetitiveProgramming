#include <bits/stdc++.h>

#define pii pair < int, int >
#define fi first
#define se second
#define ll long long
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int r, c, up[1000001], down[1000001], l[1000001], righ[1000001], cnt = 0;

int par[4000001];

char s[1000001];

pair < pii, int > cost[1000001];

int calc(int i, int j) {
    return (i - 1) * c + j;
}

int root(int u) {
    return par[u] == u ? u:  (par[u] = root(par[u]));
}

bool join(int u, int v) {
    int root_u = root(u);
    int root_v = root(v);
    if (root_u == root_v) return false;
    par[root_u] = root_v;
    return true;
}

int main() {
	fast;
	freopen("aquarium.inp", "r", stdin);
	freopen("aquarium.out", "w", stdout);
    cin >> r >> c;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            up[calc(i, j)] = ++ cnt;
            down[calc(i, j)] = ++ cnt;
            l[calc(i, j)] = ++ cnt;
            righ[calc(i, j)] = ++ cnt;
        }
    }
    for (int i = 1; i <= cnt; ++i) par[i] = i;
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j) cin >> s[calc(i, j)];
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin >> cost[calc(i, j)].se;
            cost[calc(i, j)].fi = {i, j};
        }
    }
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            if (i < r) join(down[calc(i, j)], up[calc(i + 1, j)]);
            if (j < c) join(l[calc(i, j + 1)], righ[calc(i, j)]);
            if (s[calc(i, j)] == '/') {
                join(up[calc(i, j)], l[calc(i, j)]);
                join(down[calc(i, j)], righ[calc(i, j)]);
            }
            else {
                join(up[calc(i, j)], righ[calc(i, j)]);
                join(down[calc(i, j)], l[calc(i, j)]);
            }
        }
    }
   	sort(cost + 1, cost + (r * c) + 1, [](pair < pii, int > &x, pair < pii, int > &y) {
   		return x.se < y.se;
   	});
   	ll res = 0;
   	for (int i = 1; i <= r * c; ++i) {
   		int pos = calc(cost[i].fi.fi, cost[i].fi.se);
   		if (join(l[pos], righ[pos])) {
   			s[pos] = '.';
   			res += 1ll * cost[i].se;
   		}
   	}
   	cout << res << '\n';
   	for (int i = 1; i <= r; ++i) {
   		for (int j = 1; j <= c; ++j) cout << s[calc(i, j)];
   		cout << '\n';
   	}
}
