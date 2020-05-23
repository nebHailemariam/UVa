#include <bits/stdc++.h>
using namespace std;


int memo[101][10001];

int compute(vector<pair<int,int>> &store, int i, int expense, int m) {
    if(expense > m && m < 1800 || expense-200 > m)
        return INT_MIN;
    if(i == store.size()) {
        if(expense > m && expense <= 2000)
            return INT_MIN;
        return 0;
    }
    if(memo[i][expense] != -1)
        return memo[i][expense];

    return memo[i][expense] = max(compute(store, i + 1, expense, m), store[i].second + compute(store, i + 1, expense + store[i].first,m));
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int m,n;
    
    while(cin>>m>>n){
        vector<pair<int,int>> store;
        
        while(n--){
            int p, f;
            cin>>p>>f;
            store.push_back(pair<int,int>(p,f));
        }
        memset(memo, -1,sizeof(memo));
        cout<<compute(store,0,0,m)<<"\n";
    }

}