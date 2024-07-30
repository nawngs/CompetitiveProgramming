#include <bits/stdc++.h>

using namespace std;
#define task "code"
#define ll long long

const int inf = 1e9;

int x, pos = 0, l = -inf, r = inf, sl = 40;

int C (int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    int x; cin >> x;
    return x;
}

void guess (int l, int r) {
    if (l == r) {
        cout << "! " << l << endl;
        exit(0);
    }
    mt19937 mt(time(nullptr));
    if (sl == 0) {
        cout << "! " << (mt()&1 ? l : r) << endl;
        exit(0);
    }
    sl --;
//    cout << '*';
    if (mt()&1) {
        x = C(l, l);
        if (x == 0) guess(r, r);
        else guess(l-1, l+1);
    }
    else {
        x = C(r, r);
        if (x == 0) guess(l, l);
        else guess(r-1, r+1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (sl -- && r - l > 5) {
        int m = l + r >> 1;
        x = C(l, m);
        if (x == 0) l = m + 1;
        else l = l - 1, r = m + 1;

        if (l == r) return cout << "! " << l, 0;
    }

    for (int i = l; i <= r; ++ i) {
        if (C(i, i) == 1) {
            l = i-1; r = i+1;
            break;
        }
    }

    guess(l, r);

    return 0;
}
