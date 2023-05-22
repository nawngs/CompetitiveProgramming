//link: https://oj.vnoi.info/problem/mchaos
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long

using namespace std;

int n, it[800005];
pair < string, int > s[100005], ps[100005];

ll query(ll node, ll l, ll r, ll u, ll v){
	if(v < l || r < u || l > r) return 0;
	if(u <= l && r <= v) return it[node];
	ll mid = (l + r) / 2;
	return query(node * 2, l, mid, u, v) + query(node * 2 + 1, mid + 1, r, u, v);
}

void update(ll node, ll l, ll r, ll pos){
	if(pos < l || pos > r) return ;
	it[node] ++;
	if(l == r) return ;
	ll mid = (l + r) / 2;
	update(node * 2, l, mid, pos);
	update(node * 2 + 1, mid + 1, r, pos);
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> s[i].fi;
		string tams = s[i].fi;
		reverse(tams.begin(), tams.end());
		ps[i].fi = tams;
		ps[i].se = i;
	}
	sort(ps + 1, ps + n + 1);
	for(int i = 1; i <= n; i++){
		s[ps[i].se].se = i;
	}
	sort(s + 1, s + n + 1);
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		//cout << s[i].fi << " " << s[i].se << '\n';
		ans += query(1, 1, n, s[i].se + 1, n);
		update(1, 1, n, s[i].se);
	}
	cout << ans;

}