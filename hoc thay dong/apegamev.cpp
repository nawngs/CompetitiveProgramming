// [+] dinhmanhhungwillwinioi2024
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5 + 5;

int n, q, par[N], w[N];

vector<ll> arr = {0LL};
int m;

inline int get_id(const ll &x) {
	return lower_bound(arr.begin(), arr.end(), x) - arr.begin();
}

struct Node {
	int cnt; ll val;
	Node() {
		cnt = val = 0;
	}
} IT[(N * 21 * 2) << 2];

void update(int x, int w, int id, int l, int r) {
	if (l == r) return IT[id].val += arr[x] * w, IT[id].cnt += w, void();
	int mid = (l + r) / 2;
	if (x <= mid) update(x, w, id << 1, l, mid);
	else update(x, w, id << 1 | 1, mid + 1, r);
	IT[id].val = IT[id << 1].val + IT[id << 1 | 1].val;
	IT[id].cnt = IT[id << 1].cnt + IT[id << 1 | 1].cnt;
}

ll get(int k, int id, int l, int r) { 
	if (l == r) return arr[l] * min(IT[id].cnt, k);
	if (k >= IT[id].cnt) 
		return IT[id].val;
	int mid = (l + r) / 2;
	ll ans = get(k, id << 1 | 1, mid + 1, r);
	if (k > IT[id << 1 | 1].cnt)
		ans += get(k - IT[id << 1 | 1].cnt, id << 1, l, mid);
	return ans;	
}

inline void update(ll x, int w) {
	if (x == 0) return;
	update(get_id(x), w, 1, 1, m);
}

inline ll get(int k) {
	if (k == 0) return 0LL;
	return get(k, 1, 1, m);
}

struct Query { // choose k apple(s) out of idx
	int idx, k, id; ll ans;
	Query() {}
	
	void input(int id_) {
		id = id_;
		cin >> k >> idx;
	}
} qr[N];

ll sum[N], mx[N];

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> q;
	for (int i = 2; i <= n; i++) cin >> par[i];
	for (int i = 2; i <= n; i++) cin >> w[i];
	for (int i = 2; i <= n; i++) {
		int x = i; ll lst = 0;
		sum[x] = sum[par[x]] + w[x];
		mx[x] = sum[x];
		while (x > 1) {
			x = par[x];
			if (x == 1) {
				if (lst) arr.emplace_back(lst);
				arr.emplace_back(sum[i]);
			} else if (mx[x] > lst || sum[i] <= mx[x]) {
				if (lst) arr.emplace_back(lst - sum[x]);
				arr.emplace_back((sum[i] > mx[x] ? mx[x] : sum[i]) - sum[x]);
				lst = mx[x];
			}
			if (sum[i] > mx[x]) mx[x] = sum[i];
			else break;
		}
	}
	sort(arr.begin(), arr.end());
	arr.resize(unique(arr.begin(), arr.end()) - arr.begin());
	m = arr.size() - 1;
	for (int i = 1; i <= q; i++) 
		qr[i].input(i);
	sort(qr + 1, qr + q + 1, [&] (const Query &x, const Query &y) {
		return x.idx < y.idx;
	});
	qr[0].idx = 1;
	for (int ii = 1; ii <= q; ii++) {
		for (int i = qr[ii - 1].idx + 1; i <= qr[ii].idx; i++) {
			int x = i; ll lst = 0;
			mx[x] = sum[x];
			while (x > 1) {
				x = par[x];
				if (x == 1) {
					if (lst) update(lst, -1);
					update(sum[i], +1);
				} else if (mx[x] > lst || sum[i] <= mx[x]) {
					if (lst) update(lst - sum[x], -1);
					update((sum[i] > mx[x] ? mx[x] : sum[i]) - sum[x], +1);
					lst = mx[x];
				}
				if (sum[i] > mx[x]) mx[x] = sum[i];
				else break;
			}
		}
		qr[ii].ans = get(qr[ii].k);
	}
	sort(qr + 1, qr + q + 1, [&] (const Query &x, const Query &y) {
		return x.id < y.id;
	});
	for (int i = 1; i <= q; i++)
		cout << qr[i].ans * 2 << '\n';
	return 0;
}