#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define int ll
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "bubblesort";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;
const ll SZE = 703;

void fre() {	
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Data {
	int val, id, change;
	Data (int _val, int _id, int _change) : val(_val), id(_id), change(_change) {};
};

int n, k, q, a[100003], delta[1000003], p[100003], cnt[100003], it[400003];

vector < int > pos[100003];

vector < Data > vec[100003];

void update(int node, int l, int r, int pos) {
	if (pos < l || pos > r) return ;
	it[node] ++;
	if (l == r) return ;
	update(node * 2, l, (l + r) / 2, pos);
	update(node * 2 + 1, (l + r) / 2 + 1, r, pos);
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return query(node * 2, l, mid, u, v) + query(node * 2 + 1, mid + 1, r, u, v); 
}

signed main() {
	fast;
	//fre();
	cin >> n >> k >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		delta[0] += query(1, 1, k, a[i] + 1, k);
		update(1, 1, k, a[i]);
		pos[a[i]].push_back(i);
	}
	for (int i = 1; i <= k; i++) p[i] = i;
	for (int t = 1; t <= q; t++) {
		int j;
		cin >> j;
		swap(p[j], p[j + 1]);
		if (pos[p[j]].size() > SZE) vec[p[j]].push_back({p[j + 1], t, 1});
		else if (pos[p[j + 1]].size() > SZE) vec[p[j + 1]].push_back({p[j], t, -1});
			else {
				delta[t] = pos[p[j]].size() * pos[p[j + 1]].size();
				int cur = 0, s = 0;
				for (int i = 0; i < pos[p[j + 1]].size(); i++) {
					while (cur < pos[p[j]].size() && pos[p[j]][cur] < pos[p[j + 1]][i]) cur ++;
					s += cur * 2;
				}
				delta[t] -= s;
			}
	}	
	for (int i = 1; i <= k; i++) {
		if (pos[i].size() <= SZE) continue;
		memset(cnt, 0, sizeof(cnt));
		for (int j = 1; j <= n; j++) cnt[j] = cnt[j - 1] + (a[j] == i);
		ll pre = 0;
		sort(vec[i].begin(), vec[i].end(), [&](Data &x, Data &y) {
			return x.val < y.val;
		});
		for (int j = 0; j < vec[i].size(); j++) {
			if (j != 0 && vec[i][j].val == vec[i][j - 1].val) {
		 		pre = pre * (vec[i][j].change == vec[i][j - 1].change ? 1 : -1);
		 		delta[vec[i][j].id] = pre;
				continue;
			}
			int temp = pos[i].size() * pos[vec[i][j].val].size(), s = 0;
			for (auto x : pos[vec[i][j].val]) s += 2 * cnt[x];
			temp -= s;
			temp *= vec[i][j].change;
			delta[vec[i][j].id] = temp;
			pre = temp;
		}
	}
	for (int i = 1; i <= q; i++) {
		delta[i] += delta[i - 1];
		cout << delta[i] << '\n';
	}
}