#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind
{ // OOP style
private:
    vi p, rank, setSize; // remember: vi is vector<int>
    int numSets;

public:
    UnionFind(int N)
    {
        setSize.assign(N, 1);
        numSets = N;
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
            numSets--;
            int x = findSet(i), y = findSet(j);
            // rank is used to keep the tree short
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
    int numDisjointSets() { return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    return (a.second < b.second) ? true : false;
}

int main()
{
    int V = 5;
    UnionFind u(V);
    vector<pair<pair<int, int>, int>> EdgeList;
    EdgeList.push_back(pair<pair<int, int>, int>(pair<int, int>(0, 1), 0));
    EdgeList.push_back(pair<pair<int, int>, int>(pair<int, int>(0, 4), 1));
    EdgeList.push_back(pair<pair<int, int>, int>(pair<int, int>(0, 2), 20));
    EdgeList.push_back(pair<pair<int, int>, int>(pair<int, int>(0, 3), 1));
    EdgeList.push_back(pair<pair<int, int>, int>(pair<int, int>(1, 3), 1));
    EdgeList.push_back(pair<pair<int, int>, int>(pair<int, int>(1, 4), 2));
    EdgeList.push_back(pair<pair<int, int>, int>(pair<int, int>(4, 3), 3));
    EdgeList.push_back(pair<pair<int, int>, int>(pair<int, int>(4, 2), 20));
    EdgeList.push_back(pair<pair<int, int>, int>(pair<int, int>(3, 2), 10));
    sort(EdgeList.begin(), EdgeList.end(), comp);

    int v = 0;
    int cost = 0;
    int i = 0;
    vector<pair<pair<int, int>, int>> res;

    while (v < V && i < EdgeList.size())
    {
        pair<pair<int, int>, int> front = EdgeList[i];
        if (!u.isSameSet(front.first.first, front.first.second)) //avoiding cycle
        {
            v++;
            res.push_back(front);
            cost += front.second;
            u.unionSet(front.first.first, front.first.second);
        }
        i++;
    }
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i].first.first << " - " << res[i].first.second << " = " << res[i].second << "\n";
    }
    cout << "MST cost = " << cost << "\n";
}
