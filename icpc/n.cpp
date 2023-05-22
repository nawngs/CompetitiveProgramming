#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
    string finp = NAME2 + ".inp";
    string fout = NAME + ".out";
    freopen(finp.c_str(), "r", stdin);
    //freopen(fout.c_str(), "w", stdout);
}

string s, t;

int cnt[30][100005], cnt_t[30];

bool check[30];

vector < int > adj[30];

int bs(int val, int pos) {
    int l = 0, r = adj[pos].size() - 1, mid, ans = -1;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (adj[pos][mid] >= val) {
            ans = adj[pos][mid];
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return ans;
}

void sol() {
    cin >> s >> t;
    int m = s.size(), n = t.size();
    for (int i = 0; i < n; ++i) {
        check[t[i] - 'a'] = true;
        ++cnt_t[t[i] - 'a'];
    }
    for (int i = 0; i < m; ++i) if (check[s[i] - 'a']) adj[s[i] - 'a'].emplace_back(i);
    for (int i = m - 1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) cnt[j][i] = cnt[j][i + 1];
        cnt[s[i] - 'a'][i] ++;
    }
    int pre = -1;
    string ans = "";
    for (int i = 0; i < n; ++i) {
        bool tm = false;
        for (int j = 0; j < 26; ++j) {
            if (check[j] && cnt_t[j] > 0) {
                int newpos = bs(pre + 1, j);
                if (newpos == -1) continue;
                bool th = true;
                for (int c = 0; c < 26; ++c) {
                    if (cnt[c][newpos] < cnt_t[c]) {
                        th = false;
                        break;	
                    } 
                }
                if (th == true) {
                    char c = 'a' + j;
                    ans += c;
                    --cnt_t[j];
                    pre = newpos;
                    tm = true;
                    break;
                }
            }
        }
        if (!tm) {
            cout << -1 << '\n';
            return ;
        }
    }
    cout << ans;

}

int main() {
    fast;
    //asdfre();
    int t = 1;
    //cin >> t;
    while (t --) sol();
}