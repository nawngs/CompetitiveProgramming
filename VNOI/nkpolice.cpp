#include <bits/stdc++.h>

using namespace std;

int n, e, num[100005], low[100005], tail[100005], p[100005][23], depth[100005], deep = 0, timeDFS = 0;

bool joint[100005];

vector < int > adj[100005];

//##########################################################################################

void dfs(int u, int e){
	num[u] = low[u] = ++ timeDFS;
	depth[u] = ++ deep;
	int child = 0;
	for(auto v : adj[u]){
		if(v == e) continue;
		//if(v == 7) cout << p[7][0] << '\n';
		//cout << v << " " << u << '\n';
		if(!num[v]){
			dfs(v, u);
			p[v][0] = u;
			low[u] = min(low[u], low[v]);
			child ++;
			if(e == 0){
				if(child > 1) joint[u] = true;
			}
			else if(low[v] >= num[u]) joint[u] = true;
		}
		else low[u] = min(low[u], num[v]);
	}
	tail[u] = timeDFS;
	deep --;
}

//##########################################################################################

void build_sparse(){
	for(int k = 1; k <= 20; k++){
		for(int i = 1; i <= n; i++){
			p[i][k] = p[p[i][k - 1]][k - 1];
		}
	}
}

//#########################################################################################

bool check(int u, int ance){
	return (num[ance] <= num[u]) && (num[u] <= tail[ance]);
}

//##########################################################################################

void sol1(int a, int b, int g1, int g2){
	if(num[g1] > num[g2]) swap(g1, g2);
	if(low[g2] != num[g2]){
		cout << "yes" << '\n';
		return ;
	}
	if((check(a, g2) && !check(b, g2)) || (!check(a, g2) && check(b, g2))){
		cout << "no" << '\n';
		return ;
	} 
	cout << "yes" << '\n';
	return ;
}

//#########################################################################################

int find_ance(int u, int c){
	for(int i = 20; i >= 0; i--){
		if(depth[p[u][i]] > depth[c]) u = p[u][i];
	}
	return u;
}

//#########################################################################################

void sol2(int a, int b, int c){
	if(!joint[c]){
		cout << "yes" << '\n';
		return ;
	}
	int pa , pb;
	pa = pb = 0;
	if(check(a, c)) pa = find_ance(a, c);
	if(check(b, c)) pb = find_ance(b, c);
	if(pa == pb){
		cout << "yes" << '\n';
		return ;
	}
	if(pa == 0 && pb == 0){
		cout << "yes" << '\n';
		return ;
	}
	if(pa == 0 && low[pb] < num[c]){
		cout << "yes" << '\n';
		return ;
	}
	if(pb == 0 && low[pa] < num[c]){
		cout << "yes" << '\n';
		return ;
	}
	if(pa != 0 && pb != 0 && low[pa] < num[c] && low[pb] < num[c]){
		cout <<"yes" << '\n';
		return ;
	}
	cout << "no\n";
}

int main(){

	cin >> n >> e;
	for(int i = 1; i <= e; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	build_sparse();

	//for(int i = 1; i <= n; i++) cout << i << " " << joint[i] << '\n';
	
	int q;
	cin >> q;
	while(q --){
		int x, a, b, c, d;
		cin >> x;
		if(x == 1){
			cin >> a >> b >> c >> d;
			sol1(a, b, c, d);
		}
		else{
			cin >> a >> b >> c;
			sol2(a, b, c);
		}
	}
}