#include <bits/stdc++.h>
using namespace std;

int memo[1<<11][11];

int compute(vector<pair<int,int>> &store, int pos, int mask){
    if(mask == (1<<store.size())-1)
        return abs(store[pos].first - store[0].first) + abs(store[pos].second - store[0].second);
    int res = INT_MAX;
    if(memo[mask][pos] != -1)return memo[mask][pos];
    for(int i = 0; i < store.size();i++){
        if((mask &(1<<i))== 0 && i != pos){
            int dist = abs(store[pos].first - store[i].first) + abs(store[pos].second - store[i].second);
            res = min(dist+compute(store, i, mask|(1<<i)), res);
        }
    }
    return memo[mask][pos] = res;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int testcases;
    cin>>testcases;

    while(testcases--){
        int j,k;
        cin>>j>>k;
        pair<int,int> robot;
        cin>>robot.first>>robot.second;
        vector<pair<int,int>> cord;
        cord.push_back(robot);
        int count;
        cin>>count;
        while(count--){
            int x,y;
            cin>>x>>y;
            cord.push_back(pair<int,int>(x,y));
        }
        memset(memo,-1,sizeof(memo));
        cout<<"The shortest path has length "<<compute(cord, 0,1)<<"\n";
    }
}