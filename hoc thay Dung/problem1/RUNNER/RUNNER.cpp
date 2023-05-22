#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <list>
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

const int nmax = 400 * 1000 + 1;
const int LOG = 19;

int N;
int depth[nmax], self[nmax][2], sum[nmax][2], par[nmax][LOG];
vector<int> edges[nmax];

void dfs(int node, int parent) {
    par[node][0] = parent;
    depth[node] = depth[parent] + 1;
    for (int i : edges[node]) {
        if (i == parent)
            continue;
        dfs(i, node);
    }
}
int LCA(int a, int b) {
    if (depth[a] < depth[b])
        swap(a, b);
    for (int i = LOG - 1; i >= 0; i--)
        if (depth[a] - (1 << i) >= depth[b])
            a = par[a][i];
    if (a == b)
        return a;
    for (int i = LOG - 1; i >= 0; i--)
        if (par[a][i] != 0 && par[b][i] != 0 && par[a][i] != par[b][i]) {
            a = par[a][i];
            b = par[b][i];
        }
    return par[a][0];
}
int get_kth_parent(int a, int k) {
    if (k >= depth[a])
        return 0;
    for (int i = LOG - 1; i >= 0; i--)
        if (k >= (1 << i)) {
            a = par[a][i];
            k -= (1 << i);
        }
    return a;
}
void sum_self(int node, int parent) {
    sum[node][0] = self[node][0];
    sum[node][1] = self[node][1];
    for (int i : edges[node]) {
        if (i == parent)
            continue;
        sum_self(i, node);
        sum[node][0] += sum[i][0];
        sum[node][1] += sum[i][1];
    }
}
int main(int argc, const char* argv[]) {
    freopen("RUNNER.INP", "r", stdin);
    freopen("RUNNER.OUT", "w", stdout);
    scanf("%d", &N);
    for (int i = 1; i < N; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i < LOG; i++)
        for (int j = 1; j <= N; j++)
            if (par[j][i - 1] != 0)
                par[j][i] = par[par[j][i - 1]][i - 1];
    for (int i = 2; i <= N; i++) {
        int L = LCA(i - 1, i);
        if (L == i) {
            self[i][0] ++;
            self[i - 1][1] ++;
        }
        else if (L == i - 1) {
            self[i - 1][0] ++;
            self[i][1] ++;
        }
        else {
            self[L][0] ++;
            self[i - 1][1] ++;
            int SL = get_kth_parent(i, depth[i] - depth[L] - 1);
            self[SL][0] ++;
            self[i][1] ++;
        }
    }
    sum_self(1, 0);
    for (int i = 1; i <= N; i++) {
        printf("%d\n", sum[i][1] - sum[i][0] + self[i][0]);
    }

    return 0;
}
