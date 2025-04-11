#include <vector>
#include <queue>

using namespace std;

int solution(int x, int y, int n)
{
    queue<pair<int, int>> q;
    vector<bool> visited(y + 1, false);

    q.push({ x, 0 });
    visited[x] = true;

    while (!q.empty())
    {
        auto [cur, cnt] = q.front(); q.pop();

        if (cur == y) return cnt;

        vector<int> nexts = { cur + n, cur * 2, cur * 3 };

        for (int next : nexts)
        {
            if (next <= y && !visited[next])
            {
                visited[next] = true;
                q.push({ next, cnt + 1 });
            }

        }
    }

    return -1;
}