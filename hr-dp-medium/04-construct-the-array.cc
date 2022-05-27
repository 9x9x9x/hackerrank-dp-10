#include "bits/stdc++.h"
#define MAXN 100009
#define INF 1000000007
using namespace std; 
typedef long long ll;
int dp[MAXN];
int mod(ll x){
	while(x<0)
		x+=INF;
	return (x%INF);	
}
int Fe(int x,int y){
	if(!y)
		return 1LL;
	int h=Fe(x,y/2);
	h=mod(h*1LL*h);
	if(y&1)
		h=mod(h*1LL*x);
	return h;	
}
int main(){
	int N,K,X;
	scanf("%d%d%d",&N,&K,&X);
	assert(3<=N and N<=100000);
	assert(2<=K and K<=100000);
	assert(1<=X and X<=K);
	dp[0]=1;
	for(int i=2;i<=N;i++)	
		dp[i]=mod(mod(dp[i-2]*1LL*(K-1))+mod(dp[i-1]*1LL*(K-2)));
	if(X==1)
		printf("%d\n",dp[N-1]);
	else
		printf("%d\n",mod(dp[N]*1LL*Fe(K-1,INF-2)));
	return 0;
}


/*
#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, x;
    cin >> n >> k >> x;
    assert(3 <= n && n <= 100000);
    assert(2 <= k && k <= 100000);
    assert(1 <= x && x <= k);
    int d[n];
    d[0] = 0;
    d[1] = 1;
    for(int i = 2; i < n; i++)
        d[i] = (1LL * (k - 2) * d[i - 1] + 1LL * (k - 1) * d[i - 2]) % mod;
    cout << (x == 1 ? 1LL * (k - 1) * d[n - 2] % mod : d[n - 1]) << endl;
}
*/
