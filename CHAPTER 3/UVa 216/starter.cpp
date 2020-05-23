#include <bits/stdc++.h>
#include <cmath>
#include <math.h>
using namespace std;


pair<double,vector<int>> compute(vector<pair<double,double>>& cord, int pos, int mask, vector<int> path){
    
    if(mask== (1<<cord.size())-1)return pair<int,vector<int>>(0,path);
    
    pair<double,vector<int>> ans = pair<double,vector<int>>(INT_MAX,path);

    for(int i = 0; i < cord.size(); i++){
        if((mask&(1<<i)) == 0 && i != pos){
            double x = cord[pos].first  - cord[i].first;
            double y = cord[pos].second - cord[i].second;
            double dist = sqrt(pow(x,2) + pow(y,2)) + 16;
            vector<int> new_path = path;
            new_path.push_back(i);
            pair<double,vector<int>> hold = compute(cord, i, mask|(1<<i), new_path);
            if(hold.first+dist <= ans.first){
                ans.first = hold.first+dist;
                ans.second = hold.second;
            }
        }
    }
    return ans;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int comps;
    int net = 1;
    while(cin>>comps){
        if(comps == 0)break;

        vector<pair<double,double>> cord;
        while(comps--){
            int x,y;
            cin>>x>>y;
            cord.push_back(pair<int,int>(x,y));
        }
        pair<double,vector<int>> ans = pair<double,vector<int>>(INT_MAX,vector<int>());

        for(int i = 0;i < cord.size();i++){
            vector<int> start = vector<int>(1,i);
            pair<double,vector<int>> hold = compute(cord, i,(1<<i),start);
            if(hold.first <= ans.first){
                ans.first = hold.first;
                ans.second = hold.second;
            }
        }
        cout<<"**********************************************************\n";
        cout<<"Network #"<<net<<"\n";
        for(int i = ans.second.size()-1; i >0 ;i--){
            double x = cord[ans.second[i]].first  - cord[ans.second[i-1]].first;
            double y = cord[ans.second[i]].second - cord[ans.second[i-1]].second;
            double dist = sqrt(pow(x,2) + pow(y,2)) + 16;
            cout<<fixed<<setprecision(0);
            cout<<"Cable requirement to connect ("<<cord[ans.second[i]].first<<","<<cord[ans.second[i]].second<<") to ("<<cord[ans.second[i-1]].first<<","<<cord[ans.second[i-1]].second<<") is ";
            cout<<fixed<<setprecision(2)<<dist<<" feet."<<"\n";
        }
        cout<<"Number of feet of cable required is "<<fixed<<setprecision(2)<<ans.first<<".\n";

        net++;
    }
}