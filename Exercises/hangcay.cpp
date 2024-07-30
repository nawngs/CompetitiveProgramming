#include <bits/stdc++.h>

#define ll long long
#define pii pair < int, int >
#define fi first
#define se second
#define pb push_back
#define mp make_pair
	
using namespace std;
	
const int INF = 1E9 + 7;
const int NMAX = 2E5;
const int BLOCK = 350;
	
struct Info {
	int l, r, cur;
	Info(int _l, int _r, int _cur) : l(_l), r(_r), cur(_cur) {};
};
	
struct Query {
	int l, r, id;
} Q[NMAX + 3];
	
int n, q, L[NMAX + 3], R[NMAX + 3];

ll h[NMAX + 3], ans[NMAX + 3], res = 0;
	
vector < pii > val;
	
void reset(int l, int r) {
	for (int i = 0; i <= n + 1; i++) L[i] = R[i] = 0;
	for (int i = l; i <= r; i++) if (1 <= val[i].se && val[i].se <= n)
		L[val[i].se + 1] = R[val[i].se - 1] = val[i].se;
	for (int i = 1; i <= n + 1; i++) if (L[i] == 0) L[i] = L[i - 1];
	R[n + 1] = n + 1;
	for (int i = n; i >= 0; i--) if (R[i] == 0) R[i] = R[i + 1];
	res = 0;
	int st = R[0];
	while (R[st] != n + 1) {
		res += abs(h[R[st]] - h[st]);
		st = R[st];
	}
}
	
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> q; 
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
		val.pb({h[i], i});
	}
	val.pb({0, 0}); val.pb({INF, n + 1});
	sort(val.begin(), val.end());
	for (int i = 1; i <= q; i++) {
		cin >> Q[i].l >> Q[i].r;
		Q[i].id = i;
		int l = 0, r = val.size() - 1, mid, ans = n;
		while (l <= r) {
			mid = (l + r) / 2;
			if (val[mid].fi >= Q[i].l) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		Q[i].l = ans;
		l = 0, r = val.size() - 1;
		ans = -1;
		while (l <= r) {
			mid = (l + r) / 2;
			if (val[mid].fi <= Q[i].r) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		Q[i].r = ans;
	}
	sort(Q + 1, Q + q + 1, [&](Query &x, Query &y) {
		if (x.l / BLOCK != y.l / BLOCK) return x.l < y.l;
		return x.r > y.r;
	});
	Q[0].l = -INF;
	for (int i = 1; i <= q; i++) {
		int prer = Q[i - 1].r;
		if (Q[i - 1].l / BLOCK != Q[i].l / BLOCK) {
			reset((Q[i].l / BLOCK) * BLOCK, Q[i].r);
			prer = Q[i].r;
		}
		//cout << i << " " << val[Q[i].l].fi << " " << val[Q[i].r].se << '\n';
		for (int j = prer; j > Q[i].r; j--) {
			int left = L[val[j].se], right = R[val[j].se];
			if (left != 0) res -= abs(h[val[j].se] - h[left]);
			if (right != n + 1) res -= abs(h[val[j].se] - h[right]);
			if (left != 0 && right != n + 1) res += abs(h[right] - h[left]);
			R[left] = right; L[right] = left;
		}
		ll old = res;
		stack < Info > st;
		for (int j = max(1, (Q[i].l / BLOCK) * BLOCK); j < Q[i].l; j++) {
			int left = L[val[j].se], right = R[val[j].se]; 
			if (left != 0) res -= abs(h[val[j].se] - h[left]);
			if (right != n + 1) res -= abs(h[val[j].se] - h[right]);
			if (left != 0 && right != n + 1) res += abs(h[right] - h[left]);
			R[left] = right; L[right] = left;
			st.push({left, right, val[j].se});
		}
		ans[Q[i].id] = res;
		res = old;
		while (st.size()) {
			R[st.top().l] = L[st.top().r] = st.top().cur;
			L[st.top().cur] = st.top().l;
			R[st.top().cur] = st.top().r;
			st.pop();
		}	
	}
	for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
}