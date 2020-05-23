#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int k;
    bool count = false;

    while(cin>>k && k !=0){
        vector<int> nums;
        while(k--){
            int num;
            cin>>num;
            nums.push_back(num);
        }
        
        if(count)
            cout<<"\n";
        else
            count = true;

        for(int i = 0; i < nums.size();i++){
            for(int j = i+1; j < nums.size();j++){
                for(int k = j+1; k < nums.size();k++){
                    for(int l = k+1; l<nums.size(); l++){
                        for(int m = l+1; m<nums.size();m++){
                            for(int n = m+1; n< nums.size();n++){
                                cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<" "<<nums[l]<<" "<<nums[m]<<" "<<nums[n]<<"\n";
                            }
                        }
                    }
                }
            }
        }
        
    }
}