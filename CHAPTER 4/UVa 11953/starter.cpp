#include <bits/stdc++.h>
using namespace std;

void floodfill(vector<vector<char>> &grid, int y, int x){
    grid[y][x] = '.';
    if((x+1 < grid[y].size()) && (grid[y][x+1] == 'x' || grid[y][x+1] == '@'))
        floodfill(grid, y, x+1);
    if((x-1 > -1) && (grid[y][x-1] == 'x' || grid[y][x-1] == '@'))
        floodfill(grid, y, x-1);
    if((y+1) < grid.size() && (grid[y+1][x] == 'x' || grid[y+1][x] == '@'))
        floodfill(grid, y+1, x);
    if((y-1 > -1) && (grid[y-1][x] == 'x' || grid[y-1][x] == '@'))
        floodfill(grid, y-1, x);
    return;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int tests, cases = 1;
    cin>>tests;

    while(tests--){
        int N;
        cin>>N;
        vector<vector<char>> grid(N, vector<char>(N, '.'));
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                char square;
                cin>>square;
                grid[i][j] = square;
            }
        }
        int res = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(grid[i][j] == 'x'){
                    res++;
                    floodfill(grid, i, j);
                }
            }
        }
        cout<<"Case "<<cases++<<": "<<res<<"\n";
    }


}