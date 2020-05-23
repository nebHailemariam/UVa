#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int t = 0;
    int count = 0;
    cin >> t;
    while (t--)
    {
        int row, col, n;
        cin >> row;
        cin >> col;
        cin >> n;
        vector<vector<char>> board(row, vector<char>(col));
        vector<vector<char>> store(row, vector<char>(col));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                char temp;
                cin >> temp;
                board[i][j] = temp;
                store[i][j] = temp;
            }
        }
        if (count != 0)
        {
            cout << "\n";
        }
        count++;
        while (n--)
        {
            for (int i = 0; i < board.size(); i++)
            {
                for (int j = 0; j < board[i].size(); j++)
                {
                    if (j + 1 < col && board[i][j] == 'R' && board[i][j + 1] == 'S')
                    {
                        store[i][j + 1] = 'R';
                    }
                    if (j + 1 < col && board[i][j] == 'S' && board[i][j + 1] == 'R')
                    {
                        store[i][j] = 'R';
                    }
                    if (i + 1 < board.size() && board[i][j] == 'R' && board[i + 1][j] == 'S')
                    {
                        store[i + 1][j] = 'R';
                    }
                    if (i + 1 < board.size() && board[i][j] == 'S' && board[i + 1][j] == 'R')
                    {
                        store[i][j] = 'R';
                    }

                    if (j + 1 < board[i].size() && board[i][j] == 'S' && board[i][j + 1] == 'P')
                    {
                        store[i][j + 1] = 'S';
                    }
                    if (j + 1 < board[i].size() && board[i][j] == 'P' && board[i][j + 1] == 'S')
                    {
                        store[i][j] = 'S';
                    }
                    if (i + 1 < board.size() && board[i][j] == 'S' && board[i + 1][j] == 'P')
                    {
                        store[i + 1][j] = 'S';
                    }
                    if (i + 1 < board.size() && board[i][j] == 'P' && board[i + 1][j] == 'S')
                    {
                        store[i][j] = 'S';
                    }

                    if (i + 1 < board.size() && board[i][j] == 'R' && board[i + 1][j] == 'P')
                    {
                        store[i][j] = 'P';
                    }
                    if (i + 1 < board.size() && board[i][j] == 'P' && board[i + 1][j] == 'R')
                    {
                        store[i + 1][j] = 'P';
                    }
                    if (j + 1 < board[i].size() && board[i][j] == 'P' && board[i][j + 1] == 'R')
                    {
                        store[i][j + 1] = 'P';
                    }
                    if (j + 1 < board[i].size() && board[i][j + 1] == 'P' && board[i][j] == 'R')
                    {
                        store[i][j] = 'P';
                    }
                }
            }
            board = store;
        }

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                cout << store[i][j];
            }
            cout << "\n";
        }
    }
}