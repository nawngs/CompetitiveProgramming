#include <bits/stdc++.h>
using namespace std;

using ll = long long;
typedef pair<int, int> pii;
#define fi first
#define se second
#define eb emplace_back 

const int N = 1e5+5;

int n, s, d, a[N], ca[N];
vector<pii> comp;

struct segmenttree {
	int n, x, v; 
	vector<int> sc;
	vector<ll> sv;
	void build(int t, int l, int r) {
		if (l == r) 
			return sc[t] = 1, sv[t] = comp[l].fi, void();
		int mi = (l+r)/2;
		build(2*t, l, mi); build(2*t+1, mi+1, r);
		sc[t] = sc[t*2] + sc[t*2+1];
		sv[t] = sv[t*2] + sv[t*2+1];
	}
	segmenttree() {}
	segmenttree(int n) : n(n) {
		sc.resize(4*n+4, 0); sv.resize(4*n+4, 0);
		build(1, 0, n-1);
	}
	void updc(int t, int l, int r) {
		if (l > x || r < x) return;
		if (l == r) {
			sc[t] += v;
			if (!sc[t]) sv[t] = 0; else sv[t] = comp[l].fi;
			return;
		}
		int mi = (l+r)/2;
		updc(t*2, l, mi); updc(t*2+1, mi+1, r);
		sc[t] = sc[t*2] + sc[t*2+1];
		sv[t] = sv[t*2] + sv[t*2+1];	
	}
	ll getc(int t, int l, int r) {
		if (l == r) 
			return (v >= sc[t] ? sv[t] : 0);
		int mi = (l+r)/2;
		if (sc[t*2] >= v)
			return getc(t*2, l, mi);
		else 
			return v -= sc[t*2], sv[t*2]+getc(t*2+1, mi+1, r);		
	}
	void upd(int x, int v) {
		this->x = x, this->v = v;
		updc(1, 0, n-1);
	}
	ll get(int k) {
    if (!k) return 0;
    if (k >= sc[1]) return sv[1];
		this->v = k;
		return getc(1, 0, n-1);
	}
} sol;

ll res = 0;
void call(int l, int r, int opl, int opr) {
	if (l > r) return;
	int opt = opr, mi = (l+r)/2; ll best = 0;
	for (int i = r; i > mi; --i)
		sol.upd(ca[i], -1);
	for (int i = opl; i <= opr; ++i) {
		if (i-1 >= opl) sol.upd(ca[i-1], -1);
		int k = d - (2*(s-i) + mi-s);
		if (k >= 0) {
			ll tmp = sol.get(k);
			if (best < tmp) opt = i, best = tmp;
		}
	}
	res = max(res, best);
	
	for (int i = opr-1; i >= opl; --i)
		sol.upd(ca[i], 1);
	sol.upd(ca[mi], -1);
	call(l, mi-1, opl, opt);
	
	for (int i = opl; i < opt; ++i)
		sol.upd(ca[i], -1);
	for (int i = mi; i <= r; ++i)
		sol.upd(ca[i], 1);
	call(mi+1, r, opt, opr);
	
	for (int i = opl; i < opt; ++i)
		sol.upd(ca[i], 1);
}

signed main() {
	cin.tie(0)->sync_with_stdio(0); cout.tie(0);	
	cin >> n >> s >> d;
	for (int i = 0; i < n; ++i) 
		cin >> a[i], comp.eb(a[i], i);
	sort(comp.begin(), comp.end(), greater<pii>());
	for (int i = 0; i < n; ++i)
		ca[comp[i].se] = i;
	
	sol = segmenttree(n);
	call(s, n-1, 0, s);
	reverse(ca, ca+n);
	s = n-s-1;
	call(s, n-1, 0, s);
	cout << res;
	return 0;
}

