 #include <bits/stdc++.h>
 
 using namespace std;
 
 const int N = 35000;
 const int K = 100;
 
 int n, k, a[N + 3], dp[N + 3][K + 3], nxt[N + 3], root[N + 3], nnode = 0, pos[N + 3];
 
 struct Node {
 	int val, l, r;
 	Node() {
 		val = l = r = 0;
 	}
 	Node(Node x, int v) {
 		val = x.val + v;
 		l = x.l; r = x.r;
 	}
 } it[60 * N + 3];
 
 int build(int l, int r) {
 	if (l == r) {
 		it[++ nnode] = Node();
 		return nnode;
 	}
 	int cur = ++ nnode;
 	it[cur].l = build(l, (l + r) / 2); it[cur].r = build((l + r) / 2 + 1, r);
 	it[cur].val = it[it[cur].l].val + it[it[cur].r].val;
 	return cur;
 }
 
 int update(int node, int l, int r, int pos, int val) {
 	if (l == r) {
 		it[++ nnode] = Node(it[node], val);
 		return nnode;
 	}
 	int cur = ++ nnode; 
 	Node &x = it[cur]; x = it[node];
 	int mid = (l + r) / 2;
 	if (pos <= mid) x.l = update(it[node].l, l, mid, pos, val);
 	else x.r = update(it[node].r, mid + 1, r, pos, val);
 	x.val = it[x.l].val + it[x.r].val;
 	return cur;
 }
 
int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node].val;
	return query(it[node].l, l, (l + r) / 2, u, v) + query(it[node].r, (l + r) / 2 + 1, r, u, v);
}
 
 void solve(int j, int l, int r, int optl, int optr) {
 	if (l > r) return ;
 	int i = (l + r) / 2;
 	int cur = query(root[optl + 1], 1, n, optl + 1, i), best = optl, val = cur + dp[optl][j - 1];
 	for (int p = optl + 1; p <= min(i - 1, optr); p++) {
 		if (nxt[p] != -1 && nxt[p] <= i) cur -= nxt[p] - p;
 		if (val > dp[p][j - 1] + cur) {
 			val = dp[p][j - 1] + cur;
 			best = p;
 		}
 	}
 	dp[i][j] = val;
 	solve(j, l, i - 1, optl, best);
 	solve(j, i + 1, r, best, optr);
 }
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	memset(pos, 255, sizeof(pos));
	root[n + 1] = build(1, n);
	for (int i = n; i >= 1; i--) {
		nxt[i] = pos[a[i]];
		if (nxt[i] == -1) root[i] = root[i + 1];
		else root[i] = update(root[i + 1], 1, n, nxt[i], nxt[i] - i);
		// cout << i << " " << it[root[i]].val << '\n';
		pos[a[i]] = i;
	}
	memset(dp, 0x3f, sizeof dp);
	for (int i = 0; i <= k; i++) dp[0][i] = 0;
	for (int i = 1; i <= k; i++)
		solve(i, 1, n, 0, n - 1);
	cout << dp[n][k];
}