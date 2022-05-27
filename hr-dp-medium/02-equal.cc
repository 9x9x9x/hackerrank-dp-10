#include<iostream>
#include<cstdio>
#define INT_MAX 2000000000
    
using namespace std;
    
long long int functn (long long int temp)  // similar to greedy Coin-change
{
    long long int x=0;
    if(temp>=5)
    {
        x = temp/5;
        temp = temp%5;
    }
    if(temp>=2)
    {
        x += temp/2;
        temp = temp%2;
    }
    x += temp;
    return x;
    
}
    
int array_smallest(long long int array[],int array_length)
{
    long long int smallest = INT_MAX;
    long long int i;
    for (i = 0; i < array_length; i++)
    {
        if (array[i] < smallest) {
            smallest = array[i];
        }
    }
    return smallest;
}
    
long long int mod(long long int x)
{
    if(x>0)
        return x;
    else
        return (-1)*x;
}
    
int main()
{
    long long int T,N,i,j,min,sum,temp;
    cin>>T;
    while(T--)
    {
        min = 1000000;
        cin>>N;
        int A[N];
        for(i=0 ; i< N ; i++)
        {
            cin>>A[i];
            if(A[i]<min)
                min = A[i];
        }
        long long int sum[6];
        for(j=0 ; j<=5 ; j++)
        {
            sum[j]=0;
            for(i=0 ; i< N ; i++)
            {
                temp = mod(A[i] - (min-j));
                sum[j] = sum[j] + functn(temp);
            }
        }
        cout<<array_smallest(sum,6)<<endl;
    }
    return 0;
}


/*
#include<cassert>
#include<iostream>
#include<algorithm>
using namespace std;
    
int T, N;
int d[100010];
    
int main() {
    cin >> T;
    assert(T <= 100);
    while(T--) {
        cin >> N;
        assert(N <= 10000);
        for(int i = 0; i < N; i++) 
        {cin >> d[i]; assert(d[i] < 1000);}
        int M = *min_element(d, d + N);
        int r = 1e9;
        for(int t = M - 4; t <= M; t++) {
            int s = 0;
            for(int i = 0; i < N; i++) {
                int D = d[i] - t;
                s += D / 5, D %= 5;
                s += D / 2, D %= 2;
                s += D;
            }
            r = min(r, s);
        }
        cout << r << endl;
    }
    return 0;
}

*/
