#include <bits/stdc++.h>
using namespace std;

int UNVISITED = -1;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n;

    while(cin>>n && n != 0){
        vector<vector<int>> ADJ_LST = vector<vector<int>>(n,vector<int>());
        int l;
        cin>>l;
        
        while(l--){
            int u, v;
            cin>>u>>v;
            ADJ_LST[u].push_back(v);
            ADJ_LST[v].push_back(u);
        }
        queue<int> q;
        vector<int> color(n, UNVISITED);
        q.push(0);
        color[0] = 0;
        bool colorable = true;;
        while(!q.empty() && colorable){
            int u = q.front();
            q.pop();
            
            for(int i = 0; i < ADJ_LST[u].size() && colorable; i++){
                int v = ADJ_LST[u][i];
                if(color[v] == UNVISITED){
                    color[v] = 1- color[u];
                    q.push(v);
                }else if(color[v] == color[u]){
                    colorable = false;
                }
            }

        }
        if(colorable)
            cout<<"BICOLORABLE.\n";
        else
            cout<<"NOT BICOLORABLE.\n";
        
    }
}