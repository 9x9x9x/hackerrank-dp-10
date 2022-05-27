#include <bits/stdc++.h>

const int N = 1000111;
const int INF = 1<<30;
int m[N];
int a[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        m[i + 1] = INF;
    }
    for (int i = 0; i < n; i++) {
        int lo = 0, hi = n;
        while (hi - lo > 1) {
            int md = lo + hi >> 1;
            (m[md] < a[i] ? lo : hi) = md;
        }
        m[hi] = a[i];
    }
    int ans = 0;
    while (ans < n && m[ans + 1] < INF) ans++;
    printf("%d\n", ans);
}

/*
# M2: Python
a = [int(input()) for i in range(int(input()))]
m = [float('inf')]*(len(a)+1)
ans = 0
for i, v in enumerate(a):
    l, r = 0, i + 1
    while r - l > 1:
        k = l + r >> 1
        if m[k] < v:
            l = k
        else:
            r = k
    m[r] = v
    ans = max(ans, r)
print(ans)

*/
