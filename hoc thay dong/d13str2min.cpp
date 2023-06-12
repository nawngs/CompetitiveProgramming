#include <bits/stdc++.h>

#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

string s;

int it[800003], n;

void build(int node, int l, int r) {
	if (l == r) {
		it[node] = l;
		return ;
	}
	build(lnode); build(rnode);
	it[node] = it[node * 2 + 1];
	if (s[it[node * 2 + 1]] > s[it[node * 2]]) it[node] = it[node * 2];
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return -1;
	if (u <= l && r <= v) return it[node];
	int v1 = query(lnode, u, v), v2 = query(rnode, u, v);
	if (v1 == -1) return v2;
	if (v2 == -1) return v1;
	return (s[v2] <=s[v1] ? v2 : v1);
}

void solve(const string &s, int l, int  r) {
	if (l > r) return ;
	int pos = query(1, 1, n, l, r);
	cout << s[pos];
	solve(s, l, pos - 1); solve(s, pos + 1, r);
}

int main() {
	cin >> s; n = s.size();s = ' ' + s;
	build(1, 1, n);
	solve(s, 1, n);
}