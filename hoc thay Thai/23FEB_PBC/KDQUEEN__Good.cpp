#include <bits/stdc++.h>
using namespace std;

template<int mod> struct ModInt {
   int x;

   ModInt(): x(0) {}

   ModInt(int64_t y): x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

   ModInt & operator += (const ModInt & p) {
      if ((x += p.x) >= mod) x -= mod;
      return *this;
   }

   ModInt & operator -= (const ModInt & p) {
      if ((x += mod - p.x) >= mod) x -= mod;
      return *this;
   }

   ModInt & operator *= (const ModInt & p) {
      x = (int)(1LL * x * p.x % mod);
      return *this;
   }

   ModInt & operator /= (const ModInt & p) {
      * this *= p.inverse();
      return *this;
   }

   ModInt operator - () const {
      return ModInt(-x);
   }

   ModInt operator + (const ModInt & p) const {
      return ModInt( * this) += p;
   }

   ModInt operator - (const ModInt & p) const {
      return ModInt( * this) -= p;
   }

   ModInt operator * (const ModInt & p) const {
      return ModInt( * this) *= p;
   }

   ModInt operator / (const ModInt & p) const {
      return ModInt( * this) /= p;
   }

   bool operator == (const ModInt & p) const {
      return x == p.x;
   }

   bool operator != (const ModInt & p) const {
      return x != p.x;
   }

   ModInt inverse() const {
      int a = x, b = mod, u = 1, v = 0, t;
      while (b > 0) {
         t = a / b;
         swap(a -= t * b, b);
         swap(u -= t * v, v);
      }
      return ModInt(u);
   }

   ModInt pow(int64_t n) const {
      ModInt ret(1), mul(x);
      while (n > 0) {
         if (n & 1) ret *= mul;
         mul *= mul;
         n >>= 1;
      }
      return ret;
   }

   friend ostream & operator << (ostream & os,
      const ModInt & p) {
      return os << p.x;
   }

   friend istream & operator >> (istream & is, ModInt & a) {
      int64_t t;
      is >> t;
      a = ModInt<mod> (t);
      return (is);
   }

   int get() const {
      return x;
   }

   static constexpr int get_mod() {
      return mod;
   }
};

const int MAX_N = 2e5 + 5, mod = 1e9 + 7;
using mint = ModInt<mod>;

int k, n[MAX_N], x[MAX_N], a[MAX_N], b[MAX_N], cnt1[MAX_N], cnt2[MAX_N];

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> k;
  mint ans = 0;
  for (int i = 1; i <= k; i++)
    cin >> n[i], ans += n[i] - 1;
  for (int i = 1; i <= k; i++)
    cin >> x[i];
  vector<int> arr;
  for (int i = 1; i <= k; i++) {
    a[i] = n[i] - x[i];
    b[i] = x[i] - 1;
    if (a[i] > b[i])
      swap(a[i], b[i]);
    arr.emplace_back(a[i]);
    arr.emplace_back(b[i]);
  }
  arr.emplace_back(0);
  sort(arr.begin(), arr.end());
  arr.resize(unique(arr.begin(), arr.end()) - arr.begin());
  for (int i = 1; i <= k; i++) 
    a[i] = lower_bound(arr.begin(), arr.end(), a[i]) - arr.begin(),
    b[i] = lower_bound(arr.begin(), arr.end(), b[i]) - arr.begin(),
    cnt2[1]++, cnt2[a[i] + 1]--,
    cnt1[a[i] + 1]++, cnt1[b[i] + 1]--;
  for (int i = 1, o = arr.size(); i < o; i++) {
    cnt1[i] += cnt1[i - 1], cnt2[i] += cnt2[i - 1];
    if (cnt1[i] + cnt2[i] == k)
      ans += ((mint)2).pow(cnt2[i]) * (arr[i] - arr[i - 1]);
  }
  cout << ans;
  return 0;
}