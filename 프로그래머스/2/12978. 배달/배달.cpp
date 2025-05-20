#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void convert_adj_list(vector<vector<pair<int, int>>>& adj_list, const vector<vector<int>>& road)
{
    for (const vector<int>& vec : road)
    {
        adj_list[vec[0]].push_back({ vec[1],vec[2] });
        adj_list[vec[1]].push_back({ vec[0],vec[2] });
    }
}

int dijkstra(const int& k, const vector<vector<pair<int, int>>>& adj_list, const int& N)
{
    vector<int> dist(N + 1, 21e8);
    dist[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({ 0,1 });

    while (!pq.empty())
    {
        auto [cur_cost, s] = pq.top(); pq.pop();
        if (cur_cost > dist[s]) continue;

        for (auto [e, cost] : adj_list[s])
        {
            int next_cost = cur_cost + cost;
            if (next_cost < dist[e])
            {
                dist[e] = next_cost;
                pq.push({ next_cost, e });
            }
        }
    }

    int count = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (dist[i] <= k) count++;
    }

    return count;
}

int solution(int N, vector<vector<int>> road, int K) 
{
    vector<vector<pair<int, int>>> adj_list(N + 1);
    convert_adj_list(adj_list, road);
    
    int answer = dijkstra(K, adj_list, N);

    return answer;
}