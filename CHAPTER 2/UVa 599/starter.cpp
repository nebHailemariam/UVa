#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
private:
    vector<int> p, rank, setSize;

public:
    UnionFind()
    {
        int N = 26;
        setSize = vector<int>(N, 1);
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++)
            p[i] = i;
    }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j)
    {
        if (!isSameSet(i, j))
        {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y])
            {
                p[y] = x;
                setSize[x] += setSize[y];
            }
            else
            {
                p[x] = y;
                setSize[y] += setSize[x];
                if (rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }
    void treesAcron(string &proc)
    {
        int tree = 0;
        unordered_map<int, bool> dict;

        for (int i = 0; i < 26; i++)
        {
            if (findSet(i) == i && setSize[i] > 1)
            {
                tree++;
            }
        }
        int acron = 0;
        for (int i = 0; i < proc.length(); i += 2)
        {

            if ((findSet(((int)proc[i]) - 65) == (((int)proc[i]) - 65)) && setSize[(int)proc[i] - 65] == 1)
            {
                acron++;
            }
        }
        cout << "There are " << tree << " tree(s) and " << acron << " acorn(s).\n";
    }
};

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    string store = "";
    int count = 0;
    getline(cin, store);
    count = stoi(store);
    while (count--)
    {
        UnionFind un = UnionFind();
        while (getline(cin, store) && store[0] != '*')
        {
            un.unionSet(((int)store[1]) - 65, ((int)store[3]) - 65);
        }
        getline(cin, store);
        un.treesAcron(store);
    }

    return 0;
}