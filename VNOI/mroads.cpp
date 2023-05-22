#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

struct Data
{
	ll v;
	ll w;
	ll b;
};
ll n, k, max_dis, ans, cur;
vector < Data > adj[100005];
deque < pair < ll, ll > > road;

void dfs(ll u, ll e, ll cmp, ll &k){
	//cout << u << " " << e << " " << cmp << " " << k << " " << road.size() << '\n';
	for(auto v : adj[u]){
		if(v.v == e) continue;
		//cout << v.w << " " << v.b << '\n';
		road.push_back({v.w, v.b});
		//cout << cmp << " " << u << " " << v.v << " " << road.size() << '\n';
		cur += v.w;
		while(cur > cmp && !road.empty() && k > 0){
			ll tam = min(cur - cmp, min(road.front().fi - road.front().se, k));
			road.front().fi -= tam;
			k -= tam;
			cur -= tam;
			if(road.front().fi == road.front().se) road.pop_front();
		}
	//	cout << k << " " << max_dis << '\n';
		max_dis = max(max_dis, cur);
		dfs(v.v, u, cmp, k);
		//cout << road.back().fi << " " << road.back.se << '\n'
		if(road.size()){
			cur -= road.back().fi;
			road.pop_back();
		}
		else cur -= v.b;
	}
}

bool solve(ll x){
	max_dis = 0;
	ll tmp = k;
	road.clear();
	cur = 0;
	dfs(1, 0, x, tmp);
	//cout << x << " " << max_dis << '\n';
	if(max_dis <= x) return true;
	else return false;
}

int main(){
	cin >> n >> k;
	for(int i = 1; i < n; i++){
		ll u, v, w, b;
		cin >> u >> v >> w >> b;
		Data tmp;
		tmp.v = v;
		tmp.w = w;
		tmp.b = b;
		adj[u].push_back(tmp);
		tmp.v = u;
		adj[v].push_back(tmp);
	}
	ll l = 1, r = 1e9, mid;
	while(l <= r){
		mid = (l + r) / 2;
		//cout << mid << '\n';
		if(solve(mid)){
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;
}