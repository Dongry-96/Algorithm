#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) 
{
    int max_y = park.size() - 1;
    int max_x = park[0].length() - 1;
    int dog_y = -1, dog_x = -1;

    for (int y = 0; y < park.size(); ++y)
    {
        size_t x = park[y].find('S');
        if (x != string::npos)
        {
            dog_y = y;
            dog_x = x;
            break;
        }
    }
    
    for (const string& rout : routes)
    {
        stringstream ss(rout);
        char direction; int cnt;
        ss >> direction >> cnt;

        bool can_move = true;
        int new_y = dog_y;
        int new_x = dog_x;

        for (int step = 1; step <= cnt; ++step)
        {
            switch (direction)
            {
            case 'N':
                new_y = dog_y - step;
                break;
            case 'S':
                new_y = dog_y + step;
                break;
            case 'E':
                new_x = dog_x + step;
                break;
            case 'W':
                new_x = dog_x - step;
                break;
            }
            if (new_y < 0 || new_y > max_y || new_x < 0 || new_x > max_x || park[new_y][new_x] == 'X')
            {
                can_move = false;
                break;
            }
        }

        if (can_move)
        {
            dog_y = new_y;
            dog_x = new_x;
        }
    }

    vector<int> answer = { dog_y, dog_x };

    return answer;
}