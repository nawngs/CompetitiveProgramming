#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
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

/* Author: Van Hanh Pham */

/** END OF TEMPLATE. DRINK A CUP OF TIGERSUGAR BEFORE READING MY CODE. **/

#define MAX   505
const int INF = (int)1e9 + 7;

int numRow, numCol, side;
char board[MAX][MAX];
int sumGain[MAX][MAX], totalBlue;
int minTop[MAX], minBot[MAX], minLeft[MAX], minRight[MAX];

void init(void) {
    scanf("%d%d%d", &numRow, &numCol, &side);
    FOR(i, 1, numRow) scanf("%s", board[i] + 1);
}

int getGain(int top, int bot, int left, int right) {
    return sumGain[bot][right] - sumGain[top - 1][right] - sumGain[bot][left - 1] + sumGain[top - 1][left - 1];
}

int getSquareGain(int top, int left) {
    return getGain(top, top + side - 1, left, left + side - 1);
}

void prepare(void) {
    FOR(i, 1, numRow) FOR(j, 1, numCol)
        sumGain[i][j] = sumGain[i][j - 1] + sumGain[i - 1][j] - sumGain[i - 1][j - 1] +
                        (board[i][j] == 'r') - (board[i][j] == 'b');
    FOR(i, 1, numRow) FOR(j, 1, numCol) totalBlue += board[i][j] == 'b';

    memset(minTop, 0x3f, sizeof minTop);
    memset(minBot, 0x3f, sizeof minBot);
    memset(minLeft, 0x3f, sizeof minLeft);
    memset(minRight, 0x3f, sizeof minRight);

    FOR(i, 1, numRow - side + 1) FOR(j, 1, numCol - side + 1) {
        int top = i, bot = i + side - 1, left = j, right = j + side - 1;
        int gain = getSquareGain(top, left);
        minimize(minTop[bot], gain);
        minimize(minBot[top], gain);
        minimize(minLeft[right], gain);
        minimize(minRight[left], gain);
    }

    FOR(i, 2, numRow) minimize(minTop[i], minTop[i - 1]);
    FORD(i, numRow - 1, 1) minimize(minBot[i], minBot[i + 1]);
    FOR(j, 2, numCol) minimize(minLeft[j], minLeft[j - 1]);
    FORD(j, numCol - 1, 1) minimize(minRight[j], minRight[j + 1]);
}

void process(void) {
    FOR(i, 1, numRow - side + 1) FOR(j, 1, numCol - side + 1) {
        int worst = 0;

        int tmp = getSquareGain(i, j);
        int top = i, bot = i + side - 1, left = j, right = j + side - 1;

        minimize(worst, tmp + minTop[top - 1]);
        minimize(worst, tmp + minBot[bot + 1]);
        minimize(worst, tmp + minLeft[left - 1]);
        minimize(worst, tmp + minRight[right + 1]);

        FOR(x, max(1, top - side + 1), min(bot, numRow - side + 1))
        FOR(y, max(1, left - side + 1), min(right, numCol - side + 1)) {
            int interTop = max(top, x), interBot = min(bot, x + side - 1);
            int interLeft = max(left, y), interRight = min(right, y + side - 1);
            int gain = tmp + getSquareGain(x, y) - 2 * getGain(interTop, interBot, interLeft, interRight);
            minimize(worst, gain);
        }

        printf("%d", totalBlue + worst);
        if (j <= numCol - side) printf(" "); else printf("\n");
    }
}

int main(void) {
#ifdef ONLINE_JUDGE
    freopen("bidoimau.inp", "r", stdin);
    freopen("bidoimau.out", "w", stdout);
#endif // ONLINE_JUDGE
    init();
    prepare();
    process();
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/
