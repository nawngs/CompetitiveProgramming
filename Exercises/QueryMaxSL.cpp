#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

ll n, q, a[100005], cnt = 0, dp[200005];
pair < ll, pair < ll, ll > > p[100005];

struct Node{
	ll maxa;
	ll cnt;
} it[800005];

struct Data{
	bool isquery;
	ll val;
	ll pos;
} st[200005];

bool cmp(Data x, Data y){
	return x.val < y.val;
}

void build_tree(ll node, ll l, ll r){
	if(l == r){
		it[node].maxa = a[l];
		it[node].cnt = 1;
		return ;
	}
	ll mid = (l + r) / 2;
	build_tree(node * 2, l, mid);
	build_tree(node * 2 + 1, mid + 1, r);
	if(it[node * 2].maxa > it[node * 2 + 1].maxa) it[node] = it[node * 2];
	else{
		if(it[node * 2].maxa < it[node * 2 + 1].maxa)it[node] = it[node * 2 + 1];
		else{
			it[node].maxa = it[node * 2].maxa;
			it[node].cnt = it[node * 2].cnt + it[node * 2 + 1].cnt;
		}
	}
}

void update(ll node, ll l, ll r, ll pos, ll val){
	//cout << node << " " << l << " " 
	if(pos < l || pos > r || l > r) return ;
	//it[node] = max(it[node], val);
	if(l == r){
		it[node].maxa = val;
		it[node].cnt = 1;
		return ;
	}
	ll mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
	if(it[node * 2].maxa > it[node * 2 + 1].maxa) it[node] = it[node * 2];
	else{
		if(it[node * 2].maxa < it[node * 2 + 1].maxa)it[node] = it[node * 2 + 1];
		else{
			it[node].maxa = it[node * 2].maxa;
			it[node].cnt = it[node * 2].cnt + it[node * 2 + 1].cnt;
		}
	}
}

Node query(ll node, ll l, ll r, ll u, ll v){
	if(v < l || r < u || l > r){
		Node ans;
		ans.maxa = -1e18;
		return ans;
	}
	if(u <= l && r <= v) return it[node];
	ll mid = (l + r) / 2;
	Node ans, lnode = query(node * 2, l, mid, u, v), rnode = query(node * 2 + 1, mid + 1, r, u, v);
	if(lnode.maxa > rnode.maxa) return lnode;
	else{
		if(lnode.maxa < rnode.maxa) return rnode;
		else{
			ans.maxa = lnode.maxa;
			ans.cnt = lnode.cnt + rnode.cnt;
			return ans;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("QueryMaxSL.INP", "r", stdin);
	freopen("QueryMaxSL.OUT", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= 8 * n; i++) it[i].maxa = -1e18;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		st[++ cnt].isquery = false;
		st[cnt].val = a[i];
		st[cnt].pos = i;
 	}
 	for(int i = 1; i <= q; i++){
 		cin >> p[i].fi >> p[i].se.fi >> p[i].se.se;
 		if(p[i].fi == 1){
 			st[++ cnt].isquery = true;
 			st[cnt].val = p[i].se.se;
 			st[cnt].pos = i;
 		}
 	}
 	sort(st + 1, st + cnt + 1, cmp);
 	st[0].val = 1e18;
 	int dem = 0;
 	for(int i = 1; i <= cnt; i++){
 		if(st[i].val != st[i - 1].val) dem ++;
 		if(st[i].isquery){
 			dp[dem] = p[st[i].pos].se.se;
 			p[st[i].pos].se.se = dem;
 		}
 		else{
 			dp[dem] = a[st[i].pos];
 			a[st[i].pos] = dem;
 		}

 	}
 	build_tree(1, 1, n);
 	for(int i = 1; i <= q; i++){
 		if(p[i].fi == 1){
 			update(1, 1, n, p[i].se.fi, p[i].se.se);
 		}
 		else{
 			//cout << 1 << '\n';
 			Node tmp = query(1, 1, n, p[i].se.fi, p[i].se.se);
 			cout << dp[tmp.maxa] << " " << tmp.cnt << '\n';
 		}
 	}
}


