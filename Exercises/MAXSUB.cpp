#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

const ll nmax = 4 * 2000 * 2000;
ll n, m, k, a[2005], s[2005], demf = 0, ans = 0, f[2005], g[2005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("MAXSUB.Inp", "r", stdin);
	freopen("MAXSUB.Out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	for(int len = 1; len <= n; len ++){
		f[len] = 1e9;
		for(int i = len; i <= n; i++){
			f[len] = min(f[len], s[i] - s[i - len]);
		}
	}
	s[0] = 0;
	for(int i = 1; i <= m; i++){
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	for(int len = 1; len <= m; len ++){
		g[len] = 1e9;
		for(int i = len; i <= m; i++){
			g[len] = min(g[len], s[i] - s[i - len]);
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(f[i] * g[j] <= k) ans = max(ans, (ll) i * j);
		}
	}
	cout << ans;
}