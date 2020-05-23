#include <bits/stdc++.h>
using namespace std;


class UnionFind
{
private:
    vector<int> p, rank, setSize;

public:
    UnionFind(int N)
    {
        setSize.assign(N, 1);
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++)
            p[i] = i;
    }
    int findSet(int i)
    {
        if (i == p[i])
            return i;
        p[i] = findSet(p[i]);
        return p[i];
    }
    bool isSameSet(int a, int b) { return findSet(a) == findSet(b); }
    void UnionSet(int a, int b)
    {
        if (!isSameSet(a, b))
        {
            int a_par = findSet(a);
            int b_par = findSet(b);
            if (rank[a_par] > rank[b_par])
            {
                p[b_par] = a_par;
                setSize[a_par] += setSize[b_par];
            }
            else
            {
                setSize[b_par] += setSize[a_par];
                p[a_par] = b_par;
                if (rank[a_par] == rank[b_par])
                {
                    rank[a_par]++;
                }
            }
        }
    }
    int setSizeCount(int i)
    {
        return setSize[findSet(i)];
    }
};

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int count = 0;
    cin >> count;
    while (count--)
    {
        int con;
        cin >> con;
        int i = 0;
        unordered_map<string, int> hash_peo;
        UnionFind un = UnionFind(100000);
        while (con--)
        {
            string p1, p2;
            cin >> p1 >> p2;
            if (hash_peo.count(p1) == 0)
            {
                hash_peo[p1] = i;
                i++;
            }
            if (hash_peo.count(p2) == 0)
            {
                hash_peo[p2] = i;
                i++;
            }

            int p1_id = hash_peo[p1];
            int p2_id = hash_peo[p2];
            un.UnionSet(p1_id, p2_id);
            cout << (un.setSizeCount(p1_id)) << "\n";
        }
    }
}