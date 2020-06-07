#include <bits/stdc++.h>
using namespace std;

int floodfill(vector<vector<char>> &cont, int y, int x, char land){
    cont[y][x] = '\0';
    int res = 0;
    if((x+1 < cont[y].size()) && cont[y][x+1] == land)
        res = floodfill(cont, y, x+1, land) + 1;
    if((x-1 > -1) && cont[y][x-1] == land)
        res += floodfill(cont, y, x-1, land) + 1;
    if((x+1 > cont[y].size()) && cont[y][0] == land)
        res += floodfill(cont, y, 0, land) + 1;
    if((x-1 < 0) && cont[y][cont[y].size()-1] == land)
        res += floodfill(cont, y, cont[y].size()-1, land) + 1;
    if((y+1) < cont.size() && cont[y+1][x] == land)
        res += floodfill(cont, y+1, x, land) + 1;
    if((y-1 > -1) && cont[y-1][x] == land)
        res += floodfill(cont, y-1, x, land) + 1;

    return res;

}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int M, N;

    while(cin>>M>>N){
        vector<vector<char>> cont(M, vector<char>(N, '\0'));

        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                char land;
                cin>>land;
                cont[i][j] = land;
            }
        }

        int kx, ky;
        cin>>kx>>ky;
        char land = cont[kx][ky];
        floodfill(cont, kx, ky,land);

        int max_res = 0;
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(cont[i][j] == land){
                    max_res = max(max_res, floodfill(cont,i,j, land)+1);
                }
            }
        }
        cout<<max_res<<"\n";
    }



}