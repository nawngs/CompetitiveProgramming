#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll n, a[200003], b[200003], cnt[200003], res[200003], s[200003];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        s[i] = s[i - 1] + b[i];
        cnt[i] = res[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        int l = i, r = n, mid, ans = i - 1;
        while (l <= r) {
            mid = (l + r) / 2;
            if (a[i] >= s[mid] - s[i - 1]) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        cnt[i] ++; cnt[ans + 1] --;
        a[i] = a[i] - s[ans] + s[i - 1];
        res[ans + 1] += a[i];
    }
    for (int i = 1; i <= n; i++) {
        cnt[i] += cnt[i - 1];
        cout << cnt[i] * b[i] + res[i] << " ";
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while(t--) solve();
}
