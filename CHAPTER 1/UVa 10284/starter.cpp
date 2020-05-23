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

    while (getline(cin, store))
    {
        vector<vector<char>> board(8, vector<char>(8, '*'));

        int ptr = 0;
        for (int p_i = 0; p_i < 8; p_i++)
        {
            for (int p_j = 0; p_j < 8; p_j++)
            {
                if (isdigit(store[ptr]))
                {
                    int temp_j = (p_j + (((int)store[ptr]) - 48));
                    ptr++;
                    if (temp_j < 8)
                    {
                        board[p_i][temp_j] = store[ptr];
                        ptr++;
                    }
                    p_j = temp_j;
                }
                else if (store[ptr] == '/')
                {
                    ptr++;
                    p_j--;
                }
                else
                {
                    board[p_i][p_j] = store[ptr];
                    ptr++;
                }
            }
        }
        vector<vector<char>> check_board = board;
        // for (int i = 0; i < board.size(); i++)
        // {
        //     for (int j = 0; j < board[0].size(); j++)
        //     {
        //         cout << board[i][j];
        //     }
        //     cout << endl;
        // }

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {

                if (board[i][j] == 'p')
                {
                    if (i + 1 < 8 && j - 1 > -1 && board[i + 1][j - 1] == '*')
                    {
                        check_board[i + 1][j - 1] = 'O';
                    }
                    if (i + 1 < 8 && j + 1 < 8 && board[i + 1][j + 1] == '*')
                    {
                        check_board[i + 1][j + 1] = 'O';
                    }
                }
                else if (board[i][j] == 'P')
                {
                    if (i - 1 > -1 && j - 1 > -1 && board[i - 1][j - 1] == '*')
                    {
                        check_board[i - 1][j - 1] = 'O';
                    }
                    if (i - 1 > -1 && j + 1 < 8 && board[i - 1][j + 1] == '*')
                    {
                        check_board[i - 1][j + 1] = 'O';
                    }
                }
                else if (board[i][j] == 'n' || board[i][j] == 'N')
                {

                    if (i + 2 < 8 && j - 1 > -1 && board[i + 2][j - 1] == '*')
                    {
                        check_board[i + 2][j - 1] = 'O';
                    }
                    if (i + 2 < 8 && j + 1 < 8 && board[i + 2][j + 1] == '*')
                    {
                        check_board[i + 2][j + 1] = 'O';
                    }
                    if (i - 2 > -1 && j - 1 > -1 && board[i - 2][j - 1] == '*')
                    {
                        check_board[i - 2][j - 1] = 'O';
                    }
                    if (i - 2 > -1 && j + 1 < 8 && board[i - 2][j + 1] == '*')
                    {
                        check_board[i - 2][j + 1] = 'O';
                    }
                    if (i - 1 > -1 && j + 2 < 8 && board[i - 1][j + 2] == '*')
                    {
                        check_board[i - 1][j + 2] = 'O';
                    }
                    if (i - 1 > -1 && j - 2 > -1 && board[i - 1][j - 2] == '*')
                    {
                        check_board[i - 1][j - 2] = 'O';
                    }
                    if (i + 1 < 8 && j + 2 < 8 && board[i + 1][j + 2] == '*')
                    {
                        check_board[i + 1][j + 2] = 'O';
                    }
                    if (i + 1 < 8 && j - 2 > -1 && board[i + 1][j - 2] == '*')
                    {
                        check_board[i + 1][j - 2] = 'O';
                    }
                }
                else if (board[i][j] == 'r' || board[i][j] == 'R')
                {
                    for (int ptr_i = i - 1; ptr_i > -1 && board[ptr_i][j] == '*'; ptr_i--)
                    {
                        check_board[ptr_i][j] = 'O';
                    }
                    for (int ptr_i = i + 1; ptr_i < 8 && board[ptr_i][j] == '*'; ptr_i++)
                    {
                        check_board[ptr_i][j] = 'O';
                    }
                    for (int ptr_j = j - 1; ptr_j > -1 && board[i][ptr_j] == '*'; ptr_j--)
                    {
                        check_board[i][ptr_j] = 'O';
                    }
                    for (int ptr_j = j + 1; ptr_j < 8 && board[i][ptr_j] == '*'; ptr_j++)
                    {
                        check_board[i][ptr_j] = 'O';
                    }
                }
                else if (board[i][j] == 'q' || board[i][j] == 'Q')
                {
                    for (int ptr_i = i - 1; ptr_i > -1 && board[ptr_i][j] == '*'; ptr_i--)
                    {
                        check_board[ptr_i][j] = 'O';
                    }
                    for (int ptr_i = i + 1; ptr_i < 8 && board[ptr_i][j] == '*'; ptr_i++)
                    {
                        check_board[ptr_i][j] = 'O';
                    }
                    for (int ptr_j = j - 1; ptr_j > -1 && board[i][ptr_j] == '*'; ptr_j--)
                    {
                        check_board[i][ptr_j] = 'O';
                    }
                    for (int ptr_j = j + 1; ptr_j < 8 && board[i][ptr_j] == '*'; ptr_j++)
                    {
                        check_board[i][ptr_j] = 'O';
                    }
                    int ptr_j = j + 1;
                    int ptr_i = i + 1;
                    for (ptr_j, ptr_i; ptr_j < 8 && ptr_i < 8 && board[ptr_i][ptr_j] == '*'; ptr_j++, ptr_i++)
                    {
                        check_board[ptr_i][ptr_j] = 'O';
                    }
                    ptr_j = j - 1;
                    ptr_i = i - 1;
                    for (ptr_j, ptr_i; ptr_j > -1 && ptr_i > -1 && board[ptr_i][ptr_j] == '*'; ptr_j--, ptr_i--)
                    {
                        check_board[ptr_i][ptr_j] = 'O';
                    }
                    ptr_j = j - 1;
                    ptr_i = i + 1;
                    for (ptr_j, ptr_i; ptr_j > -1 && ptr_i < 8 && board[ptr_i][ptr_j] == '*'; ptr_j--, ptr_i++)
                    {
                        check_board[ptr_i][ptr_j] = 'O';
                    }
                    ptr_j = j + 1;
                    ptr_i = i - 1;
                    for (ptr_j, ptr_i; ptr_j < 8 && ptr_i > -1 && board[ptr_i][ptr_j] == '*'; ptr_j++, ptr_i--)
                    {
                        check_board[ptr_i][ptr_j] = 'O';
                    }
                }
                else if (board[i][j] == 'b' || board[i][j] == 'B')
                {
                    int ptr_j = j + 1;
                    int ptr_i = i + 1;
                    for (ptr_j, ptr_i; ptr_j < 8 && ptr_i < 8 && board[ptr_i][ptr_j] == '*'; ptr_j++, ptr_i++)
                    {
                        check_board[ptr_i][ptr_j] = 'O';
                    }
                    ptr_j = j - 1;
                    ptr_i = i - 1;
                    for (ptr_j, ptr_i; ptr_j > -1 && ptr_i > -1 && board[ptr_i][ptr_j] == '*'; ptr_j--, ptr_i--)
                    {
                        check_board[ptr_i][ptr_j] = 'O';
                    }
                    ptr_j = j - 1;
                    ptr_i = i + 1;
                    for (ptr_j, ptr_i; ptr_j > -1 && ptr_i < 8 && board[ptr_i][ptr_j] == '*'; ptr_j--, ptr_i++)
                    {
                        check_board[ptr_i][ptr_j] = 'O';
                    }
                    ptr_j = j + 1;
                    ptr_i = i - 1;
                    for (ptr_j, ptr_i; ptr_j < 8 && ptr_i > -1 && board[ptr_i][ptr_j] == '*'; ptr_j++, ptr_i--)
                    {
                        check_board[ptr_i][ptr_j] = 'O';
                    }
                }
                else if (board[i][j] == 'k' || board[i][j] == 'K')
                {
                    if (i + 1 < 8 && board[i + 1][j] == '*')
                    {
                        check_board[i + 1][j] = 'O';
                    }
                    if (i - 1 > -1 && board[i - 1][j] == '*')
                    {
                        check_board[i - 1][j] = 'O';
                    }
                    if (j + 1 < 8 && board[i][j + 1] == '*')
                    {
                        check_board[i][j + 1] = 'O';
                    }
                    if ((j - 1 > -1 && board[i][j - 1] == '*'))
                    {
                        check_board[i][j - 1] = 'O';
                    }
                    if (j + 1 < 8 && i + 1 < 8 && board[i + 1][j + 1] == '*')
                    {
                        check_board[i + 1][j + 1] = 'O';
                    }
                    if (j - 1 > -1 && i + 1 < 8 && board[i + 1][j - 1] == '*')
                    {
                        check_board[i + 1][j - 1] = 'O';
                    }
                    if (j + 1 < 8 && i - 1 > -1 && board[i - 1][j + 1] == '*')
                    {
                        check_board[i - 1][j + 1] = 'O';
                    }
                    if (j - 1 > -1 && i - 1 > -1 && board[i - 1][j - 1] == '*')
                    {
                        check_board[i - 1][j - 1] = 'O';
                    }
                }
            }
        }

        int star = 0;
        // cout << endl;
        for (int i = 0; i < check_board.size(); i++)
        {
            for (int j = 0; j < check_board[0].size(); j++)
            {
                if (check_board[i][j] == '*')
                {
                    star++;
                }
                // cout << check_board[i][j];
            }
            // cout << endl;
        }
        cout << star << "\n";
    }
}
