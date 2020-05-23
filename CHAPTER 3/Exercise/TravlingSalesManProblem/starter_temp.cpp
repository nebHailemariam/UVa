#include <bits/stdc++.h>
using namespace std;


int tsp(int mask, int pos,vector<vector<int>> &ADJ_MAT, vector<vector<int>> &DP_TABLE){
    
    if(mask == (1<<ADJ_MAT.size())-1)
        return ADJ_MAT[pos][0];
    
    if(DP_TABLE[mask][pos]!=-1)
    return DP_TABLE[mask][pos];

    int ans = INT_MAX;

    for(int i = 0; i < ADJ_MAT.size();i++){
        if(i != pos && ((1<<i) & mask) == 0){
            ans = min(ADJ_MAT[pos][i] + tsp(mask|1<<i, i, ADJ_MAT,DP_TABLE),ans);
        }
    }
    DP_TABLE[mask][pos]= ans;
    return DP_TABLE[mask][pos];
}


int main(){
    freopen("in.txt","r", stdin);
    freopen("out.txt", "w",stdout);
    int size_G;
    cin>>size_G;
    vector<vector<int>> ADJ_MAT=vector<vector<int>>(size_G, vector<int>(size_G,0));
        vector<vector<int>> DP_TABLE=vector<vector<int>>(1<<size_G, vector<int>(size_G,-1));
    for(int i=0; i<size_G; i++){
        for(int j = 0; j < size_G; j++){
            int temp;
            cin>>temp;
            ADJ_MAT[i][j] = temp;
        }
    }
    for(int i=0; i<size_G; i++){
        for(int j = 0; j < size_G; j++){
            cout<<ADJ_MAT[i][j]<<" ";
        }cout<<"\n";
    }
    cout<<"\n";

    int pos = 0;
    int mask = 1;
    cout<<"The minimum cost of all Hamiltonian cycles in the graph is "<<tsp(mask, pos,ADJ_MAT, DP_TABLE);


}