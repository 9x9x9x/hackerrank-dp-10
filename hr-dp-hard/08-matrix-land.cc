#include <bits/stdc++.h>
#define MA(x,y) ((x) > (y) ? (x) : (y))

using namespace std;

const int N = 4000005;

int n, m;

vector <vector <int> > a, dp;
vector <int> msl, msr, d;

void input(){
    scanf("%d %d", &n, &m);

    msl.resize(m+2,0);
    d = msr = msl;

    a.resize(n+2, d);
    dp = a;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void sol(){
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            msl[j] = MA(msl[j-1] + a[i][j],0);
        for (int j = m; 0 < j; j--)
            msr[j] = MA(msr[j+1] + a[i][j],0);

        d[1] = dp[i-1][1] + a[i][1];
        dp[i][1] = d[1] + msr[2];
        for (int j = 2; j <= m; j++) {
            d[j] = MA(d[j-1] + a[i][j], dp[i-1][j] + a[i][j] + msl[j-1]);
            dp[i][j] = d[j] + msr[j + 1];
        }

        d[m] = dp[i-1][m] + a[i][m];
        dp[i][m] = MA(dp[i][m], d[m] + msl[m - 1]);
        for (int j = m - 1; 0 < j ; j--) {
            d[j] = MA(d[j+1] + a[i][j], dp[i-1][j] + a[i][j] + msr[j+1]);
            dp[i][j] = MA(dp[i][j], d[j] + msl[j - 1]);
        }
    }

    int ans = dp[n][1];
    for (int i = 2; i <= m; i++) {
        ans = MA(ans, dp[n][i]);
    }

    printf("%d\n", ans);
}

int main() {
    input();
    sol();
    return 0;
}

/*
#include <bits/stdc++.h>
#define forn(i,n) for (int i = 0; i < int(n); ++i)
using namespace std;

const int N = int(4e6) + 5;
int dp[2][N];
int a[N], s[N];
int best[N];

int main() {
    int n, m;
    assert(cin >> n >> m);
    assert(1 <= n * m && n * m <= int(4e6));
    memset(dp, 0, sizeof(dp));

    int t = 0;
    forn(_, n) {
        t = !t;

        forn(j, m) {
            assert(scanf("%d", &a[j]) == 1);
            assert(abs(a[j]) <= 250);
        }

        forn(r, 2) {
            s[0] = 0;
            forn(i, m)
                s[i + 1] = s[i] + a[i];

            best[m] = s[m];
            for (int i = m - 1; i >= 0; --i)
                best[i] = max(s[i], best[i + 1]);

            int mx = -s[0], mxw = -s[0] + dp[!t][0];
            forn(i, m) {
                mxw = max(mxw, mx + dp[!t][i]);

                int val = mxw + best[i + 1];
                if (!r)
                    dp[t][i] = val;
                else
                    dp[t][i] = max(dp[t][i], val);

                mx = max(mx, -s[i + 1]);
            }

            forn(i, 2)
                reverse(dp[i], dp[i] + m);
            reverse(a, a + m);
        }
    }

    cout << *max_element(dp[t], dp[t] + m) << endl;
    return 0;
}
*/
