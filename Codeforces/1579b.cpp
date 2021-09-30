#include <bits/stdc++.h>

#define ll long long
#define fi first 
#define se second
#define pll pair < ll, ll >

using namespace std;

const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1;

struct ans {
	int l, r, sub;
	ans(int _l, int _r, int _sub) : l(_l), r(_r), sub(_sub) {};
};

ll n, a[55], b[55];


vector < ans > res;
void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	res.clear();
	ll ans = 0;
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++) {
		if (a[i] == b[i]) continue;
		int r;
		for (int j = i + 1; j <= n; j++) {
			if (a[j] == b[i]) {
				r = j;
				break;
			}
		}  
		ans ++;
		res.push_back({i, r, r - i});
		for (int j = 1; j <= r - i; j++) {
			int tam = a[i];
			for (int k = i; k < r; k ++) {
				a[k] = a[k + 1];
			}
			a[r] = tam;
		}
	}
	cout << ans << '\n';
	for (int i = 0; i < ans; i++) cout << res[i].l << " " << res[i].r << " " << res[i].sub << '\n';
	//cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while (t --) sol();
}
