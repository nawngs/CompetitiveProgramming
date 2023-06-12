#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define piii pair < pii, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int f, M, k, cnt[100003], s[100003], timer = 0, cur[100003];

bool added[1000003], deleted[100003];

pii edge_val[1000003];

vector < int > ver, edges[100003], mp[1000003], res, tmp;

map < pii, int > id_ed;

int main() {
	fast;
	cin >> f >> M;
	for (int i = 1; i <= f; i++) {
		int k;
		cin >> k;
		tmp.clear();
		ver.resize(k);
		for (auto &x : ver) cin >> x;
		sort(ver.begin(), ver.end());
		cin >> s[i];
		for (int p = 0; p < k; p++) {
				pii edge = make_pair(ver[p], ver[(p + 1) % k]);
				if (p == k - 1) swap(edge.fi, edge.se);
				if (id_ed.find(edge) == id_ed.end()) {
					id_ed[edge] = ++ timer;
					edge_val[timer] = edge;
				}
				cnt[i] ++;
				edges[i].push_back(id_ed[edge]);
				mp[id_ed[edge]].push_back(i);
		}
	}
	queue < pii > que;
	for (int i = 1; i <= timer; i++)
		if (mp[i].size() == 1) {
			que.push({i, mp[i][0]});
		}
	while (que.size()) {
		auto x = que.front();
		que.pop();
		if (added[x.fi]) continue;
		added[x.fi] = 1;
		res.push_back(x.fi);
		if (deleted[x.se]) continue;
		deleted[x.se] = 1;
		for (auto v : edges[x.se]) {
			for (auto new_ : mp[v]) {
				if (new_ == x.se) continue;
				que.push({v, new_});
			}
		}
	}
	reverse(res.begin(), res.end());
	for (auto x : res) {
		int valu = 0;
		for (auto v : mp[x])
			if (cnt[v] == 1) valu = (s[v] - cur[v] + M) % M;
		cout << edge_val[x].fi << " " << edge_val[x].se << " " << valu << '\n';
		for (auto v : mp[x]) {
			cnt[v] --;
			cur[v] = (cur[v] + valu) % M;
		}
	}
}

/*
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
using pii = pair<int, int>;
#define fi first
#define se second
#define M(p, q) make_pair((p), (q))
pii ax(int i, int j){
    if (i > j) swap(i, j);
    return M(i, j);
}
#define pb push_back
map<pii, int> id;
int cnt, f, m, s[N], ind[10*N];
vector<int> ed[10*N], adj[10*N];
int cur[N], lef[N], res[N];
pii pai[10*N];
void process(int u, int v){
    cout << pai[u].fi << " " << pai[u].se << " " << v << '\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> f >> m;
    for (int i = 1; i <= f; i++){
        int k; cin >> k;
        vector<int> tmp, cool;
        for (int j = 0; j < k; j++){
            int x; cin >> x;
            tmp.pb(x);
        }
        cin >> res[i];
        for (int j = 0; j < k; j++){
            pii X = ax(tmp[j], tmp[(j + 1) % k]);
            if (id.find(X) == id.end())
                id[X] = ++cnt, pai[cnt] = X;
            cool.pb(id[X]);
            ed[id[X]].pb(i);
        }
        for (int j = 0; j < k; j++){
            adj[cool[(j + 1) % k]].pb(cool[j]);
            adj[cool[(j + 1) % k]].pb(cool[(j + 2) % k]);
        }
    }
    queue<int> q; stack<int> st;
    for (int i = 1; i <= cnt; i++){
        sort(adj[i].begin(), adj[i].end());
        adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
        ind[i] = ed[i].size() - 1;
        if (!ind[i]) q.push(i);
        //process(i, ind[i]);
    }

    while (!q.empty()){
        int u = q.front();
        q.pop();
        st.push(u);
        for (auto c: adj[u]){
            ind[c]--;
            if (!ind[c]) q.push(c);
        }
    }
    for (int i = 1; i <= cnt; i++)
        for (auto c: ed[i]) lef[c]++;
    while (!st.empty()){
        int u = st.top();
        st.pop();
        int rest = 0;
        for (auto c: ed[u]){
            if (lef[c] == 1)
                rest = res[c] - cur[c];
        }
        if (rest < 0) rest += m;
        for (auto c: ed[u]){
            (cur[c] += rest) %= m;
            lef[c]--;
        }
        process(u, rest);
    }
}
*/
