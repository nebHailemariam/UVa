#include <bits/stdc++.h>
using namespace std;

int UNVISITED = -1;
vector<vector<int>> ADJ_LST;
vector<int> dfs_low;
vector<int> dfs_num;
vector<int> dfs_par;
vector<bool> failure_point_store;
int dfs_count;
int dfs_root;
int root_children;
int failure_points;

void failure_point(int u){
    dfs_num[u] = dfs_count;
    dfs_low[u] = dfs_count;
    dfs_count++;

    for(int i = 0; i < ADJ_LST[u].size();i++){
        int v = ADJ_LST[u][i];

        if(dfs_num[v] == UNVISITED){
            dfs_par[v] = u;
            if(u == dfs_root)
                root_children++;

            failure_point(v);

            if(dfs_low[v] >= dfs_num[u])
                failure_point_store[u] = true;
            dfs_low[u] = min(dfs_low[u],dfs_low[v]);
        }else if(v != dfs_par[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }

}



int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string N_str = "";
    while (getline(cin, N_str))
    {
        int N = stoi(N_str);
        if(N == 0)
            break;
        ADJ_LST = vector<vector<int>>(N, vector<int>());
        dfs_low = vector<int>(N, 0);
        dfs_par = vector<int>(N, 0);
        dfs_num = vector<int>(N,UNVISITED);
        failure_point_store = vector<bool>(N, false);
        dfs_count = 0;
        failure_points = 0;        


        while(N--){
            string V;
            getline(cin,V);
            stringstream ss(V);
            string node = "";
            ss>>node;
            int u = stoi(node);
            if(u == 0)
                break;
            u--;
            while(ss>>node){
                if(node[0] == ' ')
                    continue;
                int v = stoi(node)-1;
                ADJ_LST[u].push_back(v);
                ADJ_LST[v].push_back(u);
            } 
        }
        if(N==-1)
            getline(cin, N_str);

        for(int i = 0; i < ADJ_LST.size(); i++){
            if(dfs_num[i] == UNVISITED){
                dfs_root = i;
                root_children = 0;
                failure_point(i);
                if(root_children > 1)
                    failure_point_store[i] = true;
                else
                    failure_point_store[i] = false;

            }
        }
        for(int i = 0; i < failure_point_store.size(); i++){
            if(failure_point_store[i])
                failure_points++;
        }
        cout<<failure_points<<"\n";
    }
}
