#include <bits/stdc++.h>
#define ll long long

using namespace std;

const long long  MOD = 1E9;
long long n, a[10005], k, ans = 0;

struct Data{
	long long a[12];
} it[80005];

void update(ll node, ll l, ll r, ll pos, ll cnt, ll num){
	if(pos < l || pos > r || l > r) return ;
	it[node].a[cnt] += num;
	if(l == r) return ;
	ll mid = (l + r) / 2;
	update(node * 2, l, mid, pos, cnt, num);
	update(node * 2 + 1, mid + 1, r, pos, cnt, num);
}

ll query(ll node, ll l, ll r, ll u, ll v, ll cnt){
	if(v < l || r < u || l > r) return 0;
	if(u <= l && r <= v) return it[node].a[cnt];
	ll mid = (l + r) / 2;
	return query(node * 2, l, mid, u, v, cnt) + query(node * 2 + 1, mid + 1, r, u, v, cnt);
}

int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	//update(1, 1, n, a[1], 1, 1);
	for(int i = 1; i <= n; i++){
		update(1, 1, n, a[i], 1, 1);
		for(int j = 2; j <= k; j++){
			long long tmp = query(1, 1, n, a[i] + 1, n, j - 1);
			tmp %= MOD;
			if(j == k) ans = (ans + tmp) % MOD;
			else update(1, 1, n, a[i], j, tmp);
		}
	}
	cout << ans;
}