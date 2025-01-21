#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<int> solution(vector<string> wallpaper) 
{
    vector<int> answer = { INT_MAX,INT_MAX,INT_MIN,INT_MIN };
    
    for (int y = 0; y < wallpaper.size(); ++y)
    {
        for (int x = 0; x < wallpaper[y].size(); ++x)
        {
            if (wallpaper[y][x] == '#')
            {
                if (y < answer[0]) answer[0] = y;
                if (x < answer[1]) answer[1] = x;
                if (y > answer[2]) answer[2] = y;
                if (x > answer[3]) answer[3] = x;
            }
        }
    }

    answer[2]++;
    answer[3]++;

    return answer;
}