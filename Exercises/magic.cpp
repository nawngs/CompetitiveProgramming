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
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 1e6;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[nmax + 3], bit[30][nmax + 3];

void update(int id, int u, int v) {
    int idx = u;
    while (idx <= n) {
        bit[id][idx] += v;
        idx += (idx & (-idx));
    }
}

int getSum(int id, int p) {
    int idx = p, ans = 0;
    while (idx > 0) {
        ans += bit[id][idx];
        idx -= (idx & (-idx));
    }
    return ans;
}

int get(int id, int l, int r) {
	return getSum(id, r) - getSum(id, l - 1);
}

int calc(int l, int r, int bit) {
	int ans = 0;
	if (l == r || l > r) return 0;
	for (int i = bit; i >= 0; i--) {
		int val = get(i, l, r);
		if (val == (r - l + 1) || val == 0) continue;
		if (get(i, l, (l + val) - 1) == val) {
			ans ^= (1 << i);
			int templ = calc(l, (l + val) - 1, i - 1);
			int tempr = calc(l + val, r, i - 1);
			if (templ == -1 || tempr == -1) return -1;
			ans |= templ;
			ans |= tempr;
			return ans;
		}
		else {
			if (get(i, r - val + 1, r) == val) {
				int templ = calc(l, r - val, i - 1);
				int tempr = calc(r - val + 1, r, i - 1); 
				return (templ | tempr);
			}
			else return -1;
		}
	}
	return ans;
}

int main() {
	fast;
	//fre();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = 29; j >= 0; j--) 
			if (((a[i] >> j) & 1)) update(j, i, 1);
	}
	cout << calc(1, n, 29) << '\n';
	int q;
	cin >> q;
	while (q--) {
		int id, val;
		cin >> id >> val;
		for (int j = 29; j >= 0; j--) {
			bool cur = ((a[id] >> j) & 1);
			bool new_ = ((val >> j) & 1);
			if (cur == new_) continue;
			else {
				if (cur == 0) update(j, id, 1);
				else update(j, id, -1);
			}
		}
		cout << calc(1, n, 29) << '\n';
	}
}
