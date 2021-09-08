	//link:https://oj.vnoi.info/problem/message
	#include <bits/stdc++.h>
	#define ll long long
	#define fi first
	#define se second

	using namespace std;

	ll n, m, num[805], low[805], timeDFS = 0, scc, num_scc[805], check[805];

	bool deleted[805];

	vector < ll > adj[805];

	stack < ll > st;

	vector < pair < ll, ll > > vec;

	void dfs(ll u){
		//cout << u << '\n';
		num[u] = low[u] = ++ timeDFS;
		st.push(u);
		for(auto v : adj[u]){
			if(deleted[v]) continue;
			if(!num[v]){
				dfs(v);
				low[u] = min(low[u], low[v]);
			}
			else low[u] = min(low[u], num[v]);
		}
		if (num[u] == low[u]){
			scc ++;
			while (st.top() != u) {
				deleted[st.top()] = true;
				num_scc[st.top()] = scc;
				st.pop();
			}
			deleted[st.top()] = true;
			num_scc[st.top()] = scc;
			st.pop();
		}

	}

	int main(){
		cin >> n >> m;
		memset(num, 0, sizeof(num));
		for(int i = 1; i <= m; i++){
			ll u, v;
			cin >> u >> v;
			adj[u].push_back(v); 
			vec.push_back({u, v});
		}
		//cout << 1 << '\n';
		for(int i = 1; i <= n; i++) if(num[i] == 0) dfs(i);
		//cout << "YEs" << '\n';
		for(auto v : vec){
			if(num_scc[v.fi] != num_scc[v.se]) check[num_scc[v.se]] = 1;
		}
		ll ans = 0;
		for(int i = 1; i <= scc; i++) if(check[i] == 0) ans ++;
		cout << ans;
	}
