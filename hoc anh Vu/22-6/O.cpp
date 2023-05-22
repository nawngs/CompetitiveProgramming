#pragma GCC optimize ("O2")
#pragma GCC optimize ("O1")

#include <bits/stdc++.h>

#define ll long long
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "O";

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Data {
	int val;
	int index;
	bool IsQuery;
} a[2000001];

int n, q;

ll res[1000001], val[1000001];

ll calc(int x) {
	if (x < 0) return 0;
	return ((1ll * x + 1) * 1ll * x / 2);
}

int main() {
	fast;
	fre();
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].val;
		a[i].index = i;
		a[i].IsQuery = false;
	}
	for (int i = 1; i <= q; ++i) {
		cin >> a[n + i].val;
		a[n + i].index = i;
		a[n + i].IsQuery = true;
	}
	sort(a + 1, a + n + q + 1, [&](Data &x, Data &y) {
		return (x.val < y.val) || (x.val == y.val && !x.IsQuery);
	});
	ll ans = 0;
	for (int i = 1; i <= n + q; i++) {
		if (!a[i].IsQuery) {
			ans = ans - calc(val[a[i].index - 1]) - calc(val[a[i].index + 1]) + calc(val[a[i].index - 1] + val[a[i].index + 1] + 1);
			int posl = a[i].index - val[a[i].index - 1];
			int posr = a[i].index + val[a[i].index + 1];
			val[posl] = val[posr] = posr - posl + 1;
			//cout << i << " " << a[i].val << " " << a[i].index << " " << posl << " " << posr << '\n';
		}
		else res[a[i].index] = ans;
		//cout << a[i].val << " " << a[i].index << " " << ans << '\n';
	}
	for (int i = 1; i <= q; i++) cout << res[i] << '\n';
}
