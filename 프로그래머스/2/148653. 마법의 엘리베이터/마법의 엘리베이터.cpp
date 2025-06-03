#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<int> convert_q(int value)
{
    queue<int> result;

    while (value != 0)
    {
        result.push(value % 10);
        value /= 10;
    }

    return result;
}

void calculate_target_q(int& target, queue<int>& q)
{
    target = 10 - target;

    if (q.empty())
    {
        q.push(1);
    }
    else
    {
        q.front() += 1;
    }
}

int solution(int storey) 
{
    queue<int> q = convert_q(storey);

    int answer = 0;

    while (!q.empty())
    {
        int target = q.front(); q.pop();

        if (target > 5)
        {
            calculate_target_q(target, q);
        }
        else if (target == 5)
        {
            int next = q.front();

            if (next >= 5)
            {
                calculate_target_q(target, q);
            }
        }

        answer += target;
    }

    return answer;
}