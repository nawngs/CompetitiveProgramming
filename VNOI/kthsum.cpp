//link: https://oj.vnoi.info/problem/bedao_t1_kthsum
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

ll n, s[100005], k, f[100005], it[800005];

pair < ll, ll > p[100005];

ll query(ll node, ll l, ll r, ll u, ll v){
	if(v < l || r < u || l > r) return 0;
	if(u <= l && r <= v) return it[node];
	ll mid = (l + r) / 2;
	return query(node * 2, l, mid, u, v) + query(node * 2 + 1, mid + 1, r, u, v);
}

void update(ll node, ll l ,ll r, ll pos){
	if(pos < l || pos > r) return;
	it[node] ++;
	if(l == r) return;
	ll mid = (l + r) / 2;
	update(node * 2, l, mid, pos);
	update(node * 2 + 1, mid + 1, r, pos);
}

ll calc(ll x){
	memset(it, 0, sizeof(it));
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		ll l = 1, r = n, temp = -1, mid;
		while(l <= r){
			mid = (l + r) / 2;
			if(f[mid] <= f[s[i]] - x){
				temp = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		if(temp != -1) ans += query(1, 1, n, 1, temp);
		update(1, 1, n, s[i]);
	}
	return ans;
}

void roi_rac_s(){
	for(int i = 1; i <= n; i++){
		p[i].fi = s[i];
		p[i].se = i;
	}
	sort(p + 1, p + n + 1);
	p[0].fi = -1e18;
	ll cnt = 0;
	for(int i = 1; i <= n; i++){
		cnt += (p[i].fi != p[i - 1].fi);
		f[cnt] = s[p[i].se];
		s[p[i].se] = cnt;
	}
}

int main(){
	cin >> n >> k;
	s[1] = 0;
	n ++;
	for(int i = 2; i <= n; i++){
		ll x;
		cin >> x;
		s[i] = s[i - 1] + x;
	}
	roi_rac_s();
	ll l = -1e14, r = 1e14, mid, ans;
	while(l <= r){
		mid = (l + r) / 2;
		ll temp = calc(mid);
		//cout << mid << " " << temp << '\n';
		if(temp >= k){
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans;
}
