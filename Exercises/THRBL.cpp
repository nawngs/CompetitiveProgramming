#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

long long n, m, a[50005], it[500005], dp[50005];
pair < long long, long long > p[50005];

void update(long long node, long long l, long long r, long long pos, long long val){
	if(pos < l || pos > r) return ;
	it[node] = min(it[node], val);
	if(l == r) return ;
	long long mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
}

long long query(long long node, long long l, long long r, long long u, long long v){
	if(v < l || r < u || l > r) return 1e18;
	if(u <= l && r <= v) return it[node];
	long long mid = (l + r) / 2;
	return min(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= 8 * (n + 3); i++) it[i] = 1e18;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		p[i].fi = a[i];
		p[i].se = i;
	}
	sort(p + 1, p + n + 1);
	p[0].fi = -1e18;
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(p[i].fi != p[i - 1].fi) cnt ++;
		a[p[i].se] = cnt;
	}
	for(int i = n; i >= 1; i --){
		dp[i] = query(1, 1, n + 3, a[i] + 1, cnt);
		update(1, 1, n + 3, a[i], i);
		//cout << i << " " << dp[i] << '\n';
	}
	int ans = 0;
	for(int i = 1; i <= m; i++){
		long long x, y;
		cin >> x >> y;
		if(x > y) swap(x, y);
		if(dp[x] >= y) ans ++;
	}
	cout << ans;
}