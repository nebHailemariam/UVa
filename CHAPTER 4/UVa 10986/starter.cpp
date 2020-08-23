#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define ii pair<int, int>
vector<vector<ii>> ADJ_LST;
int dist[20010];
int n, m, S, T;

void dijkistra(int source)
{
    for (int i = 0; i < n; i++)
        dist[i] = inf;
    dist[source] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push(ii(0, source));

    ii front;
    int u, d;
    while (!pq.empty())
    {
        front = pq.top();
        pq.pop();
        d = front.first;
        u = front.second;
        if (d > dist[u])
            continue;
        for (int i = 0; i < ADJ_LST[u].size(); i++)
        {
            if (dist[u] + ADJ_LST[u][i].second < dist[ADJ_LST[u][i].first])
            {
                dist[ADJ_LST[u][i].first] = dist[u] + ADJ_LST[u][i].second;
                pq.push(ii(dist[ADJ_LST[u][i].first], ADJ_LST[u][i].first));
            }
        }
    }
}

int main()
{

    int test_cases;
    scanf("%d", &test_cases);
    int cases = 0;
    while (test_cases--)
    {
        scanf("%d%d%d%d", &n, &m, &S, &T);
        ADJ_LST.assign(n, vector<ii>(0));
        int u, v, w;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            ADJ_LST[u].push_back(ii(v, w));
            ADJ_LST[v].push_back(ii(u, w));
        }
        cases++;
        dijkistra(S);
        printf("Case #%d: ", cases);
        (dist[T] == inf) ? printf("unreachable\n") : printf("%d\n", dist[T]);
    }
}