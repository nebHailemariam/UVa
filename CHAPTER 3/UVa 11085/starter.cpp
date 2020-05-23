#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> precal;
int abs(int x)
{
    return (x < 0) ? -x : x;
}
bool check(vector<int> &board, int index)
{
    for (int i = 0; i < index; i++)
    {

        if (board[i] == board[index] || abs(board[i] - board[index]) == abs(i - index))
            return false;
    }
    return true;
}

void recurse(vector<int> board, int index)
{

    if (index == board.size())
    {
        if (check(board, index - 1))
        {
            precal.push_back(board);
        }
        return;
    }
    else
    {
        for (int i = 0; i < board.size(); i++)
        {
            board[index] = i + 1;
            if (check(board, index))
                recurse(board, index + 1);
        }
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int input;
    int cases = 1;
    recurse(vector<int>({0, 0, 0, 0, 0, 0, 0, 0}), 0);
    while (cin >> input)
    {
        int count = 0;
        vector<int> pos;
        pos.push_back(input);
        while (count < 7)
        {
            cin >> input;
            pos.push_back(input);
            count++;
        }

        int diff = INT_MAX;
        for (int i = 0; i < precal.size(); i++)
        {
            int temp = 0;
            for (int j = 0; j, j < precal[i].size(); j++)
            {
                if (precal[i][j] - pos[j])
                    temp += 1;
            }
            diff = min(temp, diff);
        }

        cout << "Case " << cases << ": " << diff << "\n";

        cases++;
    }
}