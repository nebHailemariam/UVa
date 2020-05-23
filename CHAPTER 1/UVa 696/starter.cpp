#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int row, col;
    
    while(true){
        cin>>row;
        cin>>col;
        if(row == 0 && col == 0)break;
        int res = 0;
        int temp = 0;
        if(row == 0 || col == 0){
            cout<<0<<" knights may be placed on a "<<row<<" row "<<col<<" column board.";
        }
        else if (col == 1 || row == 1){
            cout<<max(col,row)<<" knights may be placed on a "<<row<<" row "<<col<<" column board.";
        }else if(col == 2 || row  == 2){
            int res = max(col,row);
            if(res%4 == 0)res = res;
            else if(res%4 == 1)res++;
            else res = res-(res%4) + 4;
            cout<<res<<" knights may be placed on a "<<row<<" row "<<col<<" column board.";
        }else{
            float temp = (col*row+1)/2 + 0.5;
            int res = temp;
            cout<<res<<" knights may be placed on a "<<row<<" row "<<col<<" column board.";
        }
        cout<<"\n";
    }
}
