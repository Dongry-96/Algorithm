#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int bfs(int start, vector<vector<int>>& adj_list, vector<bool>& visited)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    int count = 1;

    while (!q.empty())
    {
        int cur = q.front(); q.pop();

        for (int next : adj_list[cur])
        {
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
                ++count;
            }
        }
    }

    return count;
}

int solution(int n, vector<vector<int>> wires)
{
    // 양방향 인접리스트 형태로 저장
    vector<vector<int>> adj_list(n + 1);

    for (const auto& wire : wires)
    {
        adj_list[wire[0]].push_back(wire[1]);
        adj_list[wire[1]].push_back(wire[0]);
    }
    
    // 간선 하나씩 제거해보며 최소 차이 값 계산
    int answer = n;
    for (const auto& wire : wires)
    {
        // 1. 현재 간선 노드 캐싱
        int a = wire[0], b = wire[1];

        // 2. 양방향 간선 제거
        adj_list[a].erase(remove(adj_list[a].begin(), adj_list[a].end(), b), adj_list[a].end());
        adj_list[b].erase(remove(adj_list[b].begin(), adj_list[b].end(), a), adj_list[b].end());

        // 3. 간선 제거 후, 1번 노드와 연결된 노드 개수 반환
        vector<bool>visited(n + 1, false);
        int group_size = bfs(1, adj_list, visited);

        // 4. 두 개로 나눠진 노드의 차이 값이 최소 값이면 갱신
        int diff = abs(n - group_size - group_size);
        answer = min(answer, diff);

        // 5. 현재 끊었던 간선 복구
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    return answer;
}