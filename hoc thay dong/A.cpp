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

const string NAME = "A";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;
const int SZE = 320;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, k, a[100003];

int maximize(int x, int y) {
	if (a[x] > a[y]) return x;
	else return y;
}

namespace task1 {
	vector < int > Block[SZE + 3][SZE + 3], new_v[SZE + 3];
	int lazy[SZE + 3];
	void solve() {
		n --;
		for (int i = 0; i <= n; ++i) 
			Block[i / SZE][i % k].push_back(i);
		for (int i = 0; i <= n / SZE; ++i)
			for (int j = 0; j < k; ++j)
				sort(Block[i][j].begin(), Block[i][j].end(), [&](int &x, int &y) {
					return (a[x] < a[y] || (a[x] == a[y] && x > y));
				});
		for (int t = 0; t <= n; ++t) {
			int id = -1, val;
			for (int block_id = 0; block_id <= n / SZE; ++block_id) {
				if (Block[block_id][lazy[block_id]].empty()) continue;
				if (id == -1 || val < a[Block[block_id][lazy[block_id]].back()]) {
					id = block_id;
					val = a[Block[block_id][lazy[block_id]].back()];
				}
			}
			cout << val << ' ';
			int pos = Block[id][lazy[id]].back();
			Block[id][lazy[id]].pop_back();
			for (int block_id = id + 1; block_id <= n / SZE; ++block_id) {
				lazy[block_id] = (lazy[block_id] + 1);
				if (lazy[block_id] >= k) lazy[block_id] -= k;
			}
			for (int i = 0; i < k; ++i) {
				int j = (i + 1);
				if (j >= k) j -= k;
				new_v[i].clear();
				for (auto x : Block[id][i]) 
					if (x < pos) new_v[i].push_back(x);
				for (auto x : Block[id][j]) 
					if (x > pos) new_v[i].push_back(x);
				
			}
			for (int i = 0; i < k; ++i) {
				sort(new_v[i].begin(), new_v[i].end(), [&](int &x, int &y) {
					return (a[x] < a[y] || (a[x] == a[y] && x > y)); 
				});
				swap(Block[id][i], new_v[i]);
			}
		}
	}
}

namespace task2 {
	int pos[100003];
	bool used[100003];
	void solve() {
		for (int i = 0; i < n; i+=k) {
			pos[i] = i;
		}
		a[n + 1] = -INF;
		for (int i = 0; i < n; i++) {
			int vt = 0;
			for (int j = k; j < n; j+=k) {
				if (pos[j] >= n) break;
				if (a[pos[vt]] < a[pos[j]]) vt = j;
			}
			cout << a[pos[vt]] << ' ';
			used[pos[vt]] = 1;
			for (int j = vt; j < n; j+=k) {
				if (pos[j] >= n) break;
				if (j != 0) pos[j] = max(pos[j], pos[j - k]);
				int val = pos[j] + 1;
				while (val < n && used[val]) val++;
				pos[j] = val;
			}
		}
		for (int i = 0; i < n; i++)
			if (!used[i]) cout << i << '\n';
	}
}

int main() {
	fast;
	//5fre();
	cin >> n >> k;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	
	if (k <= SZE) task1::solve();
	else task2::solve();
}

/*
78 3
43094 14884 2170 23316 54568 14582 16399 61266 46503 21514 12033 38842 23721 47947 71824 66847 88288 62981 44683 58825 18038 64264 45841 50205 79121 19554 20806 13946 56868 51953 59599 70207 31034 42996 31593 67985 6392 75331 27510 68066 80545 77788 41231 1752 39611 1525 9798 63238 66103 1068 91558 32677 52161 90714 85048 31402 75331 66389 8208 50226 94819 20853 72646 89730 4788 95647 45075 94331 31498 5342 29985 81002 22420 22268 99525 15489 54271 86270 */
