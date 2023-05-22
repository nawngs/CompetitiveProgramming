#include <bits/stdc++.h>

//gspvh define
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

//gspvh
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

const string NAME = "medxor";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
    string finp = NAME + ".inp";
    string fout = NAME + ".out";
    freopen(finp.c_str(), "r", stdin);
    freopen(fout.c_str(), "w", stdout);
}

#define MAX_DIGIT   46
struct Bignum {
    static const int BASE = (int)1e9;
    int digits[MAX_DIGIT], numDigit;
 
    Bignum(long long x = 0) {
        memset(digits, 0, sizeof digits);
        numDigit = 0;
 
        if (x == 0) {
            numDigit = 1;
            return;
        }
 
        while (x > 0) {
            digits[numDigit++] = x % BASE;
            x /= BASE;
        }
    }
 
    void reset(void) {
        memset(digits, 0, sizeof digits);
        numDigit = 1;
    }
 
    Bignum& operator += (const Bignum &x) {
        maximize(numDigit, x.numDigit);
        int carry = 0;
 
        REP(i, x.numDigit) {
            digits[i] += x.digits[i] + carry;
            if (digits[i] >= BASE) {
                digits[i] -= BASE;
                carry = 1;
            } else carry = 0;
        }
 
        if (carry > 0) {
            int pos = x.numDigit;
            while (true) {
                digits[pos++]++;
                if (digits[pos - 1] == BASE) digits[pos - 1] = 0;
                else break;
            }
            maximize(numDigit, pos);
        }
 
        return *this;
    }
 
    Bignum operator + (const Bignum &x) const {
        Bignum res = *this;
        return res += x;
    }
 
    Bignum& operator -= (const Bignum &x) {
        int remain = 0;
        REP(i, x.numDigit) {
            digits[i] -= x.digits[i] + remain;
            if (digits[i] < 0) {
                digits[i] += BASE;
                remain = 1;
            } else remain = 0;
        }
 
        if (remain > 0) {
            int pos = x.numDigit;
            while (true) {
                digits[pos++]--;
                if (digits[pos - 1] < 0) digits[pos - 1] += BASE;
                else break;
            }
        }
 
        while (numDigit > 1 && digits[numDigit - 1] == 0) numDigit--;
 
        return *this;
    }
 
    Bignum operator - (const Bignum &x) const {
        Bignum res = *this;
        return res -= x;
    }
 
    Bignum operator * (const Bignum &x) const {
        if (isZero() || x.isZero()) return 0;
        Bignum res;
        REP(i, numDigit) if (digits[i] > 0) REP(j, x.numDigit) {
            long long tmp = 1LL * digits[i] * x.digits[j];
            int pos = i + j;
            while (tmp > 0) {
                res.digits[pos] += tmp % BASE;
                tmp /= BASE;
                if (res.digits[pos] >= BASE) {
                    res.digits[pos] -= BASE;
                    tmp++;
                }
 
                pos++;
            }
        }
 
        res.numDigit = numDigit + x.numDigit;
        if (res.digits[res.numDigit - 1] == 0) res.numDigit--;
 
        return res;
    }
 
    Bignum operator / (int k) const {
        Bignum res;
        res.numDigit = 0;
 
        int remain = 0;
        FORD(i, numDigit - 1, 0) {
            long long tmp = 1LL * remain * BASE + digits[i];
            res.digits[res.numDigit++] = tmp / k;
            remain = tmp % k;
        }
 
        reverse(res.digits, res.digits + res.numDigit);
        while (res.numDigit > 1 && res.digits[res.numDigit - 1] == 0) res.numDigit--;
        return res;
    }
 
    bool isZero(void) const {
        return numDigit == 1 && digits[0] == 0;
    }
 
    #define COMPARE(x, y) (((x) > (y)) - ((x) < (y)))
    int cmp(const Bignum &x) const {
        if (numDigit != x.numDigit) return COMPARE(numDigit, x.numDigit);
        FORD(i, numDigit - 1, 0) if (digits[i] != x.digits[i]) return COMPARE(digits[i], x.digits[i]);
        return 0;
    }
 
    #define DEFINE_OPERATOR(o) bool operator o (const Bignum &x) const { return cmp(x) o 0; }
    DEFINE_OPERATOR(<) DEFINE_OPERATOR(<=) DEFINE_OPERATOR(==)
    DEFINE_OPERATOR(>) DEFINE_OPERATOR(>=) DEFINE_OPERATOR(!=)
    #undef DEFINE_OPERATOR
 
