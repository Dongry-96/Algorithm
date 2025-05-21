#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int to_minutes(const string& time)
{
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));

    return h * 60 + m;
}

int solution(vector<vector<string>> book_time) 
{
    sort(book_time.begin(), book_time.end());
    
    priority_queue<int, vector<int>, greater<int>> room_end_times;

    for (const auto& time : book_time)
    {
        int start = to_minutes(time[0]);
        int end = to_minutes(time[1]);

        if (!room_end_times.empty() && room_end_times.top() + 10 <= start)
        {
            room_end_times.pop();
        }

        room_end_times.push(end);
    }

    return room_end_times.size();
}