#include <bits/stdc++.h>
using namespace std;
 
//types
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define pld pair<ld, ld>
#define pii pair<int, int>
 
#define fi first
#define se second
 
const ld PI = 3.14159265359;
const ll mx = 3e5+5, mod = 1e9+7;

int n, m, a[mx], lh[mx];

pii edges[mx], cnt[mx];

vector<int> adj[mx];

vector<int> res, ans;
 
bool check(int val) {
    res.clear();
    for (int i = 1; i <= n; i++) adj[i].clear(), lh[i] = 0;
    for (int i = 1; i <= val; i++) {
        adj[edges[i].se].push_back(edges[i].fi);
        lh[edges[i].fi]++;
    }
 
    int cnt, pos, expect = 0;
    cnt = 0, pos = 1;
    for (int i = 1; i <= n; i++) {
        if (lh[i] == 0) {
            if (cnt) return false;
            cnt = 1;
            pos = i;
        }
    }
    if (!cnt) return false;
 
    res.push_back(pos);
    for (int tmp = 1; tmp <= n-1; tmp++) {
        cnt = 0;
        for (auto i : adj[pos]) {
            lh[i]--;
            if (lh[i] == 0) {
                if (cnt) return false;
                cnt = 1;
                pos = i;
                res.push_back(pos);
            }
        }
    }
    if (!cnt) return false;
    ans = res;
    return true;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 
    freopen("harem.inp", "r", stdin);
    freopen("harem.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> edges[i].fi >> edges[i].se;
    
    int l = 1, r = m, kq = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (!check(mid)) l = mid+1;
        else
        {
            kq = mid;
            r = mid-1;
        }
    }
    cout << kq << '\n';
    if (kq != -1) {
   		 reverse(ans.begin(), ans.end());
    	for (auto i : ans) cout << i << " "; 	
    }
   
}