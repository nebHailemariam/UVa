#include <bits/stdc++.h>
using namespace std;


vector<vector<char>> rotate(vector<vector<char>> sqr_mat, int sqr)
{
    for (int i = 0; i < sqr / 2; i++)
    {
        for (int j = i; j < sqr - 1 - i; j++)
        {
            char hold = sqr_mat[i][j];
            sqr_mat[i][j] = sqr_mat[j][sqr - 1 - i];
            sqr_mat[j][sqr - 1 - i] = sqr_mat[sqr - 1 - i][sqr - 1 - j];
            sqr_mat[sqr - 1 - i][sqr - 1 - j] = sqr_mat[sqr - 1 - j][i];
            sqr_mat[sqr - 1 - j][i] = hold;
        }
    }
    return sqr_mat;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int sqr_1, sqr_2;
    cin >> sqr_1 >> sqr_2;
    while (sqr_1 != 0 && sqr_2 != 0)
    {
        vector<vector<char>> sqr_1_mat;
        int sqr_1_copy = sqr_1;
        while (sqr_1_copy--)
        {
            int row = sqr_1;
            vector<char> row_mat;
            while (row--)
            {
                char val;
                cin >> val;
                row_mat.push_back(val);
            }
            row = sqr_1;
            sqr_1_mat.push_back(row_mat);
        }
        vector<vector<char>> sqr_2_mat;
        int sqr_2_copy = sqr_2;
        while (sqr_2_copy--)
        {
            int row = sqr_2;
            vector<char> row_mat;
            while (row--)
            {
                char val;
                cin >> val;
                row_mat.push_back(val);
            }
            row = sqr_2;
            sqr_2_mat.push_back(row_mat);
        }

        int degree_0 = 0;
        for (int a = 0; a < sqr_1; a++)
        {
            for (int b = 0; b < sqr_1; b++)
            {
                bool is_true = true;

                if (sqr_2 + a > sqr_1)
                    continue;
                if (sqr_2 + b > sqr_1)
                    continue;

                for (int i = 0; i < sqr_2; i++)
                {
                    for (int j = 0; j < sqr_2; j++)
                    {
                        if (sqr_2_mat[i][j] != sqr_1_mat[a + i][b + j])
                        {
                            is_true = false;
                            break;
                        }
                    }
                }
                if(is_true)
                    degree_0 += 1;
            }
        }

        int degree_90 = 0;
        sqr_2_mat = rotate(sqr_2_mat, sqr_2_mat.size());
        for (int a = 0; a < sqr_1; a++)
        {
            for (int b = 0; b < sqr_1; b++)
            {
                bool is_true = true;

                if (sqr_2 + a > sqr_1)
                    continue;
                if (sqr_2 + b > sqr_1)
                    continue;

                for (int i = 0; i < sqr_2; i++)
                {
                    for (int j = 0; j < sqr_2; j++)
                    {
                        if (sqr_2_mat[i][j] != sqr_1_mat[a + i][b + j])
                        {
                            is_true = false;
                            break;
                        }
                    }
                }
                if(is_true)
                    degree_90 += 1;
                
            }
        }

        int degree_180 = 0;
        sqr_2_mat = rotate(sqr_2_mat, sqr_2_mat.size());
        for (int a = 0; a < sqr_1; a++)
        {
            for (int b = 0; b < sqr_1; b++)
            {
                bool is_true = true;

                if (sqr_2 + a > sqr_1)
                    continue;
                if (sqr_2 + b > sqr_1)
                    continue;

                for (int i = 0; i < sqr_2; i++)
                {
                    for (int j = 0; j < sqr_2; j++)
                    {
                        if (sqr_2_mat[i][j] != sqr_1_mat[a + i][b + j])
                        {
                            is_true = false;
                            break;
                        }
                    }
                }
                if(is_true)
                    degree_180 +=1;
            }
        }

        int degree_270 = 0;
        sqr_2_mat = rotate(sqr_2_mat, sqr_2_mat.size());
        for (int a = 0; a < sqr_1; a++)
        {
            for (int b = 0; b < sqr_1; b++)
            {
                bool is_true = true;

                if (sqr_2 + a > sqr_1)
                    continue;
                if (sqr_2 + b > sqr_1)
                    continue;

                for (int i = 0; i < sqr_2; i++)
                {
                    for (int j = 0; j < sqr_2; j++)
                    {
                        if (sqr_2_mat[i][j] != sqr_1_mat[a + i][b + j])
                        {
                            is_true = false;
                            break;
                        }
                    }
                }
                if(is_true)
                degree_270 +=1;
            }
        }

            cout<<degree_0<<" "<<degree_270<<" "<<degree_180<<" "<<degree_90<<"\n";

        cin >> sqr_1 >> sqr_2;
    }
}