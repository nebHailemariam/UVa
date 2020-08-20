#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> ADJ_MAT = vector<vector<bool>>(1001, vector<bool>(1001, true));
int R, C;
void BFS(pair<int, int> s, pair<int, int> d, vector<vector<bool>> &ADJ_MAT)
{
    queue<pair<pair<int, int>, int>> q;
    q.push(pair<pair<int, int>, int>(pair<int, int>(s.first, s.second), 0));
    int steps = INT_MAX;
    ADJ_MAT[s.first][s.second] = false;

    while (!q.empty())
    {
        pair<pair<int, int>, int> front = q.front();
        q.pop();
        if (front.first.first == d.first && front.first.second == d.second)
        {
            steps = min(steps, front.second);
        }

        if (front.first.first + 1 < R && ADJ_MAT[front.first.first + 1][front.first.second])
        {
            q.push(pair<pair<int, int>, int>(pair<int, int>(front.first.first + 1, front.first.second), front.second + 1));
            ADJ_MAT[front.first.first + 1][front.first.second] = false;
        }

        if (front.first.second + 1 < C && ADJ_MAT[front.first.first][front.first.second + 1])
        {
            q.push(pair<pair<int, int>, int>(pair<int, int>(front.first.first, front.first.second + 1), front.second + 1));
            ADJ_MAT[front.first.first][front.first.second + 1] = false;
        }

        if (front.first.first - 1 > -1 && ADJ_MAT[front.first.first - 1][front.first.second])
        {
            q.push(pair<pair<int, int>, int>(pair<int, int>(front.first.first - 1, front.first.second), front.second + 1));
            ADJ_MAT[front.first.first - 1][front.first.second] = false;
        }

        if (front.first.second - 1 > -1 && ADJ_MAT[front.first.first][front.first.second - 1])
        {
            q.push(pair<pair<int, int>, int>(pair<int, int>(front.first.first, front.first.second - 1), front.second + 1));
            ADJ_MAT[front.first.first][front.first.second - 1] = false;
        }
    }
    cout << steps << "\n";
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    R, C;

    while (cin >> R >> C && (R != 0 || C != 0))
    {
        int t;
        cin >> t;
        ADJ_MAT = vector<vector<bool>>(R, vector<bool>(C, true));
        while (t--)
        {
            int r;
            cin >> r;
            int n;
            cin >> n;
            while (n--)
            {
                int c;
                cin >> c;
                ADJ_MAT[r][c] = false;
            }
        }
        pair<int, int> s;
        pair<int, int> d;
        cin >> s.first >> s.second >> d.first >> d.second;
        BFS(s, d, ADJ_MAT);
    }
}