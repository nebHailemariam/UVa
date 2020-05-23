#include <bits/stdc++.h>
using namespace std;


long long memo[101][101];
long long compute(int N,int K){
    if(memo[N][K]!= -1)return memo[N][K];
    if(K == 1)return 1;
    long long a = 0;
    for(int i = 0; i <= N; i++ ){
        a = (a + compute(N-i,K-1))% 1000000;
    }
    return memo[N][K]= a;
}


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int N,K;
    memset(memo, -1, sizeof(memo));
    while(cin>>N>>K && (N != 0 || K != 0)){
        cout<<compute(N,K)<<"\n";
    }
}