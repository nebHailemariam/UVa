#include <bits/stdc++.h>
using namespace std;

long long memo[300001][5];
int coins[] = {1,5,10,25,50};
map<int,long long> store;

long long compute(int m, int i){
    if(m == 0)return 1;
    if(i > 4||m < 0)return 0;

    if(memo[m][i] !=-1)
        return memo[m][i];
    if(coins[i] <= m){
        memo[m][i]= compute(m-coins[i],i) + compute(m,i+1);
        return memo[m][i];
    }return 0;
}
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    memset(memo, -1, sizeof(memo));
    int temp = compute(30000,0);
    memo[0][0] = 1;
    int m;
    while(cin>>m){
         
        (memo[m][0] == 1)?cout<<"There is only 1 way to produce "<<m<<" cents change."<<"\n":cout<<"There are "<<memo[m][0]<<" ways to produce "<<m<<" cents change.\n";

    }

}