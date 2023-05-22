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
const ll MOD = 1e9 + 7;
const ll base = 2309;
const int BLOCK_SIZE = 350;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, power[100003], nxt[100003], cnt[100003];

pii query(int start) {
	int x = start, pre = x, res = 0;
	while (x < n) {
		pre = x;
		res += cnt[x];
		x = nxt[x];
	}
	int cur_block = pre / BLOCK_SIZE;
	while (pre + power[pre] < n && (pre + power[pre]) / BLOCK_SIZE == cur_block) pre += power[pre];
	
	return {pre, res};
}

void update(int index, int mana) {
	for (int i = index; i >= 0 && i / BLOCK_SIZE == index / BLOCK_SIZE; i--) {
		int curBlock = i / BLOCK_SIZE, newBlock = (i + power[i]) / BLOCK_SIZE;
		if (newBlock > curBlock || i + power[i] >= n) {
			nxt[i] = i + power[i];
			cnt[i] = 1;
		} else {
			nxt[i] = nxt[i + power[i]];
			cnt[i] = cnt[i + power[i]] + 1;
		}
	}
}

int main() {
	fast;
	//fre();
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> power[i];
	for (int i = n - 1; i >= 0; i--) update(i, power[i]);
	while (m--) {
		int type;
		cin >> type;
		if (type == 1) {
			int start;
			cin >> start;
			pii res = query(start - 1);
			cout << res.fi + 1 << " " << res.se << '\n';
		}
		else {
			int id, newpow;
			cin >> id >> newpow;
			power[id - 1] = newpow;
			update(id - 1, newpow);
		}
	}
}
