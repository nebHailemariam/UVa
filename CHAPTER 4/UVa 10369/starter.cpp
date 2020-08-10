#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vector<pair<pair<int, int>, double>> EdgeList;
int S, P;

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

bool comp(pair<pair<int, int>, double> a, pair<pair<int, int>, double> b)
{
    return (a.second < b.second) ? true : false;
}

void KruskalsAlgorithm() {

    sort(EdgeList.begin(), EdgeList.end(), comp);
    UnionFind u(P);
    int v = 0;
    int cost = 0;
    int i = 0;
    vector<pair<pair<int, int>, double>> res;

    while (v < P && i < EdgeList.size())
    {
        pair<pair<int, int>, double> front = EdgeList[i];
        if (!u.isSameSet(front.first.first, front.first.second)) //avoiding cycle
        {
            v++;
            res.push_back(front);
            cost += front.second;
            u.unionSet(front.first.first, front.first.second);
        }
        i++;
    }
    cout <<fixed<<setprecision(2)<< res[res.size()-S].second << "\n";
}


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int test_cases;
    cin>>test_cases;

    while (test_cases--) {
        vector<pair<int, int>> points;

        cin>>S>>P;

        int p = P;

        while (p--) {
            int x, y;
            cin>>x>>y;
            points.push_back(pair<int, int>(x, y));
        }
        EdgeList = vector<pair<pair<int, int>, double>>();
        for (int i = 0; i < points.size(); i++) {
            for (int j = i+1; j < points.size(); j++) {
                double dist = sqrt(pow(points[i].first-points[j].first, 2) + pow(points[i].second - points[j].second, 2));
                EdgeList.push_back(pair<pair<int, int>, double>(pair<int, int>(i, j), dist));
            }
        }
        KruskalsAlgorithm();


    }
}