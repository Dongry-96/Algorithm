#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> maps)
{
    vector<int> answer;

    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].length(), false));
    int max_y = maps.size();
    int max_x = maps[0].length();
    
    for (int y = 0; y < maps.size(); ++y)
    {
        for (int x = 0; x < maps[0].size(); ++x)
        {
            if (visited[y][x] || maps[y][x] == 'X') continue;

            queue<pair<int, int>> q;
            q.push({ y,x });
            int sum = 0;
            visited[y][x] = true;

            int dir_y[4] = { -1,0,1,0 };
            int dir_x[4] = { 0,1,0,-1 };

            while (!q.empty())
            {
                pair<int, int> cur = q.front(); q.pop();
                sum += maps[cur.first][cur.second] - '0';

                for (int i = 0; i < 4; ++i)
                {
                    int dy = cur.first + dir_y[i];
                    int dx = cur.second + dir_x[i];

                    if (dy < 0 || dy >= max_y || dx < 0 || dx >= max_x 
                        || maps[dy][dx] == 'X' || visited[dy][dx]) continue;

                    visited[dy][dx] = true;
                    q.push({ dy,dx });
                }
            }

            answer.push_back(sum);
        }
    }
    
    if (answer.empty()) return answer = { -1 };

    sort(answer.begin(), answer.end());
        
    return answer;
}