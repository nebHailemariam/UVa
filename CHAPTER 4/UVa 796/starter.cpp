#include <bits/stdc++.h>
using namespace std;

int UNVISITED = -1;
vector<vector<int>> ADJ_LST;
int root;
int root_children;
int dfs_count;
vector<int> num; 
vector<int> low;// stores the lowest dfsnum reachable from the currne DFS spanning subtree of u.
vector<int> par;
vector<pair<int,int>> critical_links;

bool comp(pair<int,int> a, pair<int,int> b){
    if(a.first < b.first)
        return true;
    if(a.first > b.first)
        return false;
    return (a.second < b.second)?true: false;
}


void articulationPoint(int u){
    num[u] = dfs_count;
    low[u] = dfs_count;
    dfs_count++;

    for(int i = 0; i < ADJ_LST[u].size();i++){
        int v = ADJ_LST[u][i];

        if(num[v] == UNVISITED){
            par[v] = u;
            if(u == root)
                root_children++;

            articulationPoint(v);

            if(low[v] > num[u])
                (u<v)?critical_links.push_back(pair<int,int>(u,v)):critical_links.push_back(pair<int,int>(v, u));

            low[u] = min(low[u],low[v]);
        }else if(v != par[u])
            low[u] = min(low[u], num[v]);
    }

}


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n;
    
    while(cin>>n){
        ADJ_LST = vector<vector<int>>(n, vector<int>());
        while(n--){
            int u, num_of_v;
            char braces;
            cin>>u;
            cin>>braces>>num_of_v>>braces;

            while(num_of_v--){
                int v;
                cin>>v;
                ADJ_LST[u].push_back(v);
            }
        }
        num = vector<int>(ADJ_LST.size(), UNVISITED);
        low = vector<int>(ADJ_LST.size(), 0);
        par = vector<int>(ADJ_LST.size(),0);
        critical_links = vector<pair<int,int>>();
        for(int i = 0;i < ADJ_LST.size();i++){
            if(num[i] == UNVISITED){
                root = i;
                root_children = 0;
                articulationPoint(i);
            }
        }
        sort(critical_links.begin(), critical_links.end(), comp);
        cout<<critical_links.size()<<" critical links"<<"\n";

        for(int i = 0; i < critical_links.size(); i++){
            cout<<critical_links[i].first<<" - "<<critical_links[i].second<<"\n";
        }cout<<"\n";
      }
}