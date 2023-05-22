#include <bits/stdc++.h>

using namespace std;

long long t, a[17002], it[35003], n, k;

void build() {
    for (int i = n; i >= 1; i--)
        it[i] = min(it[i << 1], it[i << 1 | 1]);
}

long long query(int l, int r) {
    long long res = 1e18;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = min(res, it[l ++]);
        if (r & 1) res = min(res, it[-- r]);
    }
    return res;
}

int main(){
	cin >> t;
	while(t --){
		cin >> n >> k;
		for(long long i = 1; i <= n; i++) cin >> it[i + n];
		build();
		for (int i = 1; i <= n - k + 1; i++)
            cout << query(i, i + k) << ' ';
        cout << '\n';
	}
}

