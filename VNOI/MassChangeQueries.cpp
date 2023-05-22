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
const ll nmax = 3e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;
const int BLOCK_SIZE = 800;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[nmax + 3], nblocks;

int lazy[nmax / BLOCK_SIZE + 5][103];

/*
lazy[block][val] la gia tri cua cac a[i] = val trong block

*/

void init() {
	nblocks = n / BLOCK_SIZE + 1;
	for (int i = 1; i <= nblocks; i++)
		for (int j = 1; j <= 100; j++) lazy[i][j] = j;
}

void update_lazy(int block) { // thay doi gia tri trong block
	int l = (block - 1) * BLOCK_SIZE + 1;
	int r = block * BLOCK_SIZE;
	for (int i = l; i <= r; i++) a[i] = lazy[block][a[i]];
	for (int i = 1; i <= 100; i++) lazy[block][i] = i;
}

void update_block(int block, int x, int y) {
	for (int i = 1; i <= 100; i++) if (lazy[block][i] == x) lazy[block][i] = y;
}

void update_seg(int l, int r, int x, int y) {
	int block = (r + BLOCK_SIZE - 1) / BLOCK_SIZE;
	update_lazy(block);
	for (int i = l; i <= r; i++) if (a[i] == x) a[i] = y;
}

void update(int l, int r, int x, int y) {
	int lblock = (l + BLOCK_SIZE - 1) / BLOCK_SIZE;
	int rblock = (r + BLOCK_SIZE - 1) / BLOCK_SIZE;
	if (lblock == rblock) {
		update_seg(l, r, x, y);
		return ;
	}
	for (int i = lblock + 1; i < rblock; i++) update_block(i, x, y);
	update_seg(l, min(n, lblock * BLOCK_SIZE), x, y);
	update_seg((rblock - 1) * BLOCK_SIZE + 1, r, x, y);
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	init();
	int q;
	cin >> q;
	while (q--) {
		int l, r, x, y;
		cin >> l >> r >> x >> y;
		update(l, r, x, y);
	}	
	for (int i = 1; i <= nblocks; i++) update_lazy(i);
	for (int i = 1; i <= n; i++) cout << a[i] << " ";
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
