#include <bits/stdc++.h>
using namespace std;


class UnionFind
{
private:
    vector<int> p, rank;

public:
    UnionFind(int comp)
    {
        p = vector<int>(comp);
        for (int i = 0; i < comp; i++)
            p[i] = i;
        rank = vector<int>(comp, 0);
    }
    int find(int a)
    {
        if (p[a] == a)
            return a;
        p[a] = find(p[a]);
        return p[a];
    }
    bool isSameSet(int a, int b)
    {
        return find(a) == find(b);
    }
    void unionSet(int a, int b)
    {
        if (!isSameSet(a, b))
        {
            int x = find(a);
            int y = find(b);
            if (rank[x] > rank[y])
            {
                p[y] = x;
            }
            else
            {
                p[y] = x;
                if (rank[x] == rank[y])
                    rank[x]++;
            }
        }
    }
};

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string store = "";
    int count;
    getline(cin, store);
    count = stoi(store);
    int count_temp = 0;
    while (count--)
    {
        if (count_temp == 0)
        {

            getline(cin, store);
            count_temp++;
        }
        getline(cin, store);
        int comps = stoi(store);
        UnionFind network = UnionFind(comps);
        int corr = 0, incorr = 0;
        while (getline(cin, store) && store != "")
        {
            store += "\n";
            stringstream ss(store);
            ss >> store;
            string type = store;
            ss >> store;
            int a = stoi(store);
            ss >> store;
            int b = stoi(store);
            if (type[0] == 'c')
            {

                network.unionSet(a - 1, b - 1);
            }
            else
            {
                (network.isSameSet(a - 1, b - 1) == true) ? corr++ : incorr++;
            }
        }
        cout << corr << "," << incorr << "\n";
        if (count != 0)
            cout << "\n";
    }
}