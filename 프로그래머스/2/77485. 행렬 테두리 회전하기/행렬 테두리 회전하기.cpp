#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<vector<int>> map(rows, vector<int>(columns));
    int num = 1;
    for (int y = 0; y < rows; ++y)
    {
        for (int x = 0; x < columns; ++x)
        {
            map[y][x] = num++;
        }
    }
    
    vector<int> answer;
    int direct[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

    int turn = -1;
    while (++turn != queries.size())
    {
        pair<int, int> start({ queries[turn][0] - 1, queries[turn][1] - 1 });
        pair<int, int> end({ queries[turn][2] - 1, queries[turn][3] - 1 });
        
        int part_columns = end.second - start.second + 1;
        int part_rows = end.first - start.first + 1;
        int total_calcnt = part_columns * 2 + (part_rows - 2) * 2;
        int min_value = 21e8;

        int dy = start.first; int dx = start.second + 1;
        int dir_idx = 0;
        int temp = map[start.first][start.second];

        for (int i = 0; i < total_calcnt; ++i)
        {
            swap(temp, map[dy][dx]);

            min_value = min(min_value, temp);

            int next_dy = dy + direct[dir_idx][0];
            int next_dx = dx + direct[dir_idx][1];
            if (next_dy < start.first || next_dy > end.first || next_dx < start.second || next_dx > end.second) dir_idx++;

            dy += direct[dir_idx][0];
            dx += direct[dir_idx][1];
        }

        answer.push_back(min_value);
    }
   
    return answer;
}