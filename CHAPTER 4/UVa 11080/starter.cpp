#include <bits/stdc++.h>
using namespace std;

int UNVISITED = -1;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int testcases;
    cin>>testcases;


    while(testcases--){
        int v, e;
        cin>>v>>e;
        vector<vector<int>> ADJ_LST = vector<vector<int>>(v,vector<int>());
        
        while(e--){
            int u, v;
            cin>>u>>v;
            ADJ_LST[u].push_back(v);
            ADJ_LST[v].push_back(u);
        }
        queue<int> q;
        vector<int> color(v, UNVISITED);
        bool colorable = true;
        int soliders = 0;

        for(int i = 0; i < color.size() && colorable; i++){
            if(color[i] == UNVISITED){
                q.push(i);
                color[i] = 0;
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
                int soldiers_on = 0, soldiers_off = 0;
                for(int i = 0; i < color.size();i++){
                    if(color[i] == UNVISITED)
                        continue;
                    else if(color[i] == 0)
                        soldiers_off++;
                    else if(color[i] == 1)
                        soldiers_on++;
                    color[i] = 2;
                }
                if(soldiers_on != 0 && soldiers_off != 0){
                    soliders += min(soldiers_on, soldiers_off);
                    
                }
                else{
                    soliders+= max(soldiers_off, soldiers_on);
                }
            }
        }
        

        if(colorable)
            cout<<soliders<<"\n";
        else
            cout<<"-1\n";
    }
}