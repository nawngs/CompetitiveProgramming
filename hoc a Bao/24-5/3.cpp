#include <bits/stdc++.h>
 
#define int ll
#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r
 
using namespace std;
 
const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, k, a[63];

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k;
	set < pii > ms;
	ms.insert({0, 0});
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int u = 0;
	for (int i = 1; i <= n; i++) {
		set < pii > newms;
		newms = ms;
		for (auto x : ms) newms.insert({x.fi + a[i], x.se + a[i]});
		ms = newms;
		set< pii >::iterator itr = ms.begin(), preitr = ms.begin();
		itr ++;
		while (itr != ms.end()) {
			pii cur = *itr, pre = *preitr;
			if (cur.fi <= pre.se + 1) {
				pii newv = {pre.fi, max(pre.se, cur.se)};
				ms.erase(itr); ms.erase(preitr);
				ms.insert(newv);
				itr = ms.find(newv);
			}
			cur = *itr;
			preitr = itr;
			itr ++;
		}
		int pre = -1; u = 0;
		for (auto x : ms) {
			u += min(a[i], x.fi) - pre - 1;
			//if (a[i] == 18378777232) cout << min(a[i], x.fi) << " " << pre << " " << u << '\n';
			pre = x.se;
			if (pre > a[i]) break;
		}
		if (u >= k) {
			int pre = 0;
			for (auto x : ms) {
				while (k && pre < x.fi) {
					k --;
					cout << pre << " ";
					pre ++;
				}
				pre = x.se + 1;
				if (k == 0) return 0;
			}
		}
	}
	//for (auto x : ms) cout << x.fi << " " << x.se << '\n';
	int pre = 0;
	for (auto x : ms) {
		while (k && pre < x.fi) {
			k --;
			cout << pre << " ";
			pre ++;
		}
		pre = x.se + 1;
	}
	pii temp = *ms.rbegin();
	while (k-- && temp.se++) cout << temp.se << " ";
}