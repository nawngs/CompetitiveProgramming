#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll n, a[300005], f[100005], g[100005];

int main() {
	cin >> n;
	for (int i = 1; i <= 3 * n; i++) cin >> a[i];
	priority_queue < ll, vector < ll > , greater < ll > > heap;
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += a[i];
		heap.push(a[i]);
	}
	f[0] = sum;
	for (int i = 1; i <= n; i++) {
		if (a[n + i] > heap.top()) {
			sum -= heap.top();
			sum += a[n + i];
			heap.pop();
			heap.push(a[n + i]);
		}
		f[i] = sum;
	}
	sum = 0;
	priority_queue < ll, vector < ll > > pq;
	for (int i = 1; i <= (n * 3) / 2; i++) swap(a[i], a[3 * n - i + 1]);
	for (int i = 1; i <= n; i++) {
		sum += a[i];
		pq.push(a[i]);
	}
	g[0] = sum;
 	for (int i = 1; i <= n; i++) {
 		if (a[n + i] < pq.top()) {
 			sum -= pq.top();
 			sum += a[n + i];
 			pq.pop();
 			pq.push(a[n + i]);
 		}
 		g[i] = sum;
	}
	ll ans = -1e18;
	for (int i = 0; i <= n; i++) ans = max(ans, f[i] - g[n - i]);
	cout << ans;
}
