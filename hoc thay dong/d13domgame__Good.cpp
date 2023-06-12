#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
using ll = long long;
using pii = pair<int, int>;
#define fi first
#define se second
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
int n, m, a[N], cnt;
bool check(int i, int j) {
    return (0 <= i && i < n && 0 <= j && j < m && a[i*m+j] == 0);
}
vector<int> adj[N], List[2];
bool vis[N];
int conv(int i, int j) {
    return i*m+j;
}

void dfs(int u) {
    vis[u]=true;
    for (auto c: adj[u]) {
        if (!vis[c]) dfs(c);
    }
}

int ass[N], vist[N], cap[N], t;

bool dfs1(int u) {
    if (vist[u] == t) return false;
    vist[u] = t;

    for (auto c: adj[u]) {
        //cout << u << " " << c << " " << ass[c] << '\n';
        if (ass[c] == -1 || dfs1(ass[c])) {
            ass[c]=u;
            cap[u]=c;
            return true;
        }
    }
    return false;
}

queue<pii> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
        char x;
        cin >> x;
        a[i*m + j] = (x == '.' ? 0 : 1);
        if (x == '.') List[(i+j)&1].push_back(conv(i, j));
    }
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
        for (int t = 0; t < 4; t++) {
            int ii = i + dx[t];
            int jj = j + dy[t];
            if (!check(ii, jj)) continue;
            adj[conv(i, j)].push_back(conv(ii, jj));
        }
    }
    n = List[0].size();
    m = List[1].size();
    t = 0;
    memset(ass, -1, sizeof ass);
    //cout << ass[1] << ", " << ass[2] << '\n';
    for (auto c: List[0]) {
        ++t;
        dfs1(c);
        //cout << cap[c] << " " << ass[1] << " " << ass[2] << '\n';
    }
    //for (auto c: List[0]) cout << c << ", " << cap[c] << '\n';
    ll ans = 1LL*n*(n-1)/2 + 1LL*m*(m-1)/2;
    if (ans > N-5) return cout << 1000000, 0;
    for (auto c: List[0]) {
        for (auto v: List[0]) vis[v]=false;
        for (auto v: List[1]) vis[v]=false;
        vis[c]=true;
        q.emplace(c, 0);
        while (!q.empty()) {
            int u = q.front().fi,
                v = q.front().se;

            q.pop();
            if (!v) {
                if (!vis[cap[u]]) {
                    vis[cap[u]]=true;
                    q.emplace(cap[u], 1);
                }
            } else {
                for (auto d: adj[u]) {
                    if (!vis[d]) {
                        vis[d]=true;
                        q.emplace(d, 0);
                    }
                }
            }
        }
        for (auto v: List[1]) if (!vis[v]) ans++;
    }
    if (ans > N-5) return cout << 1000000, 0;
    cout << ans;
}
