#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section)
{
    vector<int> wall(n);
    int cnt = 0;

    for (int i = 0; i < section.size(); ++i)
    {
        wall[section[i] - 1] = 1;
    }

    for (int i = 0; i < wall.size(); ++i)
    {
        if (wall[i] == 1)
        {
            for (int j = 0; j < m; j++)
            {
                if (wall.size() > i + j) wall[i + j] = 0;
            }
            cnt++;
        }
        
    }

    return cnt;
}