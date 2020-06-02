#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    string store = "";
    int N,M,S;

    while(cin>>N>>M>>S){
        if(N == 0 && M == 0 && S==0)
            break;
        vector<vector<char>> field(N, vector<char>(M, '.'));
        int x,y;
        for(int i = 0; i < N;i++){
            for(int j = 0; j < M;j++){
                char cell;
                cin>>cell;
                if(cell == 'N' || cell == 'S' || cell == 'L' || cell == 'O'){
                    x = i;
                    y = j;
                }
                field[i][j] = cell;
            }
        }
        int res = 0;
        while(S--){
            char dir;
            cin>>dir;
            if(field[x][y] == 'N' && dir == 'D'){
                field[x][y] = 'L';
            }else  if(field[x][y] == 'N' && dir == 'E'){
                field[x][y] = 'O';
            }else if(field[x][y] == 'N' && dir == 'F'){
                if(x-1 == -1 || field[x-1][y] == '#')
                    continue;
                else if(field[x-1][y] == '*')
                    res++;
                field[x][y] = '.';
                field[x-1][y] = 'N';
                x--;
            }
            else if(field[x][y] == 'S' && dir == 'D'){
                field[x][y] = 'O';
            }else  if(field[x][y] == 'S' && dir == 'E'){
                field[x][y] = 'L';
            }else if(field[x][y] == 'S' && dir == 'F'){
                if(x+1 == N || field[x+1][y] == '#')
                    continue;
                else if(field[x+1][y] == '*')
                    res++;
                field[x][y] = '.';
                field[x+1][y] = 'S';
                x++;
            }
            else if(field[x][y] == 'L' && dir == 'D'){
                field[x][y] = 'S';
            }else  if(field[x][y] == 'L' && dir == 'E'){
                field[x][y] = 'N';
            }else if(field[x][y] == 'L' && dir == 'F'){
                if(y+1 == M || field[x][y+1] == '#')
                    continue;
                else if(field[x][y+1] == '*')
                    res++;
                field[x][y] = '.';
                field[x][y+1] = 'L';
                y++;
            }
            else if(field[x][y] == 'O' && dir == 'D'){
                field[x][y] = 'N';
            }else  if(field[x][y] == 'O' && dir == 'E'){
                field[x][y] = 'S';
            }else if(field[x][y] == 'O' && dir == 'F'){
                if(y-1 == -1 || field[x][y-1] == '#')
                    continue;
                else if(field[x][y-1] == '*')
                    res++;
                field[x][y] = '.';
                field[x][y-1] = 'O';
                y--;
            }
        }
        cout<<res<<"\n";
    }
}