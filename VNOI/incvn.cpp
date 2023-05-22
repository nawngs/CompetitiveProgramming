//link: https://oj.vnoi.info/problem/incvn
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

const ll MOD = 5000000;
const ll nmax = (1e5 + 3) * 8 + 5;
ll n, k, a[10005], it[80005][53];
pair < ll, ll > p[10005];

void update(ll node, ll l, ll r, ll pos, ll lev, ll val){
	if(pos < l || pos > r || l > r) return ;
	it[node][lev] += val;
	it[node][lev] %= MOD;
	if(l == r) return ;
	ll mid = (l + r) / 2;
	update(node * 2, l, mid, pos, lev, val);
	update(node * 2 + 1, mid + 1, r, pos, lev, val);
}

ll query(ll node, ll l, ll r, ll u, ll v, ll lev){
	if(v < l || r < u || l > r) return 0;
	if(u <= l && r <= v) return it[node][lev] % MOD;
	ll mid = (l + r) / 2;
	ll lnode = query(node * 2, l, mid, u, v, lev) % MOD;
	ll rnode = query(node * 2 + 1, mid + 1, r, u, v, lev) % MOD;
	return (lnode + rnode) % MOD;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		p[i].fi = a[i];
		p[i].se = i;
	}
	if(k == 1){
		cout << n << '\n';
		return 0;
	}
	sort(p + 1, p + n + 1);
	int cnt = 0;
	p[0].fi = -1;
	for(int i = 1; i <= n; i++){
		if(p[i].fi != p[i - 1].fi) cnt ++;
		a[p[i].se] = cnt;
	}
	
	ll ans = 0;
	//update(1, 0, 1e5 + 3, a[1], 1, 1);
	for(int i = 1; i <= n; i++){
		update(1, 0, n, a[i], 1, 1);
		for(int j = 2; j <= k; j++){
			ll temp = query(1, 0, n, 1, a[i] - 1, j - 1);
			temp %= MOD;
			update(1, 0, n, a[i], j, temp);
			if(j == k){
				ans += temp;
				ans %= MOD;
			}
		}
	}
	cout << ans;
}