    string toDecimal(void) const {
        string res;
        REP(i, numDigit) {
            int tmp = digits[i];
            REP(love, 9) {
                res.push_back(tmp % 10 + '0');
                tmp /= 10;
            }
        }
        while (res.size() > 1 && res.back() == '0') res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};
 
istream& operator >> (istream &is, Bignum &b) {
    string s; is >> s;
 
    reverse(ALL(s));
    b = 0;
    b.numDigit = (s.size() + 8) / 9;
    FORD(i, s.size() - 1, 0) b.digits[i / 9] = b.digits[i / 9] * 10 + s[i] - '0';
 
    return is;
}
 
ostream& operator << (ostream &os, const Bignum &b) {
    return os << b.toDecimal();
}

const int BIT_MAX = 670;

Bignum aa, bb, cc, dd, Pow2[BIT_MAX + 5];

int a[BIT_MAX + 5], b[BIT_MAX + 5], c[BIT_MAX + 5], d[BIT_MAX + 5];

Bignum suffab[BIT_MAX + 5][2][2], suffcd[BIT_MAX + 5][2][2], f[BIT_MAX + 5][2][2][2][2];

void convert_to_binary(Bignum x, int a[]) {
    for (int i = BIT_MAX; i >= 0; i--) {
        if (x >= Pow2[i]) {
            a[i] = 1;
            x -= Pow2[i];
        }
        else a[i] = 0;
    }
}

void UpdatePrefix(int pos, int cur) {
    for (int ca = 0; ca < 2; ca++)
    for (int cb = 0; cb < 2; cb++)
    for (int cc = 0; cc < 2; cc++)
    for (int cd = 0; cd < 2; cd++) 
        f[pos][ca][cb][cc][cd].reset();
    for (int ca = 0; ca < 2; ca++)
    for (int cb = 0; cb < 2; cb++)
    for (int cc = 0; cc < 2; cc++)
    for (int cd = 0; cd < 2; cd++) {
        if (f[pos + 1][ca][cb][cc][cd].isZero()) continue;
        //if (pos == 4) cout << ca << " " << cb << " " << cc << " " << cd << " " << f[pos + 1][ca][cb][cc][cd] << '\n';
        for (int vab = 0; vab < 2; vab++) {
            int vcd = (cur ^ vab);
            if (!ca && vab < a[pos]) continue;
            if (!cb && vab > b[pos]) continue;
            if (!cc && vcd < c[pos]) continue;
            if (!cd && vcd > d[pos]) continue;
            f[pos][(ca || vab > a[pos])][(cb || vab < b[pos])][(cc || vcd > c[pos])][(cd || vcd < d[pos])] += f[pos + 1][ca][cb][cc][cd];
        }
    }
}

Bignum calc(int pos) {
    Bignum ans = 0;
    for (int ca = 0; ca < 2; ca++)
    for (int cb = 0; cb < 2; cb++)
    for (int cc = 0; cc < 2; cc++)
    for (int cd = 0; cd < 2; cd++) 
        ans += f[pos][ca][cb][cc][cd] * suffab[pos][ca][cb] * suffcd[pos][cc][cd];
    return ans;
}

void sol() {
    cin >> aa >> bb >> cc >> dd;
    convert_to_binary(aa, a);
    convert_to_binary(bb, b);
    convert_to_binary(cc, c);
    convert_to_binary(dd, d);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) 
            suffab[0][i][j] = suffcd[0][i][j] = 1;
    for (int i = 1; i <= BIT_MAX; i++) 
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++) {
                suffab[i][j][k] = suffcd[i][j][k] = 0;
                for (int nxt = 0; nxt < 2; nxt++) {
                    if ((j || nxt >= a[i - 1]) && (k || nxt <= b[i - 1])) {

                        suffab[i][j][k] += suffab[i - 1][j || (nxt > a[i - 1])][k || (nxt < b[i - 1])];
                    }
                    if ((j || nxt >= c[i - 1]) && (k || nxt <= d[i - 1])) 
                        suffcd[i][j][k] += suffcd[i - 1][j || (nxt > c[i - 1])][k || (nxt < d[i - 1])];
                }
                //if (i == 3) cout << i << " " << j << " " << k << " " << suffab[i][j][k] << " " << suffcd[i][j][k] << '\n';

            }
    f[BIT_MAX + 1][0][0][0][0] = 1;
    Bignum total = (bb - aa + 1) * (dd - cc + 1);
    total = (total + 1) / 2;
    Bignum res = 0;
    for (int i = BIT_MAX; i >= 0; i--) {
        UpdatePrefix(i, 0);
        Bignum temp = calc(i);
        //cout << i << " " << temp << " " << total << '\n';
        if (temp < total) {
            total -= temp;
            res += Pow2[i];
            UpdatePrefix(i, 1);
        }
    }
    cout << res << '\n';
}  

int main() {
    fast;
    //fre();
    Pow2[0] = 1;
    for (int i = 1; i <= BIT_MAX; i++) 
        Pow2[i] = Pow2[i - 1] * 2;
    int t = 1;
    cin >> t;
    while (t --) sol();
}
