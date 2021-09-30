#include <bits/stdc++.h>

using namespace std;

struct Command {
	bool isQ;
	int val;
	int pos;
} a[200005];

struct Node {
	int sub;
	int l;
	int r;
	int len;
} it[800005];

int n, q, res[100005];

Node merge(Node x, Node y) {
	Node ans;
	ans.sub = max(x.sub, max(y.sub, x.r + y.l));
	ans.l = x.l;
	if (x.l == x.len) ans.l += y.l;
	ans.r = y.r;
	if (y.r == y.len) ans.r += x.r;
	ans.len = x.len + y.len;
	return ans;
}

void update(int node, int l, int r, int pos) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node].sub = it[node].l = it[node].r = 1;
		//cout << l << " " << r << " " << it[node].sub << " " << it[node].r << " " << it << " " << pos << '\n';
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos);
	update(node * 2 + 1, mid + 1, r, pos);
	it[node] = merge(it[node * 2], it[node * 2 + 1]);
	//cout << l << " " << r << " " << it[node].sub << " " << pos << '\n';
}

void build(int node, int l, int r) {
	if (l == r) {
		it[node].sub = it[node].l = it[node].r = 0;
		it[node].len = 1;
		return ;
	}
	int mid = (l + r) / 2;
	build(node * 2, l, mid);
	build(node * 2 + 1, mid + 1, r);
	it[node] = merge(it[node * 2], it[node * 2 + 1]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].val;
		a[i].isQ = false;
		a[i].pos = i;
	}
	for (int i = 1; i <= q; i++) {
		cin >> a[i + n].val;
		a[i + n].isQ = true;
		a[i + n].pos = i;
	}
	int tam = n + q;
	sort(a + 1, a + tam + 1, [](Command &x, Command &y) {
		return (x.val < y.val) || (x.val <= y.val && !x.isQ);
	});
	build(1, 1, n);
	//cout << a[10].val << '\n';
	for (int i = 1; i <= n + q; i++) {
		if (!a[i].isQ) update(1, 1, n, a[i].pos);
		else {
			res[a[i].pos] = it[1].sub;
		}
	}
	for (int i = 1; i <= q; i++) cout << res[i] << '\n';
}