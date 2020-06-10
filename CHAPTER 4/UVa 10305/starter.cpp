#include <bits/stdc++.h>
using namespace std;

list<int> s;

void dfs(vector<vector<int>> &ADJ_LST, vector<bool> &visited, int u)
{
    visited[u] = true;
    for (int i = 0; i < ADJ_LST[u].size(); i++)
    {
        int v = ADJ_LST[u][i];
        if(!visited[v])
            dfs(ADJ_LST, visited, v);
    }
    s.push_back(u);
    return;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    int n, m;
    while(cin>>n>>m && (n != 0 || m !=0)){
        vector<vector<int>> ADJ_LST(n, vector<int>());
        while(m--){
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            ADJ_LST[u].push_back(v);
        }
        s = list<int>();
        vector<bool> visited = vector<bool>(n, false);
        for(int i=0; i < ADJ_LST.size();i++){
            if(!visited[i]){
                dfs(ADJ_LST, visited, i);
            }
        }
        string str = "";
        int count = 0;
        while(!s.empty()){
            int u = s.back();
            s.pop_back();
            (count == 0)?(str = to_string(u+1)):(str += " "+to_string(u+1));
            count++;
        }
        cout<<str<<"\n";
    }


}