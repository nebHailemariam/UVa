#include <bits/stdc++.h>
using namespace std;

int UNVISITED = -1;

int dfs(vector<vector<int>> &ADJ_LST, vector<int> &visited, vector<int> &G_visited, int u, int d){
    visited[u] = 1;
    d++;
    
    for(int i = 0; i < ADJ_LST[u].size();i++){
        int v = ADJ_LST[u][i];
        if(visited[v] == UNVISITED)
            d = max(d,dfs(ADJ_LST, visited, G_visited, v, d));
    }
    G_visited[u] = 1;
    visited[u] = -1;
    return d;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int tests, cases = 0;
    cin>>tests;

    while(tests--){
        int V;
        cin>>V;

        vector<vector<int>> ADJ_LST(V, vector<int>());
        vector<int> G_visited = vector<int>(V,UNVISITED);
        vector<int> visited = vector<int>(V,UNVISITED);

        while(V--){
            int u, v;
            cin>>u>>v;
            ADJ_LST[u-1].push_back(v-1);
        }

        int min_i = 0, max_depth = 0;
        int count = 0;
        for(int i = 0; i < ADJ_LST.size();i++){
            
            if(G_visited[i] == UNVISITED){
                
                int depth  = dfs(ADJ_LST, visited, G_visited, i, 0);
                if(max_depth < depth){
                    max_depth = depth;
                    min_i = i;
                }
            }
        }
        cout<<"Case "<<++cases<<": "<<min_i+1<<"\n";
            
    }
}