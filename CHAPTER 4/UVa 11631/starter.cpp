#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> EdgeList;

typedef vector<int> vi;

class UnionFind
{
private:
    vi p, rank, setSize;
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
    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
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
    int numDisjointSets() {
        return numSets;
    }
    int sizeOfSet(int i) {
        return setSize[findSet(i)];
    }
};



bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    if (a.second < b.second)return true;
    return false;
}

int KruskalsAlgorithm(int m) {
    sort(EdgeList.begin(), EdgeList.end(), comp);
    UnionFind u(m);
    int v = 0;
    int i = 0;
    int cost = 0;
    while (v < m && i < EdgeList.size()) {
        pair<pair<int, int>, int> front = EdgeList[i];
        if (!u.isSameSet(front.first.first, front.first.second)) {
            cost += front.second;
            v++;
            u.unionSet(front.first.first, front.first.second);
        }
        i++;
    }
    return cost;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int m, n;
    while (cin>>m>>n && (m != 0 || n != 0)) {
        EdgeList = vector<pair<pair<int, int>, int>>();
        int weight = 0;
        while (n--) {
            int u, v, w;
            cin>>u>>v>>w;
            weight+=w;
            EdgeList.push_back(pair<pair<int, int>, int>(pair<int, int>(u, v), w));
        }
        cout<<weight-KruskalsAlgorithm(m)<<"\n";
    }
}