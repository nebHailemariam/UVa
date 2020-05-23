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
    int count = 0;
    cin>>count;
    while(count--){
        int m, n;
        int res = 0;
        char chesspiece;
        cin>>chesspiece;
        cin>>m;
        cin>>n;

        if(chesspiece == 'K' ){
            if(m%2 == 0 && n%2 == 0){
                res = (m*n)/4;
            }else if(m%2 == 0 && n%2 !=0){
                res = (m*(n+1))/4;
            }else if(m%2 != 0 && n%2 ==0){
                res = (n*(m+1))/4;
            }else{
                res = ((m+1)*(n+1))/4;
            }
        }else if(chesspiece == 'Q'){
            res = min(n,m);
        }
        else if(chesspiece == 'r'){
            res = min(n, m);
        }else if(chesspiece == 'k'){
            float temp = (n*m+1)/2 + 0.5;
            res = temp;
        }
        cout<<res<<"\n";
    }
}