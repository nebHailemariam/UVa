#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> EdgeList;
vector<vector<int>> ADJ_LST;
map<pair<int, int>, int> u_to_v;

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

void KruskalsAlgorithm(int m) {
    sort(EdgeList.begin(), EdgeList.end(), comp);
    UnionFind u(m);
    int v = 0;
    int i = 0;
    u_to_v.empty();
    ADJ_LST = vector<vector<int>>(m);
    while (v < m && i < EdgeList.size()) {
        pair<pair<int, int>, int> front = EdgeList[i];
        if (!u.isSameSet(front.first.first, front.first.second)) {
            u_to_v[pair<int, int>(front.first.second, front.first.first)] =  front.second;
            u_to_v[pair<int, int>(front.first.first, front.first.second)] = front.second;
            ADJ_LST[front.first.first].push_back(front.first.second);
            ADJ_LST[front.first.second].push_back(front.first.first);
            v++;
            u.unionSet(front.first.first, front.first.second);

        }
        i++;
    }
}


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int C, S, Q;
    int cases = 1;
    while (cin>>C>>S>>Q && (C != 0 && S != 0 && Q != 0)) {
        EdgeList = vector<pair<pair<int, int>, int>>();

        while (S--) {
            int u, v, w;
            cin>>u>>v>>w;
            u--;
            v--;
            EdgeList.push_back(pair<pair<int, int>, int>(pair<int, int>(u, v), w));
        }
        KruskalsAlgorithm(C);
        if (cases != 1)
            cout<<"\n";

        cout<<"Case #"<<cases++<<"\n";
        while (Q--) {
            int source, dest;
            cin>>source>>dest;
            source--; dest--;
            queue<pair<int, int>> q;
            q.push(pair<int, int>(source, 0));
            vector<bool> visited = vector<bool>(C, false);
            bool found = false;
            int cost = 0;
            visited[source] = true;
            while (q.size() !=0 && !found) {
                pair<int, int> u = q.front();
                q.pop();
                for (int i = 0; i < ADJ_LST[u.first].size();i++) {
                    int v = ADJ_LST[u.first][i];
                    // cout<<u.first+1<<"->"<<v+1<<" : "<<u_to_v[pair<int, int>(u.first, v)]<<"\n";

                    if (v == dest) {
                        cost = max(u_to_v[pair<int, int>(u.first, v)], u.second);
                        found=true;
                        break;
                    }
                    else if (!visited[v]) {
                        visited[v] = true;
                        cost = max(cost, u_to_v[pair<int, int>(u.first, v)]);
                        q.push(pair<int, int>(v, max(u_to_v[pair<int, int>(u.first, v)], u.second)));
                    }

                }
            }
            if (!found)
                cout<<"no path\n";
            else
                cout<<cost<<"\n";
        }
    }
}