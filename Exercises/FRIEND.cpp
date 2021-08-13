#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

int n, l, ans = 1, it[8000003], dp[1000005]; 

pair < long double, int > p[100005];

pair < int, int > a[100005];

void update(int node, int l, int r, int pos, int val){
	if(pos < l || pos > r) return ;
	it[node] = max(it[node], val);
	if(l == r) return ;
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
}

int query(int node, int l, int r, int u, int v){
	if(v < l || r < u || l > r) return 0;
	if(u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return max(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

bool cmp(pair < int, int > x, pair < int, int > y){
	return (x.fi < y.fi) || (x.fi == y.fi && x.se > y.se);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("FRIEND.Inp", "r", stdin);
	freopen("FRIEND.Out", "w", stdout);
	memset(a, 255, sizeof(a));
	cin >> l >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].fi >> a[i].se;
		p[i].fi = (long double) l / a[i].se + a[i].fi;
		//cout << p[i].fi << '\n';
		p[i].se = i;
	}
	sort(p + 1, p + n + 1);
	p[0].fi = 0;
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		//cout << p[i].fi << '\n';
		cnt += (p[i].fi != p[i - 1].fi);
		a[p[i].se].se = cnt;
	}
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i++){
		//if(a[i] == -1) continue;
		dp[i] = query(1, 1, cnt, a[i].se, cnt) + 1;
		//cout << a[i].fi << " " << a[i].se << '\n';
		update(1, 1, cnt, a[i].se, dp[i]);
		ans = max(ans, dp[i]);
	}
	cout << ans;
}