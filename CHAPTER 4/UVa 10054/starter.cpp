#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, bool>>> ADJ_LST;


void dfs(int u, vector<int> &s) {

    for (int i = 0; i < ADJ_LST[u].size(); i++) {
        pair<int, bool> v = ADJ_LST[u][i];
        if (v.second) {
            ADJ_LST[u][i].second = false;

            for (int j = 0; j < ADJ_LST[v.first].size(); j++) {
                if (ADJ_LST[v.first][j].first == u && ADJ_LST[v.first][j].second) {
                    ADJ_LST[v.first][j].second = false;
                    break;
                }
            }
            dfs(v.first, s);
            s.push_back(u);
        }
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int test_cases, cases=0;
    cin>>test_cases;

    while (test_cases--) {
        int beads;
        cin>>beads;
        ADJ_LST =  vector<vector<pair<int, bool>>>(1000, vector<pair<int, bool>>());
        while (beads--) {
            int u, v;
            cin>>u>>v;
            u--;
            v--;

            ADJ_LST[u].push_back(pair<int, bool>(v, true));
            ADJ_LST[v].push_back(pair<int, bool>(u, true));

        }
        bool is = true;
        for (int i = 0; i < ADJ_LST.size(); i++) {
            if (ADJ_LST[i].size() & 1 != 0) {
                is = false;
                break;
            }
        }
        if (!is) {
            cout<<"Case #"<<++cases<<"\n";
            cout<<"some beads may be lost\n";
        }
        else {
            int i;
            for (i = 0; i < ADJ_LST.size(); i++) {
                if (ADJ_LST[i].size())break;
            }
            vector<int> s;
            s.push_back(i);
            dfs(i, s);
            cout<<"Case #"<<++cases<<"\n";
            bool is = true;
            for (;i<s.size() && is;i++)
                for (int j = 0; j < ADJ_LST[i].size() && is; j++)
                    if (ADJ_LST[i][j].second)
                        is=false;

            if (!is)
                cout<<"some beads may be lost\n";
            else
                for (int b = 0; b < s.size()-1;b++)
                    cout<<s[b]+1<<" "<<s[b+1]+1<<"\n";

        }
        if (test_cases != 0)
            cout<<"\n";
    }
}