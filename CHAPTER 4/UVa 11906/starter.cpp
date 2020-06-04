#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int test_cases = 0;
    int cases = 1;
    cin>>test_cases;
    while(test_cases--){
        int R, C, M, N, W;
        cin>>R>>C>>M>>N;
        cin>>W;

        vector<vector<char>> grid(R, vector<char>(C,'.'));

        
        while(W--){
            int x,y;
            cin>>x>>y;
            grid[x][y] = '#';
        }
        queue<pair<int,int>> q;
        q.push(pair<int,int>(0,0));
        int even = 0, odd = 0;
        while(!q.empty()){
            pair<int,int> pos = q.front();
            q.pop();
            if(grid[pos.first][pos.second] == '*')
                continue;
            map<pair<int,int>,int> visited;
            grid[pos.first][pos.second] = '*';
            int count = 0;
            if(pos.first + M < R && pos.second + N < C && grid[pos.first + M][pos.second + N] != '#'){
                if(!visited[pair<int,int>(pos.first + M,pos.second + N)]){
                    q.push(pair<int,int>(pos.first + M, pos.second + N));
                    count++;
                    visited[pair<int,int>(pos.first + M,pos.second + N)] = true;
            }
            }
            if(pos.first + M < R && pos.second - N > -1 && grid[pos.first + M][pos.second - N] != '#'){
                 if(!visited[pair<int,int>(pos.first + M,pos.second - N)]){
                    q.push(pair<int,int>(pos.first + M, pos.second - N));
                    count++;
                    visited[pair<int,int>(pos.first + M,pos.second - N)] = true;
                 }

            
            }
            if(pos.first - M > -1 && pos.second + N < C && grid[pos.first - M][pos.second + N] != '#'){
                 if(!visited[pair<int,int>(pos.first - M,pos.second + N)]){
                    q.push(pair<int,int>(pos.first - M, pos.second + N));
                    visited[pair<int,int>(pos.first - M,pos.second + N)] = true;
                    count++;
                 }

            
            }
            if(pos.first - M > -1 && pos.second - N > -1 && grid[pos.first - M][pos.second - N] != '#'){
                
                if(!visited[pair<int,int>(pos.first - M,pos.second - N)]){
                    q.push(pair<int,int>(pos.first - M, pos.second - N));
                    count++;
                    visited[pair<int,int>(pos.first - M,pos.second - N)] = true;
                
            }
            }
            if(pos.first + N < R && pos.second + M < C && grid[pos.first + N][pos.second + M] != '#'){
                if(!visited[pair<int,int>(pos.first + N,pos.second + M)]){
                    q.push(pair<int,int>(pos.first + N, pos.second + M));
                    count++;
                    visited[pair<int,int>(pos.first + N,pos.second + M)] = true;
                
            }
            }
            if(pos.first + N < R && pos.second - M > -1 && grid[pos.first + N][pos.second - M] != '#'){
                if(!visited[pair<int,int>(pos.first + N,pos.second - M)]){
                    q.push(pair<int,int>(pos.first + N, pos.second - M));
                    count++;
                    visited[pair<int,int>(pos.first + N,pos.second - M)] = true;
                    }
                
            }
            if(pos.first - N > -1 && pos.second - M > -1 && grid[pos.first - N][pos.second - M] != '#'){
                if(!visited[pair<int,int>(pos.first - N,pos.second - M)]){
                    count++;
                    q.push(pair<int,int>(pos.first - N, pos.second - M));
                    visited[pair<int,int>(pos.first - N,pos.second - M)] = true;
                
            }
            }
            if(pos.first - N > -1 && pos.second + M < C && grid[pos.first - N][pos.second + M] != '#'){
                if(!visited[pair<int,int>(pos.first - N,pos.second + M)]){
                    q.push(pair<int,int>(pos.first - N, pos.second + M));
                    count++;
                    visited[pair<int,int>(pos.first - N,pos.second + M)] = true;
                }
            }
            (count%2 == 0)?(even++):(odd++);
        }
        cout<<"Case "<<cases++<<": "<<even<<" "<<odd<<"\n";
        
    }
}