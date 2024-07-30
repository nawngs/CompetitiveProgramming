#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second
#define pb push_back
#define pss pair < string, string >

using namespace std;

const int NMAX = 1E5;
const ll MOD = 1E9 + 7;
const ll BASE = 2309;

using vl = vector < int >;

int n, m, root[NMAX + 3], res[NMAX + 3];

string rev[NMAX + 3], b[NMAX + 3];

pair < string, vl > s[NMAX + 3];

pair < pss, int > a[NMAX + 3];

map < char, int > charv;

struct Node {
    int nxt[4], cnt;
    Node() {
        cnt = 0;
        for (int i = 0; i < 4; i++) nxt[i] = -1;
    }
};

vector < Node > trie;

void Add() {
    trie.pb(Node());
    trie.back().cnt = 0;
}

void build(int id, int prev) {
    Add(); root[id] = trie.size() - 1;
    int cur = root[id];
    if (prev != -1) for (int i = 0; i < 4; i++) trie[cur].nxt[i] = trie[prev].nxt[i];
    trie[cur].cnt = trie[prev].cnt + 1;
    string news = "";
    for (auto c : rev[id]) {
        Add();
        trie[cur].nxt[charv[c]] = trie.size() - 1;
        cur = trie[cur].nxt[charv[c]];
        if (prev != -1) prev = trie[prev].nxt[charv[c]];
        if (prev != -1) trie[cur].cnt = trie[prev].cnt + 1;
        else trie[cur].cnt = 1;
        news += c;
        //cout << id << " " << news << " " << cur << " " << trie[cur].cnt << '\n';
        if (prev != -1) for (int i = 0; i < 4; i++) trie[cur].nxt[i] = trie[prev].nxt[i];
    }
}

int calc(int cur, const string &a) {
    for (auto c : a) {
        if (trie[cur].nxt[charv[c]] == -1) return 0;
        cur = trie[cur].nxt[charv[c]];
    }
    return trie[cur].cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("RNA.inp", "r", stdin);
    freopen("RNA.out", "w", stdout);
    charv['A'] = 0; charv['G'] = 1; charv['C'] = 2; charv['U'] = 3;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i].fi;
        s[i].se.pb(0);
        for (auto c : s[i].fi) s[i].se.pb((s[i].se.back() * BASE + c) % MOD);
        b[i] = "";
    }
    sort(s + 1, s + n + 1, [&](pair < string, vl > &x, pair < string, vl > &y) {
        int l = 1, r = min(x.fi.size(), y.fi.size()), mid, ans = 0;
        while (l <= r) {
            mid = (l + r) / 2;
            if (x.se[mid] == y.se[mid]) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        if (ans == min(x.fi.size(), y.fi.size())) return x.fi.size() < y.fi.size();
        return x.fi[ans] < y.fi[ans];
    });
    for (int i = 1; i <= n; i++) {
        rev[i] = s[i].fi;
        reverse(rev[i].begin(), rev[i].end());
    }
    Add(); root[0] = 0;
    for (int i = 1; i <= n; i++) build(i, root[i - 1]);
    //for (int i = 1; i <= n; i++) cout << rev[i] << " " << calc(root[i], "A") << '\n';
    for (int i = 1; i <= m; i++) {
        cin >> a[i].fi.fi >> a[i].fi.se;
        a[i].se = i;
        reverse(a[i].fi.se.begin(), a[i].fi.se.end());
    }
    sort(a + 1, a + m + 1, [&](pair < pss, int > &x, pair < pss, int > &y) {
        return x.fi.fi.size() < y.fi.fi.size();
    });
    for (int i = 1; i <= m; i++) {
        if (b[1].size() < a[i].fi.fi.size()) {
            for (int j = 1; j <= n; j++)
                while (b[j].size() < s[j].fi.size() && b[j].size() < a[i].fi.fi.size()) b[j] += s[j].fi[b[j].size()];
        }
        /*cout << i << '\n';
        for (int j = 1; j <= n; j++) cout << b[j] << " ";
        cout << '\n';*/
        int l = 1, r = n, mid, ans;
        while (l <= r) {
            mid = (l + r) / 2;
            if (b[mid] <= a[i].fi.fi) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        if (b[ans] != a[i].fi.fi) continue;
        res[a[i].se] = calc(root[ans], a[i].fi.se);
        l = 1, r = n;
        while (l <= r) {
            mid = (l + r) / 2;
            if (b[mid] >= a[i].fi.fi) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        res[a[i].se] -= calc(root[ans - 1], a[i].fi.se);
    }
    for (int i = 1; i <= m; i++) cout << res[i] << '\n';
}