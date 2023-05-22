#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define FORC(i, a, b, c) for (int i = (a), _b = (b); i <= _b; i+=(c))
#define FORM(i, a, b, c) for (int i = (a), _b = (b); i <= _b; i*=(c))
#define FORS(i, a, b) for (int i = (a), _b = (b); i < _b; i++)
#define ll long long
#define fi first
#define se second
#define pb push_back
#define MASK(i) (1 << (i))
#define MASKLL(i) (1LL << (i))
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define revall(x) (x).rbegin(), (x).rend()
#define print(x) cout<<"["<<(x)<<"] "
#define gc(x) ((x) - 'a')
#define popcountll(x) __builtin_popcountll((x))
#define popcount(x) __builtin_popcount((x))
void minimize(int& a, int b){ a = min(a, b); }
void maximize(int& a, int b){ a = max(a, b); }
void setIO(string name = ""){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if ((int)(name.size())){
        freopen((name + ".inp").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
const int N = 2e5 + 5;
const int INF = 1e9 + 1;
/// --- Basic inp and ans --- ///
int t, n, ans[N];
pii a[N];
/// ------ pre , maxend , vector(stack) ------ ///
int pre[N], mxe[N];
vector<int> v;
int main(){
    setIO();
    cin >> t;
    while (t--){
        cin >> n;
        FOR(i, 1, n){
            cin >> a[i].fi >> a[i].se;
        }
        sort(a + 1, a + 1 + n);
        /// --- them vao vi dep vl --- ///
        pre[1] = 1; mxe[1] = a[1].se;
        FOR(i, 2, n){
            pre[i] = pre[i - 1] + (a[i].fi > mxe[i - 1]);
            mxe[i] = max(mxe[i - 1], a[i].se);
        }
        v.clear();
        FORD(i, n, 2){
            int it = v.rend() - upper_bound(revall(v), mxe[i - 1]);
            ans[i] = pre[i - 1] + it;
            while (!v.empty() && v.back() <= a[i].se){
                v.pop_back();
            }
            v.pb(a[i].fi);
        }
        int res = 0;
        maximize(res, v.size());
        FOR(i, 2, n) maximize(res, ans[i]);
        cout << res << '\n';
    }
}
